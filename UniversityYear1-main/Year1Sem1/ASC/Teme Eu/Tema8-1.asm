bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit,printf,scanf              ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process.isdefined in msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll

                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    ;Read a number in base 10 from the keyboard and display the value of that number in base 16 Example: Read: 28; display: 1C
    a dw 0
    b dw 0
    message db "a=", 0
    format1 db "%d", 0
    format2 db "%x",0
    
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        push dword message 
        call [printf]
        add esp, 4*1
        
        push dword a 
        push dword format1 
        call [scanf]
        add esp,4*2
        push dword [a] 
        push dword format2
        call [printf]
        add esp,4*2
        