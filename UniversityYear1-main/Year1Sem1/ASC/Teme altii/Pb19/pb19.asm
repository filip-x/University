bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
extern printf
import printf msvcrt.dll
extern fopen
import fopen msvcrt.dll
extern fclose
import fclose msvcrt.dll
extern fscanf
import fscanf msvcrt.dll
; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...

    filename db "numere.txt",0;
    access db "r",0;
    
    nr_temporar dd 0;
    
    descriptor dd -1;
    
    p resd 1000; maxim 1000 de numere intra aici 
    len_p dw 0
    n resd 1000; maxim 1000 de numere intra aici 
    len_n dw 0
 
    format_numar db "%d",0
    format_afisare db "%d ",0

; our code starts here
segment code use32 class=code
    start:
        ; ...
        
        ;open
        push dword access;
        push dword filename;
        call [fopen];
        add esp,4*2;
       
        ;check file
        cmp eax,0;
        je final
        mov [descriptor],eax;
        
        mov esi,p;
        mov edi,n;
        for_1:
            ; 
            push dword nr_temporar
            push dword format_numar
            push dword [descriptor]
            call [fscanf]
            add esp,4*3
           
            cmp eax,-1; 
            je close
            
            mov eax,[nr_temporar]
            cmp eax,0;
            jg pozitiv
            ; daca ii negativ
            mov [edi],eax;
            add edi,4;
            inc word[len_n];
            jmp fin1
            ;daca ii pozitiv
            pozitiv:
            mov [esi],eax;
            add esi,4;
            inc word[len_p]
            fin1:
            
        jmp for_1   
            
        ;close file
        close:
        push dword [descriptor];
        call [fclose]
        add esp,4; 
 
        mov ecx,0
        mov esi,p;
        mov edi,n;
        mov cx,[len_p]
        for_2:
        ;afisre pe ecran
        push ecx
        push dword [esi]
        push dword format_afisare
        call [printf]
        add esp,4*2;
        add esi,4
        pop ecx
        loop for_2
        
        mov ecx,0
        mov cx,[len_n]
        for_3:
        ;afisre pe ecran
        push ecx
        push dword [edi]
        push dword format_afisare
        call [printf]
        add esp,4*2;
        add edi,4
        pop ecx
        loop for_3
    
        final:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
