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
    ;(a+d+d)-c+(b+b)= (1+4+4)-3+(2+2)=9-3+4=11=B    9-3+254= 260  fe =
    a db 1
    b dw 2
    c dd 3 
    d dq 4 

; our code starts here
segment code use32 class=code
    start:
        ; ...
       mov edx,[d]  ;here we put the first part of the dq
       mov ecx, [d+4] ;here we put the second part of the dq
       mov eax, 0 ;we make eax all 0 
       mov al, [a] ; we move a into al 
       add edx, edx ; we add d+d 
       adc ecx, ecx ;same here
       add edx,eax ; we add the dd with a 
       adc ecx, 0   ;if we have a carry we  put it in  
       mov ebx, 0
       mov eax, [c] ; we put c into eax
       sub edx, eax ; we substract c from d ( c is in eax)
       sbb ecx, 0 ; if there is a carry we will put it 
       mov ebx, 0 ; after we substract c in ebx we make it 0 so that we can add b+be
       mov bx, [b] ; we move b into bx 
       add bx,bx  ; we add b to b 
       add edx, ebx ;we add d to b
       adc ecx, 0   ;we add the carry 
       
       
       
       
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
