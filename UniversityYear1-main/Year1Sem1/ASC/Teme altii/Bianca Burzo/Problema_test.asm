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
    X dd 442348h
    Y dd 0FC3CDFh
    varXY db 0
    _1 dd 0
    _2 dd 0
    ;punem 0 in memorie sa nu ne afecteze atunci cand facem adunarea 
    
    varRes db 0
    
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov eax, 0
        mov eax, [X]
        mov [varXY], eax
        mov eax, [Y]
        mov [varXY+3], eax
        ;
        mov bl, [varXY]
        mov dx, [varXY+1]
        mov cx, [varXY+3]
        mov ah, [varXY+5]
        ;
        mov [varRes], bl
        add [varRes], cl
        adc [varRes + 1], byte 0
        add [varRes + 1], ch
        adc [varRes + 2], byte 0
        add [varRes + 1], dl
        adc [varRes + 2], byte 0
        add [varRes + 2], dh
        adc [varRes + 3], byte 0
        add [varRes + 2], ah
        adc [varRes + 3], byte 0
        
    
    
    
    
    
    
    
    
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
