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
; and daca e 1 cu 1 atunci e 1 altfel da 0 
; or daca se compara 0 cu 0 atunci e 0 altfel e 1
; xor da 1 daca unul dintre numere e 1 si celalalt e 0 
; test's if the number is ood or even 
; not daca avem 0 devine 1 si daca e 1 devine 0 

; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov eax,123 ;acesta este A
        shr eax, 8
        and eax, 1111b
        mov ebx,200
        and ebx,0FFFFFFF0h
        or ebx,eax
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
