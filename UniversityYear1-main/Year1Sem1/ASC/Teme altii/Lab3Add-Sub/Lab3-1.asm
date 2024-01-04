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
    a db 5
    b dw 60
    c dd 100
    d dq 300
    
    
    
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        ;100-5+300+60+300=205+360=565
        ;c-(a+d)+(b+d)-unsigned
        ;60+100+5-300+100+5=165-405=-240
        ;(b+c+a)-(d+c+a)-unsigned
        ;100+60+5-600=-435
        ;(c+b+a)-(d+d)-sign
        ;300-5+100+100-60+5=295+140+5=440
        ;d-a+c+c-b+a-sign
        mov eax,0;
        mov ebx,0;
        mov ecx,0;
        mov edx,0;
        
        mov eax,[d];low
        mov edx,[d+4]; high
        mov bl,[a];
        
        add eax,ebx; low
        adc edx,0; high
        
       sub eax,[c];low 
       sbb edx,0;high
       
        mov ebx,0;
        mov ecx,0;
        
        mov ebx,[d]; low 
        mov cx,[b];
        add ebx,ecx;
        mov ecx,0;
        mov ecx,[d+4]; high 
        adc ecx,0;
        
        
        add eax,ebx; with the numbers that i explain the result is 565
        adc edx,ecx;
        
       ;-------------------------------------------------------------------------
        mov eax,0;
        mov ebx,0;
        mov ecx,0;
        mov edx,0;
        
        mov al,[a];
        add ax,[b];
        add dx,0;
        add eax,[c];
        adc edx,0;
        
        mov cl,[a];
        add ecx,[c];
        add ecx,[d];
        add ebx,[d+4];
        
        sub eax,ecx;with the nr that i explain the result is -240 
        sbb edx,ebx;
        
        ;-----------------------------------------------------------
        ;Sign (c+b+a)-(d+d)
        mov eax,0;
        mov ebx,0;
        mov ecx,0;
        mov edx,0;
        
        mov al,[a];
        cbw
        add ax,[b];
        adc dx,0;
        
        push dx;
        push ax;
        
        pop eax;
        
        mov edx,0
        
        add eax,[c];
        adc edx,0;
        
        mov ebx,[d];
        mov ecx,[d+4];
        add ebx,[d];
        adc ecx,[d+4];
        
        sub eax,ebx;
        sbb edx,ecx;
        
        ;--------------------------------------------------------
        ;d-a+c+c-b+a
        mov eax,0;
        mov ebx,0;
        mov ecx,0;
        mov edx,0;
        
        mov ax,[b]
        cwde
        mov ebx,[c];
        sub ebx,eax;
        mov eax,0;
        mov al,[a];
        cbw
        cwde
        add eax,ebx;
        adc edx,0;
        add eax,[c];
        adc edx,0;
        
        push edx;
        push eax;
        mov eax,0;
        mov edx,0;
        mov al,[a];
        cbw
        cwde
        cdq
        mov ebx,[d];
        mov ecx,[d+4];
        sub ebx,eax;
        sbb ecx,edx;
        mov eax,0;
        mov edx,0;
        pop eax;
        pop edx;
        add eax,ebx;
        adc edx,ecx;
        
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
