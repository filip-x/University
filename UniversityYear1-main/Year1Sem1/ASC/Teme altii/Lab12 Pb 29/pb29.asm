bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)

global _invers     




; our data is declared here (the variables needed by our program)
segment data public data use32
    ; ...
    cuvant dd 0;
; our code starts here
segment code public code use32
    _invers:
        ; ...
        push ebp;
        mov ebp,esp;
        mov eax,0;
        mov esi, [ebp+8]; bcs i pushed ebp i need to have ebp+8
        mov [cuvant],esi;
        push dword -1
        
        bucla:
        mov al,[esi]
        cmp al,0;
        je final_cuvant
        
        push eax;pusham litera sa o putem prelua invers apoi
        inc esi;
        jmp bucla
       
        final_cuvant:
        
        mov esi,[cuvant]
        
        
        bucla2:
        pop eax;
        cmp eax,-1;
        je final_prob
        
        mov [esi],al
        inc esi;
        jmp bucla2
        
        final_prob:
        
        mov esp,ebp;
        pop ebp
        ret 4

        
