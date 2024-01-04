bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
import printf msvcrt.dll
import scanf msvcrt.dll

extern printf, scanf, este_patrat_perfect
; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    n dd -1
    a resw 256
    format_citire_nr db "%d", 0
    format_afisare_n db "n = ", 0
    format_afisare_nr db "Introduceti un numar: ", 0
    
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        ; citim n
        push format_afisare_n
        call [printf]
        add esp, 4 * 1
        
        push n
        push format_citire_nr
        call [scanf]
        add esp, 4 * 2
        
        ; verificam daca n este diferit de 0
        mov ecx, [n]
        jecxz final
        
        ; verificam daca n este patrat perfect
        push dword [n]
        call este_patrat_perfect
        cmp eax, -1
        je final
        
        ; citim n numere
        mov esi, a
        repeta1:
            pusha
            push format_afisare_nr
            call [printf]
            add esp, 4 * 1
            popa
            pusha
            push esi
            push format_citire_nr
            call [scanf]
            add esp, 4 * 2
            popa
            
            add esi, 2
            loop repeta1
        ; in ebx avem acum radical din n
        
        final:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
        
        ; la b)  acolo unde ai (a) trebuie scris asa 0000005B
