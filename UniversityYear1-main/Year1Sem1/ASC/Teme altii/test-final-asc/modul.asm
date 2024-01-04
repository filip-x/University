bits 32 ; assembling for the 32 bits architecture

global este_patrat_perfect
; declare the EntryPoint (a label defining the very first instruction of the program)
; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    doi dw 2
; our code starts here
segment code use32 class=code
    este_patrat_perfect:
        mov ebx, [esp + 4]
        mov ecx, 16
        cld
        ; incepem de la 16 si tot scadem
        ; si inmultim numarul cu el insusi
        ; sa vedem daca parametrul (n)
        ; este patrat perfect
        ; si daca este, il salvam in ebx si marcam eax cu 0
        ; altfel marcam eax cu -1
        repeta_pp:
            mov eax, ecx
            mul ax
            cmp eax, ebx
            je este_pp
            loop repeta_pp
        
        este_pp:
            mov eax, 0
            mov ebx, ecx
            jmp final_pp
        
        nu_este_pp:
            mov eax, -1
        final_pp:
        ret 4
        ;
    avg_linie:
        mov esi, [esp + 4] ; matricea
        mov ebx, [esp + 8] ; n
        mov edx, [esp + 12] ; indicele liniei i
        ;
        dec edx
        mov eax, edx
        mul bx
        mul word [doi]
        add esi, eax ; pozitionam esi la inceputul liniei i
        mov ecx, ebx
        cld
        ; facem suma de pe linia n
        mov eax, 0
        mov edx, 0
        repeta_avl:
            mov dx, [esi]
            add esi, 2
            add eax, edx
            loop repeta_avl
        div bx
        ret 4 * 3
    
    avg_coloana:
        mov esi, [esp + 4] ; matricea
        mov ebx, [esp + 8] ; n
        mov edx, [esp + 12] ; indicele coloanei i
        ;
        ; pozitionam esi pe pozitia a[1][i]
        mov eax, edx
        dec eax
        mul word [doi]
        add esi, eax
        mov ecx, ebx
        mov eax, ebx
        mul word [doi]
        push ebx
        mul ebx, eax
        cld
        ; facem suma de pe coloana i
        mov eax, 0
        mov edx, 0
        repeta_avc:
            mov dx, [esi]
            add esi, ebx ; trecem la urmatoarea coloana
            add eax, edx
            loop repeta_avc
        pop ebx
        div bx
        ret 4 * 3
