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
    a db 1; na=1 bit si atunci pune in db 
    n_a equ 1;
    b db 12; nb=4 biti si atunci punem in db
    n_b equ 4;
    c dw 2001;nc=11 biti si atunci punem in dw 
    n_c equ 11
    ; 1+4+11 = 16 biti => fur k 16 biti 
    k dw 1001_1111_1010_0101b; 16 bits 
    rez dd 0;
   
; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov eax,0;
        mov ebx,0;
        mov ecx,0;
        mov edx,0;
        
        ;a
        mov al,[a]; mov  in al
        ;b
        mov bl,[b];  mov b in bl 
        shl ebx,n_a ; we shift so that we can can the bits that we need 
        or eax,ebx; ; we add the bits from  ebx and  put it in eax 
        ;c
        mov ecx,0;
        mov cx,[c]; mov c in cx bcs c is a word 
        shl ecx,n_a+n_b;we shift bits 
        or eax,ecx; we add ecx into eax with or 
        ;d 
        ;1
        mov ebx,0;
        mov ecx,0;
        mov bl,[a];
        not ebx;
        shl ebx, n_a+n_b+n_c;
        or eax,ebx;
        ;3
        mov ebx,0;
        mov bx,[k];
        mov cx,1;
        f_loop:
            cmp bx,0;
            je end_f
            and cx,bx;
            shr bx,1
        end_f: 
        ror ecx,1;
        or eax,ecx;
            
        
        
        
        
        
        
        
      
        
        
        
        
        
        
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
