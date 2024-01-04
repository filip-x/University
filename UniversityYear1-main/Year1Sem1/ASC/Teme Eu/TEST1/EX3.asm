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
    ; a - doubleword; b, d - byte; c - word; e - qword
    ; a + b / c - d * 2 - e =1+10/3-4*2-5=1+3-8-5=-9
    a dd 1 
    b db 10 
    c dw 3 
    d db 4 
    e dq 5 
    f db 2 
; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov al, byte[b]
        cbw
        cwd
        idiv word[c]
        push 0
        push ax 
        mov edx,0
        pop eax
        add eax,dword[a]
        mov ebx,eax ;prima jumatate este salvata in ebx 
        mov al,byte[d]
        cbw
        imul byte[f]
        cwde
        mov ecx,eax; prima spatele a qword
        mov eax,ebx ; in eax avem acum pe ebx si il facem q word
        sub eax,ecx
        cdq
        sub eax,dword[e]
        sbb edx,dword[e+4]
        
        
        
        
        
        
        
        
        
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
