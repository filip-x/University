bits 32 ; assembling for the 32 bits architecture

extern scanf
import scanf msvcrt.dll
extern printf 
import printf msvcrt.dll



; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    
   
    isPrime dd 1
    counter dd 0
    
    format_afisare db "%x",0
    
; our code starts here
segment code use32 class=code
    prim:
        mov ecx,[esp+4];  punem numarul in ecx, il preluam din stiva ( ebx-ul pe care l-am pushat)
        continue_prime_check:
        dec dword [counter]
        cmp dword [counter], 2
        jge not_reached_1_yet
        jmp prime_check_ended

    not_reached_1_yet:
        mov eax,ecx; aici mutam numarul sa putem lucra pe el 
        mov ebx, [counter]
        idiv ebx
        cmp edx, 0
        je evenly_divisible
        jmp not_evenly_divisible

    evenly_divisible:
        mov dword [isPrime], 0

    not_evenly_divisible:
        jmp continue_prime_check

    prime_check_ended:
        cmp dword [isPrime], 1
        je number_was_prime
        jmp number_wasnt_prime

    number_was_prime:
        push dword ecx
        push dword format_afisare
        call [printf]
        add esp,4*2
        jmp end_if

    number_wasnt_prime:

    end_if:
        ret 4
