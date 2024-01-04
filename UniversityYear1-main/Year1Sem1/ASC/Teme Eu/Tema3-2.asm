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
    ;(a + b + c) - (d + d) + (b + c)= 6 - 8 + 5 = 3  
    ;(2^6 + 2^14 + 2^30) - (2^28 + 2^28) + (2^14 + 2^30) =
    ;(64 + 16384 + 1073741824) - (268435456 + 268435456) + (16384 + 1073741824) =
    ; 1073758272 - 536870912 + 1073758208 =
    ; 1610645568 = 60008040 (16)
    a db 64
    b dw 16384
    c dd 1073741824
    d dq 268435456
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov ax, 0
        mov al,[a]
        mov bx,[b]
        add ax,bx
        mov ecx, [c]
        mov dx,ax
        mov eax, dword 0
        mov ax,dx
        add eax, ecx
        mov edx ,[d]
        mov ebx ,dword 0
        mov ecx, dword 0
        add edx,edx
        adc ebx,ebx
        sub eax,edx ;here we insert the value after we do the division between a+b+c and d+d (aici punem valoare dupa ce am facut despartirea dintre a+b+c si d+d)
        sbb ecx,ebx ; punem carry si adunam cealalta parte a dq 
        mov edx, dword 0
        mov ebx, dword 0 
        mov bx,[b]
        mov edx,[c]
        add edx,ebx
        add eax,edx
        adc ecx, 0
        
       
         
        
        
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
