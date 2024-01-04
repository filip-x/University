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
    ;(b / a * 2 + 10) * b - b * 15;
    ; ex. 1: a = 10; b = 40;

    a db 100
    b dw 50
    c db 2
    d db 15
    
    
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov ax,[b]
        mov bl,[a]
        div bl ;doing the division it get to al  
        mul  byte[c] ;the multiplication gets us ax
        add ax, 10
        mul word[b]
        push dx
        push ax
        mov ax,0
        mov dx,0
        mov ax,[b]
        mul word[d]
        pop ebx
        push dx
        push ax
        pop ecx
        sub ebx,ecx
        
        
        
        
        
        
        
        
        
        
        
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
