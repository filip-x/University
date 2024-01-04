bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                            ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
extern printf
import printf msvcrt.dll
extern scanf
import scanf msvcrt.dll
                          

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
;Read numbers (in base 10) in a loop until the digit '0' is read from the keyboard. Determine and display the smallest number from those that have been read.

    nr db 0; ; i only use byte bcs of the memory, so we can wee better in the memory
    
    screenMsg_nr db "Nr= ",0;
    
    format_nr db "%d",0;
    
    _ dd -1;
    rez db 0;
; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov eax,0;
        mov ebx,0;
        mov bl,127;
        
        for:; for inf loop
        
        
        push dword screenMsg_nr;
        call [printf];
        add esp,4*1;
       
        push dword nr;
        push dword format_nr;
        call [scanf];
        add esp,4*2;

        
        mov al,[nr];
        
        cmp al,0 ; if it's 0 go to final 
        je final
        
       
        cmp al,bl;
        jl schimbare
 
        jmp for
        
        schimbare:
        mov bl,al;
        jmp for
        
        final:
        mov [rez],bl;
        
        ;extra 
        push dword [rez]
        push dword format_nr
        call [printf]
        add esp,4*2;
 
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
