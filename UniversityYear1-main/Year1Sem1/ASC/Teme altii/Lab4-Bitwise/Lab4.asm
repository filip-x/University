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
    
    a dw 1000_1111_1010_1111b;memorie AF 8F
    b dw 1010_1000_1111_0100b;memorie F4 A8
    c dd 0;memorie A0 EB AF 8F
    

    
    ;3Given the words A and B, compute the doubleword C as follows:
    ;the bits 0-2 of C are the same as the bits 12-14 of A
    ;the bits 3-8 of C are the same as the bits 0-5 of B
    ;the bits 9-15 of C are the same as the bits 3-9 of A
    ;the bits 16-31 of C are the same as the bits of A
    
    
    ;32Given the words A, B si C, obtain the byte D as the sum of the integers represented by:
    ;the bits 0-4 of A
    ;the bits 5-9 of B
    ;The byte E is the integer represented by the bits 10-14 of C. Obtain the byte F by computing the subtraction D-E.
    
    a_a dw 1000_1111_1010_1111b;memorie AF 8F
    b_b dw 1010_1000_1111_0100b;memorie F4 A8
    c_c dw 1110_0101_0010_1101b;memorie 2d E5
    d_d db 0;16
    e_e db 0;19
    f_f db 0;FD
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        ;3
        mov eax,0;
        mov ax,[a];
        shr ax,12;
        and ax,0111b;
        mov dword[c], eax;
        ;the bits 0-2 of C are the same as the bits 12-14 of A
        
        mov eax,0;
        mov ax,[b];
        and ax,0x3F;
        shl ax,3;
        or dword[c],eax;
        ;the bits 3-8 of C are the same as the bits 0-5 of B
        
        mov eax,0;
        mov ax,[a];
        shr ax,3;
        and ax,0x7F;
        shl ax,9;
        or dword[c],eax;
         ;the bits 9-15 of C are the same as the bits 3-9 of A
         
        mov eax,0;
        mov ax,[a];
        shl eax,16;
        or dword[c],eax;
        
        ;==============================================================
        ;32
        mov eax,0;
        mov ax,[a_a];
        and ax,0xF;
        ;the bits 0-4 of A
        mov ebx,0;
        mov bx,[b_b];
        shr bx,5;
        and bx,0x1F;
        ;the bits 5-9 of B 
        ;F+7==16
        add al,bl;
        mov byte[d_d],al;
        
        
        
        
        mov eax,0;
        mov ax,[c_c];
        shr ax,10;
        and ax,0x1F;
        mov byte[e_e],al;
        ;The byte E is the integer represented by the bits 10-14 of C.== 19
        
        mov eax,0;
        mov al,[d_d];
        sub al,[e_e];
        mov byte[f_f],al;
        ;Obtain the byte F by computing the subtraction D-E.==== 16-19 = FD
        
        
        
        
        
        
        
        
        
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
