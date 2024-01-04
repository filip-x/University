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
    ; 10
    ;Two character strings S1 and S2 are given. Obtain the string D by concatenating the elements of S2 in reverse order and the elements found on even positions in S1
    ;D: '5', '4', 'a', '2','b', '6', '8'
    s2 db 'a','4','5'
    lens2 equ $-s2
    s1 db '+', '2', '2', 'b', '8', '6', 'X', '8'
    lens1 equ $-s1
    D times lens1+lens2 db 0
; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov ecx,lens2 ; with exc we navigate through s2 the array starts from 0 up to 2 ( len is 3 tho)
        mov edi, 0 ; the index of D
        start_loop:
        
            mov al,[s2 + ecx-1]
            mov [D + edi], al 
            
            add edi,1
        loop start_loop ;can't use loop when ecx starts with 0 
        mov ecx, 1
        
            start_loop2:
                mov bl,[s1 + ecx]
                mov [D +edi], bl
                add edi,1
                add ecx,2
                cmp ecx,lens1
                jae end ; jump if above
                jmp start_loop2
                
                end:
                
        
        
           
    
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
