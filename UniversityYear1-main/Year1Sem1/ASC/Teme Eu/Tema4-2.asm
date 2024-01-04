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
    a dw 38187
    b dw 0
    c dd 0
    n db 0
; our code starts here
segment code use32 class=code
    start:
        ; ...
        ; Creating n...
        mov al, 111b
        and al, byte [a]
        mov [n], al
        ; --
        ; Adding bits 2-9 of B to bits 16-23 of C
        mov ebx, 0
        mov bx, [a]
        mov cl, [n]
        ror bx, cl
        mov [b], bx
        and bx, 1111111100b
        shl ebx, 14
        mov ecx, 0FF0000h
        and ecx, ebx
        ; Adding bits 7-14 of A to bits 24-31 of C
        or ecx, 0FF000000h
        mov ebx, 0
        mov bx, [a]
        and bx,  7F80h
        shl ebx, 17
        or ebx, 00FFFFFFh
        and ecx, ebx
        or ecx, 0FFh
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program