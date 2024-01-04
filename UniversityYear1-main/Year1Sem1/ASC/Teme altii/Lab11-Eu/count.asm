bits 32 ; 

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          
extern printf 
import printf msvcrt.dll
; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...

    
    
    format_afisare db "%d ",10 ,0;
; our code starts here
segment code use32 class=code
global count

     count:
    mov ebx,0;
         mov eax,[esp+4];
         mov esi,eax;
         
        for_2:
            mov al,[esi]
            cmp al,0;
            je forend
            inc esi
            inc ebx;
            
            
        jmp for_2
        forend:
        push dword ebx 
        push dword format_afisare
        call [printf]
        add esp,4*2;
       
        ret 4
     
