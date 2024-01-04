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
    a dw 4
    b dw 5

    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        ;mov ax,a;
        ;cmp ax,5;
        ; it puts the address of a and since a is the first in the memory it has the "address 1000"= and it compares with 5;
        
        ;2
        ;mov ax,[a];
        ;cmp 5,ax;
        ;error
        
        ;3
        ;mov bx,0;
        ;mov al,00011110b;
        ;shr al,2;
        ;adc bx,1;
        ;al=00000111b,bx=2
        
        ;mov ax,5
        ;mov ecx,1
        ;sub ax, 2
        ;sub ecx,2
        ;repeta:
        ;inc ax
        ;Loop repeta
        mov ax,[a]
        mov bx, [b]
        cmp ax, bx
        add ax,bx
        jne sf
            add ax, 1
        sf:

        

        
        
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
