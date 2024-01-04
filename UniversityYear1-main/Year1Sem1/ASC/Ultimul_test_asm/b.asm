bits 32 
segment code use32 public code
global secventa



segment data2 use32 class=data
    sem db -1
    doi db 2
    maxim db 0
    inceput dd 0
    secventa_finala dd 0
    noul_sir resb 100
    

  secventa:

    mov esi,[esp+4]
    while_1:
        mov ecx,0
        mov bl,0
        cmp [esi],bl
        jb negativ
        jmp positiv
        mov eax,0
        negativ:
            mov al,[esi]
            imul byte [sem]
        positiv:
        ; in caz ca e negativ 
        
        mov al,[esi]
        div byte [doi]
        cmp ah,0
        jne impar
        jmp peste_impar
        ; dacae impar
        impar:
            cmp ecx,0
            je nou
            jmp nu_nou
            nou:
                mov [inceput],esi
            nu_nou:
            ; am verificat daca suntem la inceput de secventa si salvam in inceput adresa de inceput a fiecarei secventei
            inc ecx
            jmp peste_par
        peste_impar:
        par:
            mov eax,[inceput]
            cmp [maxim],cl
            jb schimbare
            jmp treci_peste
            schimbare:
            mov [secventa_finala],eax
            mov [maxim],cl
            treci_peste: 
            mov ecx,0
        peste_par:
        
        
        inc esi; crestem esi pentru final
    ; final primul while
        mov bl,0
        cmp [esi],bl
        jne while_1
    mov eax,0
    mov ecx,0
    
    mov eax,[secventa_finala]
    mov cl,[maxim]
        
ret 4
