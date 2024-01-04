bits 32 
segment code use32 public code
global schimbare_baza

import printf msvcrt.dll
import scanf msvcrt.dll
extern printf
extern scanf

segment data2 use32 class=data
    format_16 db "Base16 = %x",0
    format_2 db "Base2 = %s",0
    save_number dw 0
    nr_base2 resb 17
       
schimbare_baza:
    ; Schimbare in baza 16 si baza 2 
    mov ecx,[esp+4]
    mov  [save_number], cx
    push dword ecx
    push dword format_16
    call [printf]
    add esp, 4*2
    ; this was for base 16 
    mov ax, [save_number]
    mov dx,0
    mov ecx,nr_base2; aici avem indicele de la numarul in baza 2/ si se preia adresa
    
    repeat:
        mov bx,2
        div  bx
        mov [ecx] ,dl; ceea ce fac acum in ecx se tranfera in nr_base2 pentru ca au aceeasi adresa
        mov dx,0
        add byte [ecx],"0"
        inc ecx
        mov bx,0
        cmp bx,ax
        jne repeat; partea de dinainte se repeta si se repeta pana cand cmp  este egal 
        
    push dword nr_base2
    push dword format_2
    call [printf]
    add esp,4*2
    
            
        
    

    ret 4
    
    
