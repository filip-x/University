bits 32                         
segment code use32 public code
global verificare

verificare:
	mov eax, 0; in eax o sa avem rezultatul final, 1 daca contine si 0 daca nu contine 
	mov ecx, [esp + 4]; primul paramentru pus pe stiva paramentru este salvat in ecx -pt ca se iau invers ( rest_var)
	mov ebx, [esp+8] ; o sa preluam al doilea parametru este salvat  in ebx ( first_var)
	repeta:; cu acest loop traversam rest_var si vedem daca il contine pe first_var 
        mov dl,[ecx]; we transfer the value of the ecs to the register of edx
        cmp dl,[ebx] ; we compare the register of edx with the value in ebx 
        jne continue ; JNE= jump not equal  to edx letter with the first letter of ebx( first_var)
        push ecx ; pusham  adresa literei actuala pe care i-am dat-o lui edx 
        push ebx ; pusham adresa sirului first_var
        inc ecx
        inc ebx 
        repeta2:
            mov dl,[ecx]; we transfer the value of the ecs to the register of edx
            cmp dl,[ebx] ; we compare the rest of the letters of the seq
            jne break ; cazul acesta este pentru cand am prima litera,dar restul nu,dar s-ar putea sa mai avem in restul cuvantului 
            inc ecx; next letter
            inc ebx ; next letter
            mov dl,0
            cmp dl,[ebx] ; daca e Null atunci stim ca am asjuns la finalul primului cuvant
            jne repeta2 ;daca nu am ajuns la final repetam loop-ul
            mov eax,1; am ajuns la final si exista
            pop ecx
            pop ebx
            jmp break2; in momentul in care am ajuns la final 
            
        break:
        pop ebx ; preluam variabilele de unde am ramas  
        pop ecx ; acceasi chestie 
        continue:
        
        inc ecx ; ca sa treaca la urmatoarea litera din cx
        mov dl,0
        cmp [ecx],dl ; (caracter null)
        jne repeta ; jne = jump not equal  repeta 
    break2:
	ret 8; in this case, 8 represents the number of bytes that need to be cleared from the stack (the parameter of the function) ;avem 4*2 pentru ca avem 2 parametrii 