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
    
    ;1 and 30- problems simple exercises & problems add and subs byte
    a db 1
    b db 9
    c db 11
    d db 5
    ;1.)c-(a+d)+(b+d)
    ;11-6+14= 5+14=19
    ;30.)d-(a+b)-(c+c)
    ;5-10-22=-5-22=-27
    
    a_a dw 260
    b_b dw 354
    c_c dw 600
    d_d dw 456
    
    ;1.) (c+b+a)-(d+d) = 302
    ;30.) a-b+(c-d+a) = 310
    
    
    
    

; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov eax,0;
        mov al,[a];
        add al,[b];
        ; we have 1 + 9 = A, I insert the values in al, bcs both of them can be represented om 1 byte(8-bits).
        mov ebx,0;
        mov bl,[c];
        add bl,[d];
        ; we have 11 + 5  = 10, I insert the values in bl, bcs both of them can be represented on 1byte (8-bits)
        ;11=B => B+5= 16 => 10
        mov eax,0;
        mov ebx,0;
        mov ecx,0;
        
        mov al,[a];
        add al,[d];
        mov bl,[b];
        add bl,[d];
        mov cl,[c];
        sub cl,al;
        add cl,bl;
        
        mov eax,0;
        mov ebx,0;
        mov ecx,0;
        
       mov al,[d];
       mov bl,[a];
       add bl,[b];
       mov cl,[c];
       add cl,[c];
       sub al,bl;
       sub al,cl;
       
        mov eax,0;
        mov ebx,0;
        mov ecx,0;
        
        mov ax,[c_c];
        add ax,[b_b];
        add ax,[a_a];
        mov bx,[d_d];
        add bx,[d_d];
        sub ax,bx;
        
        mov eax,0;
        mov ebx,0;
       
       mov ax,[a_a];
       sub ax,[b_b];
       mov bx,[c_c];
       sub bx,[d_d];
       add bx,[a_a];
       add ax,bx;
        
        
        
        
        
        


    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
