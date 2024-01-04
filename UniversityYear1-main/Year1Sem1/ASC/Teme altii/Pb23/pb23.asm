bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
                          
extern fopen
import fopen msvcrt.dll
extern fclose
import fclose msvcrt.dll
extern fread
import fread msvcrt.dll
extern fread
import fread msvcrt.dll
extern fprintf
import fprintf msvcrt.dll
extern scanf
import scanf msvcrt.dll
extern printf 
import printf msvcrt.dll

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    
    s1 resd 1000;
    len_s1 dw 0;
    _ dd -1;
    s2 resd 1000;
    
    suta dd 100;
    zece dd 10;
    
    
    temp_nr dd 0;
    format_nr_afisare db "%d ",0;
    screenMsg_nr db "Nr= ",0;
    format_nr db "%d",0;
    
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov esi,s1;
        bucla:
        push dword screenMsg_nr;
        call [printf];
        add esp,4*1;
       
        push dword esi;
        push dword format_nr;
        call [scanf];

        add esp,4*2;
        add esi,4;
        inc word[len_s1];
        mov ebx,-1;
        cmp [esi-4],ebx;
        jne bucla
        
        dec word[len_s1];
        
        mov eax,0;
        mov ecx,0
        mov esi, s1;
        mov edi, s2;
        mov cx, [len_s1];
        
        for1:
        mov edx,0;
        mov eax,[esi];
        
        idiv dword[suta];
        mov edx,0;
        idiv dword[zece];
        
        mov [edi], edx;
        

        add esi,4;
        add edi,4;
        
        loop for1
       
        mov edi,s2;
        mov ecx,0
        mov cx,[len_s1];
        
       for2:
       push ecx;
       push dword[edi]
       push dword format_nr_afisare;
       call [printf]
       add esp,4*2
       pop ecx;
       add edi,4;
       loop for2
        
        
        
        
        
        
        
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
