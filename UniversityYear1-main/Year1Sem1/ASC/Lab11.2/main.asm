bits 32 


global start        


import scanf msvcrt.dll
import printf msvcrt.dll           
import exit msvcrt.dll  ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
extern printf
extern scanf, exit 

extern schimbare_baza


segment data use32 class=data
    format_string db "%d",0
    format_citire db "Write the number you want to convert:",0
    
    nr dw 0 ; nu rezervam spatiu pentru mai multe asa ca folosim doar dw 
    
    
    
    
    
segment code use32 class=code
    start:
        
        push dword format_citire ;we print what is in ""
        call[printf]
        add esp, 4*1
        
        push nr ; the var where the number will  be put 
        push dword format_string ; the format 
        call[scanf]
        add esp, 4*2
        push dword[nr]; we need the value of nr not the address
        call schimbare_baza
       
        
        
        
        
        
    
        
        push    dword 0      
        call    [exit]       
