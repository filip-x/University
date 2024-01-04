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

    s dd 0702090Ah, 0B0C0304h, 05060108h;
    len_s equ ($-s)/4;len s
    rez resb (len_s)*2;reserve space for the elements
    len_rez equ ($-rez);len rez
; our code starts here
segment code use32 class=code
    start:
        ; ...
        
        mov esi,s;
        mov edi,rez
        mov ecx,len_s;
        
        for1:
            lodsb ; punem 0A in al
            mov bl,al; mutam pe al in bl sa facem loc pentru urmatorul numar
            lodsb; aducem urmatorul numar in al
            
            shl al,4; shiftm al doilea nr in stanga
            or bl,al; punem impreuna numerele 
            mov [edi],bl;
            inc edi;
           
            lodsb;
            mov bl,al;
            lodsb;
            shl al,4;
            or bl,al;
            mov [edi],bl;
            inc edi;
            loop for1
            
            
           ;we have the results in rez now how have to put them in asceding order;
            mov ecx,len_rez-1; the len of the rez -1, this register will pe pushed on the stack and poped after the second for will end 
            mov ebx,len_rez-1; we keep count so that we don't forget where we are 
            mov esi,rez; primul  element din rez
           
           
            
            for_2:
                
                push ecx;we push so that we can take second for value
                mov ecx,ebx; we moved the value of ebx into ecx so that we can iterate trought the second array (here same array)
                mov edi,esi;
                inc edi;
                for_3:
                    
                    mov dl,[edi]; we put the value of edi in edx so that we can comparethe values 
                    cmp [esi],dl; we cmp if the element before is smaller the the element that comes next 
                    jl no_swap; we jump over this for if the element is not bigger then the next one
                    ; so if we want to swap we mov esi into dx and in dh and dl we have the other number so we just take what it's in dl and dh and mov it in esi;
                    mov dh,[esi];
                    mov [esi],dl; 
                    mov [edi],dh;we made the swap 
     
                    no_swap:
                    inc edi;we go to the next element 
                    loop for_3
                    
                    pop ecx;
                    dec ebx; 
                    
                inc esi; we inc esi so that we can go to the next elementt
                loop for_2
                
  
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
