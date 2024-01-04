bits 32 
segment code use32 public code
global numere_prime

import printf msvcrt.dll
import scanf msvcrt.dll
extern printf
extern scanf

segment data2 use32 class=data

    d dw 3
       
numere_prime:
    ; afisare numere prime si verificare 
    mov cx,[esp+4]
    
    cmp cx,1
    je return_false
    cmp cx,2
    je return_true
    
    mov bx,2
    mov dx,0
    mov ax,cx
    div bx
    cmp dx,0
    je return_false
    
    mov bx,ax ; aici avem deja jumatatea de numar
    
    while:
    ;conditia ca sa iasa din while
        mov ax,cx
        push bx
        mov bx,[d]
        div bx
        pop bx
        cmp dx,0
        je return_false
        inc word[d]
        inc word[d]
        cmp [d],bx
        jnae while 
    return_true:
        mov eax,1
        jmp final
    return_false:
        mov eax,0
    final:
    ret 4
    
    
