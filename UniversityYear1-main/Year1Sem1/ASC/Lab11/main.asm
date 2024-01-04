bits 32
global start

import printf msvcrt.dll
import scanf msvcrt.dll
import exit msvcrt.dll
extern printf
extern scanf, exit

extern verificare

segment data use32
	
    ; in main we will have the read part and the write part 
    ;we will  read from  keyboard words until we have the value 0 inserted 
    ; we write "Yes" if all the words have the first word as a subseq and no if not 
    format_string db "%s",0 ; this variable is for the format citire
    format_citire db "Cuvant=",0; here print Cuvant for the person so that he can type a word
    first_var resb 20 ; we restrict the word to 20 characters
    rest_var resb 20 ; we restrict the others variables to 20 characters 
    sem dd 1 ; presupunem  ca e corect
    format_nr db "%d",0; d  for numbers 
    
segment code use32 public code
start:
	
    push dword format_citire
    call [printf]
    add esp, 4*1
    
    push first_var ; the addres of where the writen word should go
    push dword format_string ;the format in which it comes ( here is string %s)
    call [scanf]
    add esp,4*2
    
    repeta: ; we read the the rest of the words and put them in rest_var
        
        push rest_var ; the addres of where the writen word should go
        push dword format_string ;the format in which it comes ( here is string %s)
        call [scanf]
        add esp,4*2
        mov dl,"0";
        cmp dl,[rest_var] ; we compare the 0 with the value of rest_var(string  value)
        jne continue ; jne= jump not equel, adica sare la continue daca nu e 0 
        mov dl,0
        cmp dl,[rest_var+1] ; we compare if the 0 is the only character in the string (0 with no "" it's  Null for \0 - C++)
        je end ; je - jump is equel, adica sare la end daca asta e egal cu Null
        continue:
            push first_var; parameters for the verificare function
            push rest_var; params for the verificare function 
            ; pe stiva se pun invers asa ca o sa preluam rest_var primul parametru 
            call verificare
            cmp eax,0
            jne continue2 ;jump not equal pentru cand e 1 
            mov dword [sem],0 ; pentru cand e 0 ca sa il putem schimba
        continue2:
            jmp repeta
          
    end:
    push dword [sem]
    push dword format_nr
    call [printf]
    add esp, 4*2
    
	push 0
	call [exit]
