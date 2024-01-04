bits 32 

extern fopen
import fopen msvcrt.dll
extern fclose
import fclose msvcrt.dll
extern fread
import fread msvcrt.dll
extern fread
import fread msvcrt.dll
extern fprintf
import fprintf msvcrt.dll
extern scanf
import scanf msvcrt.dll
extern printf 
import printf msvcrt.dll

                          
segment data use32 class=data
    ; ...
    file_name db "numere.txt",0
    access_mode db "w",0;
    file_descriptor dd -1;
    format_afisare_fisier db "%x ", 0
    
segment code use32 public code
global afisare_fisier
global get_new_min

    
    get_new_min:
        mov ecx, [esp + 8];
        mov ebx, [esp + 4]
        cmp ecx, ebx
        jng not_min
        mov eax, ebx
        jmp end_get_new_min
        not_min:
        mov eax, ecx
        end_get_new_min:
        ret 8
    
    afisare_fisier:
        
        push dword access_mode;
        push dword file_name;
        call [fopen];
        add esp,4*2;
        
        cmp eax,0;
        je final
        mov [file_descriptor],eax;
       
        mov edx, [esp + 4]
        push edx
        push dword format_afisare_fisier;
        push dword [file_descriptor]
        call [fprintf];
        add esp,4*3;
           

        final:
        push dword [file_descriptor];
        call [fclose]
        add esp,4;
        
        ret 4;
        



        
