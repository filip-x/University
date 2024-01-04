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
    ;d-(7-a*b+c)/a-6+x/2; a,c-byte; b-word; d-doubleword; x-qword
    ; 15-(7-1*6+2)/1-6+12/2= 15-3-6+6= 13 = C
    a db 1
    c db 2
    b dw 6
    d dd 15  
    x dq 12 
    z db 7 ;variables
    y db 6 ;variables
    w db 2 ;variables
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov ax, 0
        mov al,[a] ; we move a in ax  so that we can do the multiplication 
        mov dx ,[b] ; we move b in dx so that we can do the multiplication in word ( it must be in dx and the end result it will be in ax 
        mul dx 
        mov cx,0
        mov cl,[z]
        sub cx,ax
        mov ax,0
        mov al,[c]
        add cx,ax
        mov eax,0
        mov ax,cx
        mov cx,0
        mov cl,[a]
        div cx  ; in ax se salveaza valoare,iar in dx se alfa ce lcu care se imparte 
        mov edx,0
        mov edx,[d]
        sub edx,eax
        mov eax,0
        mov al,[y]
        sub edx,eax ; totul este salcvat in edx 
        mov ecx,0
        mov ecx,edx ; salvam in ecx 
        mov eax,0 
        mov eax,[x]
        mov edx,[x+4]
        mov ebx,0
        mov bl,[w]
        div ebx
        add ecx, eax 
        adc edx,0
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program

        