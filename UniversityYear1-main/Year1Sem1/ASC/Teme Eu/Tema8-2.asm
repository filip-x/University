bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
extern scanf
import scanf msvcrt.dll

extern printf
import printf msvcrt.dll

extern fopen
import fopen msvcrt.dll      

extern fclose
import fclose msvcrt.dll

extern fprintf
import fprintf msvcrt.dll                   
                 

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    ;Read a file name and a text from the keyboard. Create a file with that name in the current folder and write the text that has been read to file. Observations: The file name has maximum 30 characters. The text has maximum 120 characters.
    msg db "File name",0
    msg2 db "Text",0
    file resb 31
    text resb 121
    access db "w",0
    format db "%s",0
    desc dd -1
; our code starts here
segment code use32 class=code
    start:
        ; ...
        push msg 
        push dword format 
        call [printf] ;print 
        add ESI, 4*2
        ;Getting the file name
        push file
        push dword format
        call [scanf] ;write
        add ESP, 4*2
        ;Printing text:
        push msg2
        push dword format
        call [printf] 
        add ESP, 4*2
        ;Getting the text to write
        push text
        push dword format
        call [scanf] ;write
        add ESP,4*2
        ;Creating the file(or opening it if exists)
        push access
        push file
        call [fopen] ; open the file
        add ESP,4*2
        mov [desc],eax
        cmp eax,0
        je end
        ;Writing the text into  the file
        push dword text
        push dword [desc]
        call [fprintf] ; print in the file 
        add ESP,4*2
        ;Cllosing the file
        push dword [desc]
        call [fclose] ;closing the file
        add ESP,4*1
        end:
        
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
