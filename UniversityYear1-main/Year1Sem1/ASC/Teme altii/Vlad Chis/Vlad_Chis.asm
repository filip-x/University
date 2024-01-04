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
    b db 4Eh
    a dw 0FCD7h
    c dd 0152DCDh
    unu dw 1
    f34 dd 34
; our code starts here
segment code use32 class=code
    start:
    mov eax,0;
    mov ebx,0;
    mov ecx,0;
    mov edx,0;
    
    mov ax,[a]
    mov bl,[b];
    mul bx;
    push dx;
    push ax;
    pop eax;
    mov bx,[a];
    mov cl,[b];
    sub bx,cx;
    add bx,[unu];
    mov cx,0;
    push cx;
    push bx;
    pop ebx;
    mov edx,0
    div ebx;
    sub eax,[c];
    mov ebx,0;
    mov bl,[b];
    add eax,ebx;
    add eax,[f34];
    
    
    
    
    
    
    
        
        
        
        
        
 
        
        
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
