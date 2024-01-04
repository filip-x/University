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
    A dw 1122h, 2233h, 3344h, 4455h, 5566h, 6677h
    len equ ($-A)/2
    b1 times len db 0 ; 11 22 33 44 55 66
    b2 times len db 0 ; 22 33 44 55 66 77

; our code starts here
segment code use32 class=code
    start:
        ; ...
        ; Given an array A of words, build two arrays of bytes:  
        ; - array B1 contains as elements the higher part of the words from A
        ; - array B2 contains as elements the lower part of the words from A
        
        mov ESI, A; am pus pe A in esi 
        mov ECX, len ; len of A
        mov edi,b1; partea high o sa fie in b1, edi
        mov ebx,b2; partea low o sa fie in b2, ebx
        for1:
        
            lodsw; aici punem primul word in ax 
            mov [edi], ah ; move the high part into edi 
            mov [ebx],al; move the low part  in to ebx;
            
            inc edi ; Moving to the next element of B2
            inc ebx ; Moving to the next element of B1
            loop for1 ; REPEAT LEN TIMES (ECX = ECX - 1 after every iteration)
            
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program