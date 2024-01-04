bits 32 

global start        


extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fprintf msvcrt.dll ;word by word 
import fscanf msvcrt.dll ;word by  word 
import fwrite msvcrt.dll ;write a string
import fread msvcrt.dll ;takes sentance

extern scanf
extern printf 
extern fopen
extern fclose
extern fscanf
extern fwrite
extern fread 
extern fprintf
extern secventa
                        

segment data use32 class=data

    sir_nr resb 100
    format_afisare_consola db "Citeste nr: ",0
    format_citire_nr db "%d",0
    format_afisare_consola_nr db "%x",0
    nr db 0
    

segment code use32 class=code
    start:
    mov esi,sir_nr
    while_1:
    push dword format_afisare_consola
    call [printf]
    add esp,4
    
    push dword esi
    push dword format_citire_nr
    call [scanf]
    add esp,4*2
    inc esi
    
    
    mov bl,0
    cmp [esi-1],bl
    jne while_1
    
    push dword sir_nr
    call secventa
    
    mov ebx,0
    while_2:
    ;afisare numere
    mov bl,[eax]
    pusha
    push dword ebx
    push dword format_afisare_consola_nr
    call [printf]
    add esp,4*2
    popa
    
    inc eax
    dec ecx
    cmp cl,0
    jne while_2
     
    
    
    
        
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
