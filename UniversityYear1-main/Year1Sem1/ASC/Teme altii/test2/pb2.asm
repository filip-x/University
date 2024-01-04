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
    
    sir_surs dd 4,8,12,16,20,24,28,32,36;
    len_sir equ ($-sir_surs)/4;
    _f dd -1
    max1 dd 0;
    
    max2 dd 0;
    _f2 dd -1
    v1 db 0;
    v2 db 0;
    var_16 dd 16;

; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov esi,sir_surs;
        mov ecx,len_sir; len of len sir  we mov it in ecx
        
        for_1:
        
        mov ebx,[max1];
        
        cmp [esi],ebx;
        jna nu_maxim
        
        mov edx,0;
        mov eax,[esi]
        idiv dword [var_16]
        
        cmp edx,0;
        jne nu_maxim;
        
        mov [max2],ebx
        mov ebx,0;
        mov ebx,[esi]
        mov [max1],ebx;

        nu_maxim:
        inc esi;
        inc esi 
        inc esi
        inc esi
        loop for_1
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
