bits 32

global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    ; ...
    sir_1 dw 1, 5, -5, 10, 11, 13
    len equ ($ - sir_1) / 2
    sir_2 dw 10, 20, 5, 7, -11, 20
    dd -1
    sir_3 resw len
    

segment code use32 class=code
    start:
        ; ...
        mov esi, 0
        mov edi, sir_3
        cld
        mov ecx, len
        for_1:
            mov ax, [sir_1 + esi]
            mov bx, [sir_2 + esi]
            cmp ax, bx
            jna else
            jng else
            if_1:
                stosw
                jmp endif
            else:
                cmp bx, ax
                jna else_2
                jng else_2
                if_2:
                    mov ax, bx
                    stosw
                    jmp endif_2
                else_2:
                    mov dx, 0
                    imul bx
                    stosw
                endif_2:
            endif:
            inc esi
            inc esi
            loop for_1

        ; exit(0)
        push dword 0
        call [exit]