bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
extern printf
import printf msvcrt.dll
extern fopen
import fopen msvcrt.dll
extern fclose
import fclose msvcrt.dll
extern fscanf
import fscanf msvcrt.dll


; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...

    
    
    file_name db "numere.txt",0;
    access_mode db "r",0;
    
    file_descriptor dd -1;
    
    buffer resd 10000; maxim 10000 de numere 
    
    
    _ dd -1;
    
    
    d dd 0;sir final
    format_nr db "%d",0;deciaml
    format_nr_afisare db "%d ",0
    
    doi dd 2
    
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
        
        mov esi,buffer; elem din fisier in esi;
        
        bucla:
            ; 
            push dword d; variabila_tempo
            push dword format_nr
            push dword [file_descriptor]
            call [fscanf]
            add esp,4*3
           
            cmp eax,-1; 
            je cleanup
            
            mov eax,[d]
            imul dword [doi]
            mov [esi],eax;
            
            add esi,4;
   
          
        jmp bucla;
        

        ;close file
        cleanup:
        push dword [file_descriptor];
        call [fclose]
        add esp,4;    
            
        bucla2:
        ;afisre pe ecran
        sub esi,4
        push dword [esi]
        push dword format_nr_afisare
        call [printf]
        add esp,4*2;
        
        cmp esi,buffer
        jne bucla2
        
        
       
        
       final:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
