bits 32 


global start        

extern exit
import scanf msvcrt.dll
import printf msvcrt.dll           
import exit msvcrt.dll  ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
import scanf msvcrt.dll
import printf msvcrt.dll
import fscanf msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fprintf msvcrt.dll
extern scanf, printf, fscanf, fopen, fclose, fprintf, copy





segment data use32 class=data

    afisare1 db "Introduceti nr : ", 0
    afisare2 db "Introduceti_propozitie: ", 0
    format_citire1 db "%d", 0
    format_citire2 db "%s%c", 0
    n dd 0
    cc db 0
    cuvant resb 10
    i db 1
    j db 1
    propozitie resb 100
    
    
      
    
    
    
segment code use32 class=code
    start:
    
    ; Citire numar n
        push dword afisare1
        call [printf]
        add esp, 4
        ; ..
        push dword n
        push dword format_citire1
        call [scanf]
        add esp, 4 * 2
    ;citire propozitie
    mov ecx,[n]
    mov edi, propozitie
    repeta:
        push ecx
        push dword afisare2
        call [printf]
        add esp, 4
        mov byte [j], 1
        repeta2:
            push dword cc
            push dword cuvant
            push dword format_citire2
            call [scanf]
            add esp, 4 * 3
            mov dl, [i]
            cmp dl, [j]
            jne sari
            push edi
            push cuvant
            call copy
            mov edi, eax
            sari:
            add byte [j], 1
            cmp byte [cc], 10
            jne repeta2
        
        ;push dword propozitie
        ;call indice
        pop ecx
        add byte [i], 1
        loop repeta

        push dword propozitie
        call [printf]
        
        push    dword 0      
        call    [exit]       
        