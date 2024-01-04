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
    ;(a*a+b+x)/(b+b)+c*c; a-word; b-byte; c-doubleword; x-qword signed
    a dw 5 
    b db -2 
    c dd 3
    x dq 4 
    bb dw 0
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov dx, 0
        mov ax,[a] 
        imul word[a] ;we multiply a by a (signed)
        mov cx,ax ;
        mov al,[b]
        cbw 
        mov bx,ax
        mov ax,cx
        add ax,bx
        adc dx,0
        push dx 
        push ax 
        pop eax 
        cdq
        mov ecx,[x]
        mov ebx,[x+4]
        add eax,ecx
        adc edx,ebx
        mov ebx,0; este doar vizual
        mov ecx,0; este doar vizual
        mov ebx,eax
        mov ecx,edx
        mov al,[b]
        cbw
        add ax,ax 
        cwde
        push eax 
        mov eax,[c]
        imul eax
        pop word[bb]; adica b+b
        push eax
        push edx
        mov ax,word[bb]
        cwde
        mov edx,ecx
        mov ecx,eax 
        mov eax,ebx
        idiv ecx ; aici imi da gresit 
        pop ebx
        pop ecx 
        cdq 
        add eax,ecx
        adc edx,ebx
        
        
        
        
        
        
        
        
        
        
       
        
        
        
        
        
        
        
        
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
