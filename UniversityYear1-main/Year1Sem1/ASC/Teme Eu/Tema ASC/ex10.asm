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
    A dw 1122h, 2233h, 3344h, 4455h, 5566h, 6677h
    len equ ($-A)/2
    B1 times len db 0 ; 11 22 33 44 55 66
    B2 times len db 0 ; 22 33 44 55 66 77

; our code starts here
segment code use32 class=code
    start:
        ; ...
        ; Given an array A of words, build two arrays of bytes:  
        ; - array B1 contains as elements the higher part of the words from A
        ; - array B2 contains as elements the lower part of the words from A
        mov ESI, A
        mov ECX, len
        push B2
        push B1
        for1:
            lodsw
            pop EDI ; POP B1
            mov [EDI], AH ; Move higher part of the word to B1
            mov EBX, EDI ; PUT B1 IN EBX
            pop EDI ; POP B2
            mov [EDI], AL ; Move lower part of the word to B2
            inc EDI ; Moving to the next element of B2
            inc EBX ; Moving to the next element of B1
            push EDI ; PUSH B2
            push EBX ; PUSH B1
            loop for1 ; REPEAT LEN TIMES (ECX = ECX - 1 after every iteration)

        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
