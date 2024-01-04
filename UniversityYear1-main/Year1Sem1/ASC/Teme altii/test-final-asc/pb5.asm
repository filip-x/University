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
    
; our code starts here
segment code use32 class=code
    verif_sir:
        mov ebx, [esp + 4]
        mov esi, [esp + 8]
        repeta_vs:
            cmp [esi], bl
            je e_vs
            inc esi
            cmp byte [esi], 0
            jne repeta_vs
        jmp nu_e_vs
        e_vs:
        mov eax, 0
        jmp final_vs
        nu_e_vs:
        mov eax, -1
        final_vs:
        ret 4
    start:
        ; ...
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
