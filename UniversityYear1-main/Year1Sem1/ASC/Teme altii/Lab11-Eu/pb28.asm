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
extern fread
import fread msvcrt.dll
extern fprintf
import fprintf msvcrt.dll
extern scanf
import scanf msvcrt.dll
extern printf 
import printf msvcrt.dll
extern count
; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...



cuvant resb 15;
    screen_msg db "Cuvant= ",0;
    
    format_cuvant db "%s",0;
    format_afisare db "%d ",10 ,0;
; our code starts here
segment code use32 class=code
    
    start:
       
    
      push dword screen_msg;
      call [printf];
      add esp,4*1;
    for_1:
      
           
        push dword cuvant;
        push dword format_cuvant;
        call [scanf];
        add esp,4*2;
        
        mov eax,cuvant;
        push eax;
        call count;
        
    mov dl,'$';
    cmp dl,[cuvant]
    jne for_1;
            
  
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
