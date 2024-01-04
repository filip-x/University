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

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    ;A file name (defined in data segment) is given. Create a file with the given name, then read words from the keyboard until character '$' is read from the ;keyboard. Write only the words that contain at least one digit to file
    
    file_name db "date.in",0;
    access_mode db "w",0;
    file_descriptor dd -1;
    
    cuvant resb 15;
    screen_msg db "Cuvant= ",0;
    
    format_cuvant db "%s",0;
    format_afisare_fisier db "%s ", 0
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        ;open file
        push dword access_mode;
        push dword file_name;
        call [fopen];
        add esp,4*2;
       
        ;check if file opened correctly
        cmp eax,0;
        je final
        mov [file_descriptor],eax;
       
       
        bucla:; bucla pentru citire de la tastatura cuivinte
            
            push dword screen_msg;
            call [printf];
            add esp,4*1;
           
            push dword cuvant;
            push dword format_cuvant;
            call [scanf];
            add esp,4*2;
            
            mov esi,cuvant;
            verificare:
               mov bl,[esi]
               cmp bl,'0'
               jnae c1
               cmp bl,'9'
               
               ja c1
               
               ;afisare in fisier
               push dword cuvant 
               push dword format_afisare_fisier
               push dword [file_descriptor]
               call [fprintf]
               add esp,4*3;
               jmp bucla
               c1:
            inc esi;
            cmp byte[esi-1],0;
            jne verificare
            
            mov al,'$';
        cmp al,[cuvant]
        jne bucla;
            
        
   
       
       
        ; close file
        cleanup:
        push dword [file_descriptor];
        call [fclose]
        add esp,4;
        
        
        final:
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
