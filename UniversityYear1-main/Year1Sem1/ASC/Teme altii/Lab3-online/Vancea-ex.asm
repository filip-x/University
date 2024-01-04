;Given the words A and B, compute the word C as follows:
;- the bits 0-2 of C are the same as the bits 10-12 of B
;- the bits 3-6 of C have the value 1
;- the bits 7-10 of C are the same as the bits 1-4 of A
;- the bits 11-12 have the value 0
;- the bits 13-15 of C are the invert of the bits 9-11 of B

; We will obtain the word C by successive "isolation" of bits sequences. The isolation
; of the bits 10-12 of B is done by obtaining the unchanged values of these bits,  
; and initialising all other bits to 0. The isolation operation can be performed
; using the operator AND between the word B and the mask
; 0001110000000000. Once isolated, the sequence of bits is put on the right  position by using a rotation operation. 
; The final word is obtained by applying the operator OR between all intermediate results obtained by using isolations and rotations.

; Observation: bits are numbered from right to left

bits 32 ;assembling for the 32 bits architecture
; the start label will be the entry point in the program
global  start 

extern  exit ; we inform the assembler that the exit symbol is foreign, i.e. it exists even if we won't be defining it
import  exit msvcrt.dll; exit is a function that ends the process, it is defined in msvcrt.dll
        ; msvcrt.dll contains exit, printf and all the other important C-runtime functions
segment  data use32 class=data ; the data segment where the variables are declared 
     a dw 0111011101010111b
     b dw 1001101110111110b
     c dw 0
segment  code use32 class=code ; code segment
start: 

     mov  bx, 0 ; we compute the result in bx

     mov  ax, [b] ; we isolate bits 10-12 of B
     and  ax, 0001110000000000b
     mov  cl, 10
     ror  ax, cl ; we rotate 10 positions to the right
     or   bx, ax ; we put the bits into the result

     or   bx, 0000000001111000b ; we force the value of bits 3-6 of the result to the value 1

     mov  ax, [a] ; we isolate bits 1-4 of A
     and  ax, 0000000000011110b
     mov  cl, 6
     rol  ax, cl ; we rotate 6 positions to the left
     or   bx, ax ; punem bitii in rezultat

     and  bx, 1110011111111111b ; facem biti 11-12 din rezultat sa aiba valoarea 0

     mov  ax, [b]
     not  ax ; we invert the value of b
     and  ax, 0000111000000000b ; we isolate the bits 9-11 of B
     mov  cl, 4
     rol  ax, cl ; we rotate 4 positions to the left
     or   bx, ax ; punem biti in rezultat

     mov  [c], bx ; we move the result from the register to the result variable

     push dword 0 ;saves on stack the parameter of the function exit
     call [exit] ;function exit is called in order to end the execution of
the program	
