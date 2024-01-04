bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    s DB 01011100b, 10001001b, 11100101b 
    len equ $-s
    mirror times len db 0
; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov ESI, s + len - 1
        mov EDI, mirror
        mov ECX, len
        
        for1:
            std ; We make it so ESI decreases
            lodsb ; Load in AL and decrease ESI
            push ECX ; We need ECX for the mirroring
            ; mirror starts here
            mov BL,byte 0
            mov ECX, 8
            ; We mirror the number by putting the least significant bit into CF and then adding it to BL and shifting it to make space. 
            ; In the end we get the mirrored byte
            for2:
                shl BL, 1
                shr AL, 1
                adc BL, 0
                loop for2 ; repeats 8 times, based on ecx
            mov AL, BL
            ; mirror ends above
            ; we need the position we were left at
            pop ECX
            cld ; we set DF to 0 so EDI increases
            stosb ; we move from AL to the mirror string
            loop for1 ; we repeat len times (based on ECX)
            
            
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
