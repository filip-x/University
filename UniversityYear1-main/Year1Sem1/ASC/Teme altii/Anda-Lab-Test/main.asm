bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
extern fopen
import fopen msvcrt.dll
extern fprintf
import fprintf msvcrt.dll
extern fclose
import fclose msvcrt.dll

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...

    access_mode db "r",0;
    acces_mode2 db "a",0;
    file_name db "file.txt",0;
    file_name2 db ""file2.txt",0;
    prop resb 100;
    file_descriptor dd -1
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        push dword acces_mode;
        push dword file_name;
        call [fopen];
        add esp,4*2;
        
        mov [file_descriptor],eax;
        
        cmp eax,0;
        je final:
        
        bucla:
            push dword [file_descriptor]
            
        
        
        
        
        final:
       
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
