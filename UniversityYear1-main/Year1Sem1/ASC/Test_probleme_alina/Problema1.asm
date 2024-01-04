bits 32 


global start        


extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
import printf msvcrt.dll     ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
import scanf msvcrt.dll
import fread msvcrt.dll
import fwrite msvcrt.dll
import fscanf msvcrt.dll  
import fopen msvcrt.dll 
extern scanf 
extern printf
extern fread
extern fwrite
extern fscanf
extern fopen
                  


segment data use32 class=data
;01.	Se citeste din fisier un sir de numere.
;a)	Sa se calculeze suma, produsul numerelor, pozitiile maximului. 
;b)	Sa se sorteze sirul de numere.
;c)	Sa se scrie sirul de numere in baza doi intr-un alt fisier.
;d)	Sa se calculeze cel mai lung subsir de numere pare, afisati-l in baza 16.
;e)	Afisati divizorii numerelor neprime.
; d= base 10, c = char, s = sir de caractere, x= nr in base 16


format_afisare_consola db "%d ",0;
format_afisare_consola_cerinta1 db 10,"%d ", "%d ",0
format_afisare_maxim_cerinta1 db " %d ",10,0
format_citire_fisire db "%d",0
file_acces db "r",0 ; we  will  read/ pt fisier
file_descriptor dd 0;
fisier_numere db "fisier_numere.txt",0;
sir_nr resb 100;
lungime_sir dd 0
suma dw 0
produs dd 1
max db 0
sir_maxime resb 100
len_maxim db 0
;pana aici am facut sub a.)
;pentru b avem nevoie de sir 

format_afisare_cerinta2 db " %d ",0
; cerinta c
format_afisare_cerinta3 db " %x ",0
nr_maxim_pare db 0
par db 2




segment code use32 class=code
    start:
      
      
        push dword file_acces
        push dword fisier_numere
        call [fopen] ; facem asta pentru a obtine file_descriptor/ pune file_acces si fisier_numere in file_descriptor
        add esp, 4*2     
     
        mov [file_descriptor],eax;file descriptor is like  the file itself
        cmp eax, 0
        je final
        ;========
        
        mov esi, sir_nr; we mov in esi the  addres  of  sir_nr( the first address)
        
        repeta:
            push dword esi
            push dword format_citire_fisire
            push dword [file_descriptor]
            call [fscanf]; fscanf preia element cu element/ fread preia toata linie (cate caractere ii dai)
            add esp, 4*3
            inc esi
            cmp eax,-1
            jne repeta
        ;we take the elemtns from the file and  put them  in  the sir_nr with esi as  our  index 
         
        mov eax,esi
        mov esi,sir_nr
        sub eax,esi
        mov dword[lungime_sir],eax
        sub dword[lungime_sir],1
        mov ecx,0
        ;=======  here  he   find the  the  lenght  of the string 
        repeta2:
            mov ebx,0
            mov bl,[esi] ;in  bl ii dam direct valoarea 
            push ecx; it's to push  bcs  ecx  will change so  we need  to  push  the value in ecx and then take it  back 
            push dword ebx,; in  ebx o sa imi puna numerele pe care le  doresc
            push dword format_afisare_consola; the format 
            call [printf]
            add esp,4*2
            pop ecx ; we pop  eax now
            inc esi ; we  increase esi to go  to the next element
            inc ecx ;ecx  is  the  ct to see when ecx is equal to lunime_sir
            cmp ecx,[lungime_sir]
            jne repeta2; the jump and cmp
            
        push ecx
        mov esi,sir_nr 
        mov cl,[sir_nr]
        mov byte[max],cl
        pop ecx ;  nu mai facem 0 ca facem cu loop 
        ;here we make the sum of every element
        mov eax,1
        repeta3_suma:
            mov ebx,0
            mov bl,[esi]
            add [suma],bx
            mul ebx; be carefull  mul  with the same size
            inc esi
            cmp [max],bl
            jnae interschimb
            jmp maxim_schimb
            interschimb:
                mov [max],bl
            maxim_schimb:
            
            loop repeta3_suma ; loop-ul face cmp la ecx si 0 si daca nu e repeta la ce ii dau si scade ecx 
            mov [produs],eax
        ; we pint  the sum 
        
        mov edx,0
        mov ebx,0
        mov bx,[suma]
        mov edx,[produs]
        push edx
        push ebx
        push dword format_afisare_consola_cerinta1
        call [printf]
        add esp,4*3
        mov ecx,0
        
        mov esi,sir_nr
        mov edi,sir_maxime
        repeta4_maxim:
            mov bl,[max]
            cmp bl,[esi]
            je ct_in_sir
            jmp daca_nu
            ct_in_sir:
                mov [edi],cl; punem indicele in edi 
                add byte[len_maxim],1
                inc edi;trecem la  urmatorul element din edi 
            daca_nu:
            inc esi
            inc ecx
            cmp ecx,[lungime_sir]
            jne repeta4_maxim
            
        mov ecx,0
        mov edi,sir_maxime
        repeta5_maxim_afisare:
            pusha
            mov ebx,0
            mov bl,[edi]
            push dword ebx
            push dword format_afisare_maxim_cerinta1
            call [printf]
            add esp, 4*2
            popa
            inc edi
            inc ecx
            cmp cl,[len_maxim]
            jne repeta5_maxim_afisare
        ; ===========================sortare sir
        
        mov esi,sir_nr
        mov ecx,0
        repeta6_sortare:
            cmp ecx,0
            je increase_ecx
            jmp sari_peste
            increase_ecx:
                inc ecx
                inc esi
            jmp sari_peste3
            sari_peste:
            
            mov bl,[esi]
            dec esi; 
            mov dl,[esi]
            inc esi ; ca sa nu fie schimbat
            cmp bl,dl
            jae increase_row
            jmp sari_peste2
            increase_row:
                inc esi
                inc ecx
                jmp sari_peste3
                
            sari_peste2:
            mov ebx,0; ajuta la interschimbare ca sa nu avem valori reziduale
            mov edx,0
            
            mov bl,[esi]
            dec esi
            
            mov dl,[esi]
            inc esi
            
            push ebx
            mov bl,dl
            pop edx
            ;interschimbarea
            
            mov [esi],bl
            dec esi
           
            mov [esi],dl
            inc esi
            
            dec ecx 
            dec esi
                
            sari_peste3:
            cmp ecx,[lungime_sir]; atunci se opreste "while" 
            jb repeta6_sortare
           
           mov ecx,0
           mov esi,sir_nr
           
           ; afisare sir 
           repeta7_sortare_afisare:
           pusha
           mov ebx,0
           mov bl,[esi]
           push dword ebx
           push dword format_afisare_cerinta2
           call [printf]
           add esp,4*2
           popa; dap pop aici pentru ca esi si ecx sunt 1 si apoi le crestem pentru a pune urmatorul element
           inc ecx
           inc esi
           
           cmp ecx,[lungime_sir]
           jne repeta7_sortare_afisare
           
           mov ecx,0; inceput de sir ( contorul)
           mov edx,0
           mov eax,0
           mov esi,sir_nr;inceput de sir 
           
           repeta8_numere_pare_consecutive:
                
                cmp ecx,[lungime_sir]
                je sari_peste_tot
                
                mov al,[esi]
                div byte [par]
                cmp ah,0
                je e_par ;daca nr e par sa repete
                
                e_impar:
                    
                    cmp dl,[nr_maxim_pare]
                    ja interschimb2
                    jmp daca_nu3
                    interschimb2:
                        mov edi,esi
                        push ecx
                        mov cl,dl
                        repeta10:
                            dec edi
                            loop repeta10 ; puteam sa ziceam si ca cl si si sa  facem cu jmp 
                        pop ecx
                        mov [nr_maxim_pare],dl
                    daca_nu3:
                    mov dl,0
                    inc ecx
                    inc esi
                    mov ah,0; ca sa nu fie valori de la cealalta in ah 
                    jmp repeta8_numere_pare_consecutive
                e_par:
                    inc dl
                    inc eax
                    inc ecx
                    inc esi
                    jmp repeta8_numere_pare_consecutive
                    
                dec esi
                mov al,[esi]
                div byte [par]
                cmp ah,0
                je interschimb_final
                jmp daca_nu2
                interschimb_final:
                
                    mov edi,esi
                    push ecx
                    mov cl,dl
                    repeta_final:
                        dec edi
                        loop repeta_final ; puteam sa ziceam si ca cl si si sa  facem cu jmp 
                    pop ecx
                daca_nu2:
                    
                    
     
                cmp ecx,[lungime_sir]
                jne repeta8_numere_pare_consecutive
                
                sari_peste_tot:
                
            
           ; afisare sir 
           mov edx,0
           repeta10_sortare_afisare:
           pusha
           mov ebx,0
           mov bl,[edi]
           push dword ebx
           push dword format_afisare_cerinta3
           call [printf]
           add esp,4*2
           popa; dap pop aici pentru ca esi si ecx sunt 1 si apoi le crestem pentru a pune urmatorul element
           inc edi
           inc dl
           cmp dl,[nr_maxim_pare]
           jne repeta10_sortare_afisare
           
           
        
            
        
        
            
        
       
        
        
        
               
        
            
            
        
        
        
        
        
      
      
        
    
    
    
        final:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
