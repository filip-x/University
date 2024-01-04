bits 32 


global start        


extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    
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
                        

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    file_acces db "r",0
    file_acces2 db "w",0
    file_descriptor dd 0
    file_descriptor2 dd 0
    fisier_nume db "problema_fisier_invers.txt",0
    fisier_print db "print_fisier.txt",0
    len equ 100 
    sirul resb 100
; our code starts here
segment code use32 class=code
    start:
        push dword file_acces
        push dword fisier_nume
        call [fopen]
        add esp,4*2
        
        mov [file_descriptor],eax
        cmp eax,0
        je final
        
        push dword file_acces2
        push dword fisier_print
        call [fopen]
        add esp,4*2
        
        mov [file_descriptor2],eax
        cmp eax,0
        je final2
        
        push  dword [file_descriptor]
        push  dword len
        push  dword 1
        push  dword sirul
        call  [fread]
        add esp,4*4
        
        mov ecx,eax
        mov esi,sirul
        repeta:
            mov ebx,0
            mov bl,[esi]
            push ebx
            inc esi
            loop repeta
        mov ecx,eax
        mov esi,sirul
        repeta2:
            pop ebx
            mov [esi],bl
            inc esi
            loop repeta2
            
        push dword [file_descriptor2]
        push dword len
        push dword 1
        push dword sirul
        call [fwrite]
        add esp,4*4
        
        
        
        
       
        
        
        
        
        
        
        
        
     
        
        final:
        final2:
        
        
        
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
