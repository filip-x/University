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
    ;c+(a*a-b+7)/(2+a), a-byte; b-doubleword; c-qword - unsigned 
    ;12006 rest A
    ;a*b-(100-c)/(b*b)+e+x; a-word; b,c-byte; e-doubleword; x-qword -signed
    ;350-1+70+250=349+70+250= 320+349= 669 rest 43
    ;rest 43
    a db 10;
    b dd 25;
    c dq 12000;
    
    doi db 2;
    sapte dd 7;
    
    
    a_a dw 50 ;
    b_b db 7;
    c_c db 8;
    e_e dd 70;
    x_x dq 250;
    
    hundo db 100;
; our code starts here
segment code use32 class=code
    start:
        ; 
        
        
        mov eax,0;
        mov ebx,0;
        mov ecx,0;
        mov edx,0;
        
        mov al,[a];
        mul byte[a];
        sub eax,[b];
        add eax,[sapte];
     
        
        mov bl,[a];
        add bl,[doi];
        
        div ebx;
        
        add eax,[c];
        add edx,[c+4];
        
        ;------------------------------------------------------
        ;a*b-(100-c)/(b*b)+e+x; a-word; b,c-byte; e-doubleword; x-qword -signed
        
        mov eax,0;
        mov ebx,0;
        mov ecx,0;
        mov edx,0;
        
        mov bl,[hundo]
        sub bl,[c_c];
        sbb bh,0;
        
        
        mov al,[b_b];
        imul byte [b_b];
        mov cx,ax;
        mov ax,bx;
        cwd
        idiv cx;
        
        push eax; 
        push edx;rest
        mov eax,0;
        mov al,[b_b];
        cbw
        imul word [a_a];
        
        pop ebx;rest
        pop ecx;
        push dx;
        push ax;
        pop eax;
        
        mov edx,0;
        sub eax,ecx;result until now
        sbb edx,0;
        add eax,[e_e];
        adc edx,0;
        add eax,[x_x];
        adc edx,[x_x+4];
        
        
        
        
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
