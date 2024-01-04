bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
import scanf msvcrt.dll
import printf msvcrt.dll
import fscanf msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fprintf msvcrt.dll
extern scanf, printf, fscanf, fopen, fclose, fprintf

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    afisare1 db "Introduceti numele fisierului: ", 0
    afisare2 db "Introduceti un numar: ", 0
    format_citire1 db "%s", 0
    format_citire2 db "%d", 0
    access db "w", 0
    n dd 0
    nume_fisier resb 100
    desc dd 0
    semn dd 1
    ten dd 10
    

; our code starts here
segment code use32 class=code
    start:
        ; ...
        ; Citire nume fisier
        push afisare1
        call [printf]
        add esp, 4
        
        ;
        push dword nume_fisier
        push dword format_citire1
        call [scanf]
        add esp, 4 * 2
        
        ; Citire numar n
        push dword afisare2
        call [printf]
        add esp, 4
        ; ..
        push dword n
        push dword format_citire2
        call [scanf]
        add esp, 4 * 2
        ; Deschidere fisier
        push access
        push nume_fisier
        call [fopen]
        add esp, 4 * 2
        mov [desc], eax
        
        cmp dword [n], 0 ; daca numarul e negativ salvam asta in semn si il transformam in numarul pozitiv
        jge .pozitiv ; gr or equal
        mov dword [semn], -1
        mov eax, [n]
        imul dword [semn]; inmultim cu -1 daca este negativ pentru a il face pozitiv/  nu are efect asupra problemei daca e negativ 
        mov [n], eax;punem numarul inapoi pentru a fi prelucrat 
        .pozitiv:
        
        mov eax, [n]
        mov ecx, 0
        .repeta1: ;introducem toate cifrele  din numar pe  stiva,iar apoi o sa apelam doar pe cele de pe pozitiile pare 
            mov edx, 0; pentru a face div cu 10 ( sa luam ultima cifra)
            div dword [ten] ; vom avea rezultautl in eax si restul in edx = restul adica ultima cifra din numar 
            push edx
            inc ecx
            cmp eax, 0
            jne .repeta1
            ;idiv 10
        
        mov eax, 0
        .repeta2: ; luam toate cifrele de pe stiva, dar le introducem in numar doar pe cele de pe pozitii pare (din doua in doua, incepand cu prima)
            mul dword [ten]; refacem numarul doar cu numerle  de pe pozitiile pare 
            pop ebx ;preluam numarul din stiva 
            add eax, ebx
            pop ebx ; sarim un element ca sa ramana in eax doar cele de pe pozitiile pare 
            dec ecx 
            cmp ecx, 0; ecx contor de cifre 
            je .exitRepeta2
            loop .repeta2
        .exitRepeta2
        
        imul dword [semn] ; readaugam semnul la numarul final
        
        ; scriem in fisier
        push eax
        push dword format_citire2
        push dword [desc]
        call [fprintf]
        add esp, 4
        
        ; inchidem fisierul
        push dword [desc]
        call [fclose]
        add esp, 4
        .end:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program