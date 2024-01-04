bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
import fread msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
extern fread, fopen, fclose
; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    file_name db "Sursa.txt", 0
    access_mode db "r", 0
    len equ 256
    file_descriptor dd -1
    text resb 256
    final db -1
    text_nou resb 256
    
    vocale db "aeiou", 0
; our code starts here
segment code use32 class=code
    sterge_vocale:
        ; primim sirul initial si sirul nou ca parametrii
        mov esi, [esp + 4]
        mov edi, [esp + 8]
        mov eax, 0
        ; verificam daca caracterul actual e vocala
        mov al, [esi]
        push eax
        call e_vocala
        cmp eax, 0
        jne nu_vocala
        ; daca e vocala atunci nu il adaugam in noul sir
        inc esi
        jmp final
        ; daca nu e vocala adaugam caracterul in sirul nou
        nu_vocala:
        mov al, [esi]
        mov [edi], al
        inc esi
        inc edi
        final:
        ; verificam daca am ajuns la sfarsit
        mov al, -1
        cmp [esi], al
        je final2
        ; daca nu am ajuns la final apelam recursiv
        push edi
        push esi
        call sterge_vocale
        final2:
        ret 4 * 2
        
    start:
        ; ...
        ; deschidem fisierul
        push dword access_mode     
        push dword file_name
        call [fopen]
        add esp, 4*2                

        mov [file_descriptor], eax  
        
        ; daca nu s-a deschis corect oprim programul
       
        cmp eax, 0
        je final

        ; citim caracterele
        push dword [file_descriptor]
        push dword len
        push dword 1
        push dword text        
        call [fread]
        add esp, 4*4

        ;inchidem fisierul
        push dword [file_descriptor]
        call [fclose]
        add esp, 4
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
