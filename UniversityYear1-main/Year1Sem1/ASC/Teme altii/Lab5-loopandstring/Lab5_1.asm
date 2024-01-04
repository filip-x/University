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

    ;Given a byte string S of length l, obtain the string D of length l-1 as D(i) = S(i) * S(i+1) (each element of D is the product of two consecutive elements of S)
    ;S: 1, 2, 3,4
    ;D: 2, 6, 12
    
    s db 1,2,3,4;
    len_s equ $-s;len of s 
    
    d times len_s-1 db 0; we made d (the string where to put)
    len__d equ $-s-1;len of d
    
    
    
    
    
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov esi,s; first element of s 
        mov ecx,len_s; the len of s 
        mov edi,d; first element of d 
        
        for_loop1:;it works with or without cmp but it's for me
            cmp ecx,1;
            je final
                mov al,[esi];
                imul byte[esi+1];
                mov byte[edi],al;
                inc esi;
                inc edi;
                
                
                
            ;mai trebuie caz cand e la final de sir
        
        loop for_loop1
        final:
        
        
        
        
        
        
        
        
        
        
    
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
