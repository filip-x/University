bits 32 ; assembling for the 32 bits architecture

global _concatenare

segment data public data use32
    rezultat times 100 db 0

; our code starts here
segment code public code use32
_concatenare:
    push ebp
    mov ebp,esp
     
    mov esi, [ebp+8]
    mov ebx, [ebp+12];
    
    mov edi,rezultat
    
    bucla:
        lodsb  ;load in al the first byte from esi
        cmp al,'0' ;verifies if it is a decimal digit
        jb next_char
        cmp al,'9'
        ja next_char
        stosb ;store al into the byte from edi
        next_char:
        mov dl,[esi]
    cmp dl,0;
    jne bucla

    mov esi,ebx;bagam sirul 2 in esi sa putem merge pe el 
 
    
    bucla2:
        lodsb
        cmp al,'0'
        jb next_char2
        cmp al,'9'
        ja next_char2
        stosb
        next_char2:
        mov dl,[esi]    
    cmp dl,0;
    jne bucla2
    
    mov al,0
    stosb
    
    mov eax,rezultat
    mov esp,ebp
    pop ebp
    ret 8