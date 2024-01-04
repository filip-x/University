bits 32 


global start        


extern exit               
import exit msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fread msvcrt.dll; iau tot
import scanf msvcrt.dll; ia pana la spatiu
extern scanf
extern printf
extern fopen
extern fclose
extern fread
extern scanf
; d= base 10, c = char, s = sir de caractere, x= nr in base 16
; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions


segment data use32 class=data
format_afisare_consola db " %d ,%s ",10,0
file_acces db "r",0
file_descriptor dd 0  
fisier_nume db "problema_decodare_fisier.txt",0
lenf equ 100
text times (lenf+1) db 0
segment code use32 class=code
    start:
    
    push dword file_acces
    push dword fisier_nume
    call [fopen]
    add esp,4*2
    
    mov [file_descriptor],eax
    cmp eax,0
    je final
    
    push dword [file_descriptor]
    push dword lenf
    push dword 1 
    push dword text
    call [fread]
    add esp,4*4
    pusha
    push dword text ; the text itself
    push dword eax; numbers of caractere citite
    push dword format_afisare_consola
    call [printf]
    add esp,4*3
    popa
    
    mov esi,text
    mov ecx,0
    repeta1:
        cmp byte[esi]," "
        je peste_restul
        ;spatiu
        
        cmp byte[esi],"a"
        je schimb_y
        jmp peste_y
        schimb_y:
        mov byte[esi],"y"
        jmp peste_restul
        peste_y
        
        cmp byte[esi],"b"
        je schimb_z
        jmp peste_z
        schimb_z:
        mov byte[esi],"z"
        jmp peste_restul
        peste_z
        
        cmp byte[esi],"A"
        je schimb_Y
        jmp peste_Y
        schimb_Y:
        mov byte[esi],"Y"
        jmp peste_restul
        peste_Y:
        
        cmp byte[esi],"B"
        je schimb_Z
        jmp peste_Z
        schimb_Z:
        mov byte[esi],"Z"
        jmp peste_restul
        peste_Z:


        ;celelate cazuri
        sub byte[esi],2
        peste_restul:
        
        
        
        inc esi
        inc ecx
    cmp ecx,eax
    jne repeta1
    
    push dword text ; the text itself
    push dword eax; numbers of caractere citite
    push dword format_afisare_consola
    call [printf]
    add esp,4*3
    
    
    
    
    
       
    
        final:
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
