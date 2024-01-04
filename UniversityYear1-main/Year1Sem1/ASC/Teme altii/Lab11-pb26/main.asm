bits 32 


global start        


extern exit               
import exit msvcrt.dll  
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

extern afisare_fisier
extern get_new_min

segment data use32 class=data
    
    nr dd 0;
    screen_msg_nr db "NR= ", 0;
    format_nr db "%d", 0;
    
segment code use32 class=code
    start:
        
        mov eax,0;
        
        push dword screen_msg_nr;
        call [printf];
        add esp,4*1;
           
        push dword nr;
        push dword format_nr;
        call [scanf];
        add esp,4*2;
        
        mov edx,[nr]; in edx vom retine minimul
        for_1: ;  jump-ul se termina atunci cand utilizatorul introduce valoarea 0 de la tastatura
            push edx
            push dword screen_msg_nr;
            call [printf];
            add esp,4*1;
           
            push dword nr;
            push dword format_nr;
            call [scanf];
            add esp,4*2;
            pop edx
            mov eax,[nr]
            cmp eax,0;
            je final_for
            
            ;preluam numarul in eax pentru al transmite ca parametru, ca functia afisare_fisier sa preia numarul 
            push edx
            push eax;
            call get_new_min
            mov edx, eax
        jmp for_1
        final_for:
        push edx
        call afisare_fisier
        
        push    dword 0      
        call    [exit]       
