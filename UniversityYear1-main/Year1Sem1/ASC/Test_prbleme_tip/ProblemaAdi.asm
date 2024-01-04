bits 32 


global start        


extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fscanf msvcrt.dll
import fwrite msvcrt.dll
import fread msvcrt.dll
extern scanf
extern printf 
extern fopen
extern fclose
extern fscanf
extern fwrite
extern fread
                    
                    

segment data use32 class=data
    format_descriptor dd 0
    format_acces db "r",0
    format_nume db "fisier_prob_adi.txt",0
    format_afisare db "%s",0
    cuvand resb 10
    citeste_nr db "Citeste un nr: ",0
    format_nr db "%d",0
    nr dd 0
    

segment code use32 class=code
    start:
        
        push  dword format_acces
        push  dword format_nume
        call [fopen]
        add esp,4*2
        
        mov [format_descriptor],eax
        cmp eax,0
        je final
        
        push dword cuvand
        push dword format_afisare
        push dword[format_descriptor]
        call [fscanf]
        add esp,4*3
        
        push dword citeste_nr
        call [printf]
        add esp,4*1
        
        push  dword nr 
        push  dword format_nr
        call [scanf]
        add esp,4*2
        
        mov ecx ,0
        repete:
        mov edx,0
        mov eax,ecx
        div dword[nr]
        cmp edx,0
        jne jump_over_print
        mov ebx,0
        pusha
        push dword cuvand
        push dword format_afisare
        call [printf]
        add esp,4*2
        popa
        inc ecx
        jmp final2
        
        jump_over_print:
        inc ecx
        
        final2:
        push ecx
        push dword cuvand
        push dword format_afisare
        push dword[format_descriptor]
        call [fscanf]
        add esp,4*3
        pop ecx
        
        cmp eax,-1
        jne repete
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    
        final:
        
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
