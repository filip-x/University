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
    a DB 2, 1, 3, 3, 4, 2, 6
    len1 equ $ - a
    b DB 4, 5, 7, 6, 2, 1
    len2 equ $ - b
    len equ len1 + len2
    r times len DB 0
    doi db 2;
; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov esi, b + len2 - 1; b-final
        mov ecx, len2;
        mov edi, r;
        
        for1:; for-ul asta merge pe b invers si preia elementele si le pune in r 
            cmp ecx,0;
            je dupa_for1; daca cmp ii adevarat atunci sa iasa din for( nu e necesara conditia pentru ca loop deja face asta, dar eu o pun oricum)
                mov al,[esi]
                mov byte[edi],al;
                dec esi;
                inc edi;
        loop for1; 
        dupa_for1:
        
        ; pana aici in r avem tot b-ul cum trebuie;
        
        mov ecx,len1;
        mov esi,a; mergem pe adresa de inceput a lui a ca sa preluam numerele din a 
        mov ebx,0; aici o sa tinem o dublura la numere pentru ca noi le impartim 
        
        for2:
            cmp ecx,0;
            je final_program
            mov ax,0;
            mov al,[esi];numarul pe care il impartim
            mov bl,[esi];copia 
            div byte[doi];
            cmp ah,1;
            je nu_e_par
                mov byte[edi],bl;
                inc edi;
            nu_e_par:
            inc esi;linia asta se executa si daca e par si daca nu;
           
        loop for2
        final_program:
        
        
        
        
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program