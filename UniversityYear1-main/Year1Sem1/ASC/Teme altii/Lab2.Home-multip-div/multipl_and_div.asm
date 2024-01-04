bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...

    
    a db 5
    b db 11
    c db 8
    d dw 102
    ;1.) ((a+b-c)*2 + d-5)*d = (16-8)*2+97)*102= (16+97)*102=11.526
    ;30.) [(a-b)*5+d]-2*c =  = (-6*5+102)-2*8= 72-16=56 
    doi db 2
    cinci db 5
    
    ;LAST PROBLEMS
    
    a_a db 5
    b_b db 7
    c_c db 10
    d_d db 3
    e_e dw 102
    f_f dw 302
    g_g dw 402
    h_h dw 320
    ;1. ((a-b)*4)/c = -8/10= 0 with rest -8
    ;30.) 100/(e+h-3*a) = 100/(102+320-3*5)= 100/(422-15)=100/407= 0 and rest is 100
    patru db 4
    trei db 3
    hund dw 100
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov eax,0;
        mov ebx,0;
        mov ecx,0;
        mov edx,0;
        
        mov al,[a];
        add al,[b];
        sub al,[c];
        mul byte [doi];
        add ax,[d];
        sub ax,5;
        mul word [d];
        
        mov eax,0;
        mov ebx,0;
        mov ecx,0;
        mov edx,0;
        
        mov al,[a];
        sub al,[b];
        imul byte [cinci];
        add ax,[d];
        mov bx,ax;
        mov ax,0;
        mov al,2;
        mul byte[c];
        sub bx,ax;
        
        ;##################
        
        mov eax,0;
        mov ebx,0;
        mov ecx,0;
        mov edx,0;
        
        mov al,[a_a];
        sub al,[b_b];
        imul byte [patru];
        idiv byte [c_c];
        ; the result is 0 with rest -8 =>  in ah is -8 bcs of the rest and in al is 0
        
        mov eax,0;
        mov ebx,0;
        mov ecx,0;
        mov edx,0;
        
        mov al,[a];
        mul byte [trei];
        mov bx,[e_e];
        add bx,[h_h];
        sub bx,ax;
        mov ax,0;
        mov ax,[hund]
        div bx;
        ; the result is stored in ax dx, ax=0 bcs 100/407 is 0 and the rest is 100 so it is stored in dx
        
        
        
        
        
        
        
        
        
        
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
