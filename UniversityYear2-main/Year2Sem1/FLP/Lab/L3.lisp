;14 Write a function that returns the number of atoms in a list, at any level.

;Nodes(array_, lvl,lvl_input) = { 
;   1, array atom and lvl == lvl_input 
;    0, it is an atom but lvl =! lvl_input
;   Σ i=1,m Nodes(array_i,lvl+1,lvl_input), otherwise  ; i-th element of the list
;   
;}

(defun Nodes (array_ lvl lvl_input)  

(cond 
((and (atom array_) (= lvl lvl_input)) 1)  

((listp array_) (apply #' + (MAPCAR  #'(lambda (l) (Nodes l (+ lvl 1)  lvl_input))array_ )))
; mapcar takes every element from array and calls the lambda fucntion on it :))
; mapcar expects a function with only one param so we created a lambda function that integrates all 3 params that we need into 1, l 
; like we only have the lambda parma that is l and the other params are filled by lambda

; the sole pourpose of lambda is to integrate the rest of the params into mapcar 
(t 0)
; if it's not an atom and it's not a list then we return 0  
))

;EXAMPLE1
(write (Nodes (list 'A 'B) -1 0))
;2
(terpri )

;EXAMPLE2
(write (Nodes (list 'A (list 'B) (list 'C))-1 0))
;1