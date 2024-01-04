bits 32 
segment code use32 public code
global copy

import printf msvcrt.dll
import scanf msvcrt.dll
extern printf
extern scanf

       
copy:
    mov edx, [esp + 4]
    mov ebx, [esp + 8]
    mov esi, edx
    mov edi, ebx
    .repeta:
        movsb
        cmp byte [esi], 0
        jne .repeta
    mov byte [edi], " "
    inc edi
    mov eax, edi
    ret 8
    
    
    
    
    
    
            