bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

extern fopen
import fopen msvcrt.dll
extern fclose
import fclose msvcrt.dll
extern fread
import fread msvcrt.dll
extern printf
import printf msvcrt.dll
; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    ;11
    ;A text file is given. Read the content of the file, count the number of vowels and display the result on the screen. The name of text file is defined in the ;data segment.
    
    file_name db "date.in",0;
    access_mode db "r",0;
    
    file_descriptor dd -1;
    nr_char_read_from_file dd 0;
    len equ 100
    buffer resb len;
    
    vocale db "aeiou",0;
    len_sir_voclae equ $-vocale-1; bcs it takes 0 too and it will be 6 not 5 
    _ dd -1;
    
    nr_total_de_vocale dd 0;
    
    format_nr db "%d",0
    
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
       
       
        bucla:
            ; read from file 100 char
            push dword [file_descriptor]
            push dword len
            push dword 1;
            push dword buffer;
            call [fread]
            add esp,4*4
           
            cmp eax,0; if eax is 0 then we are at the end of the file
            je cleanup
           
            mov [nr_char_read_from_file],eax; nr of chars read from file
           
            mov ecx,[nr_char_read_from_file]; 
            mov esi,buffer; elem din fisier in esi;
          
           
            for_1:; initial array
                mov edi,vocale; elem din vocale in edi;
                
                push ecx;
                mov ecx,len_sir_voclae;
                for_2:; we go on the vocale array and see if we get a match 
                    mov al,[esi];
                    cmp al,[edi]
                    je vocala
                    
                    inc edi;
                loop for_2
            pop ecx;
            inc esi;daca nu gasete vocala merge mai departe 
            loop for_1
    
        jmp bucla;
            
        
   
        ;daca ii vocala
        vocala:
        inc dword [nr_total_de_vocale];
        inc esi; pentru ca nu mai ajunge la final in for_1
        pop ecx; aducem inapoi ecx sirului mare 
        dec ecx; pentru ca nu mai ajunge la final in for_1
        jmp for_1;
        
        ; close file
        cleanup:
        push dword [file_descriptor];
        call [fclose]
        add esp,4;
        
        
        ;afisre pe ecran
        push dword [nr_total_de_vocale]
        push dword format_nr
        call [printf]
        add esp,4*2;
        
        final:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
