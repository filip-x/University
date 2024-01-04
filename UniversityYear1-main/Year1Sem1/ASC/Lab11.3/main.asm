bits 32 


global start        


import scanf msvcrt.dll
import printf msvcrt.dll           
import exit msvcrt.dll  ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
extern printf
extern scanf, exit 

extern numere_prime


segment data use32 class=data

    format_string db "%d",0 ; d= base 10, c = char, s = sir de caractere, x= nr in base 16
    format_citire db "Write some numbers:",0
    format_afisare db "%d ",0
    nr dw 0; where we save the numbers/ this is a variable to 
    string_of_number resw 10
    
    
    
segment code use32 class=code
    start:
    mov esi,string_of_number
    repete_writing_numbers:
    
        
        push dword format_citire
        call [printf]
        add esp, 4 *1
        
        push dword nr
        push dword format_string
        call [scanf]
        add esp,4*2
        
        push dword[nr]
        call numere_prime
        cmp eax,1
        je prim
        
        cmp eax,0
        je nu_prim
        
        prim:
            mov [esi],eax
            inc esi
            inc esi ; pt ca sunt word si atunci trebuie mai mult spatiu 
            
            
        nu_prim:
        mov bx,0
        cmp [nr],bx
        jne repete_writing_numbers
    mov esi,string_of_number;ca sa reincepem de la inceput   
    afisare:
        mov edx,0
        mov dx,[esi]
        push  edx
        push dword format_afisare
        call [printf]
        add esp, 4 *2
        inc esi
        inc esi
        cmp word[esi],0
        jne afisare
    push    dword 0      
    call    [exit]       
