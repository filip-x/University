bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
extern scanf
import scanf msvcrt.dll 
extern printf
import printf msvcrt.dll

extern prim
; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...

     nr dd 0; ; 
    screenMsg_nr db "Nr= ",0;
    
    format_nr db "%d",0;
    
    
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        
        mov eax,0;
        mov ebx,0;
        mov ebx,0;
        
        
        for:; for inf loop
       
        push dword screenMsg_nr;
        call [printf];
        add esp,4*1;
       
        push dword nr;
        push dword format_nr;
        call [scanf];
        add esp,4*2;

        
        mov ebx,[nr];punem nr in ebx pentru a merge pe el
        push ebx;
        call prim
 
        
        cmp ebx,0 ;daca e 0 atunci iasa din loop pentru a merge sa afiseze numerele in fisier  
        je final
        
        jmp for
        
        final:
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
