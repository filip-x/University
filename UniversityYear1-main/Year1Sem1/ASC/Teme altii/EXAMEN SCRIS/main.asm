bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
extern scanf
import scanf msvcrt.dll
                         

extern verificareIP
extern conversie
segment data use32 class=data
    
    sir resb 1000;
    format_citire db "%s",0;
    zece dd 10;
    

segment code use32 class=code
    start:
        ; ...
        
        mov eax,0
        mov ebx,0
        mov ecx,0
        mov edx,0
        
        
        mov esi,sir
        push dword sir;
        push  dword format_citire;
        call [scanf];
        add esp,4*2;
        
        mov edx,[esi];
        
        cmp edx,44;
        je virgula
      
        cmp edx,46;
        je punct
        
        ; daca nu e nici punct si nici virgula aduci e numar si o sa il adunam intr-un 
        mov ecx,0;
        mov ecx,[esi]
        imul dword[zece];inmultim pentru a forma numarul cerut( cifra cu cifra)
        add eax,ecx;
        
        virgula:
            inc esi, mergem pe urmatorul caracter
            
        punct:
            push eax; am pregatit numarul pentru a apela functia creata in celalat fisier 
            ; dupa ce apela functia numarul o sa devina iar 0 pentru a incepe iar numaratoarea
            mov eax,0;in eax pastram numarul pe care il il bagam pe stiva ca sa fie preluat de functii externe 
        

    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
