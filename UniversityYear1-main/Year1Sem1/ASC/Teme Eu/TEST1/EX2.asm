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
    ;(a*d+e)/[c+h/(c-b)]=16/(4+9/4-3)=16/13=1
    ;a,b,c,d-byte, e,f,g,h-word
    a db 2
    b db 3
    c db 4 
    d db 5
    e dw 6 
    f dw 7 
    g dw 8
    h dw 9
; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov eax,0
        mov al,[a]; trebuie  byte aici
        mul  byte[d]
        add ax, word[e]
        push 0
        push ax
        mov ax,0
        mov al, byte[c]; trebuie byte aici ?? 
        add ax,word[h]
        mov bx,0
        mov bl,[c]
        sub bl,byte[b]
        mov dx,0
        div bx
        mov ebx,0
        pop ecx
        push dx
        push ax
        mov eax,0
        pop ebx
        mov eax,ecx
        mov edx,0
        div ebx
        
        
        
        
        
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
