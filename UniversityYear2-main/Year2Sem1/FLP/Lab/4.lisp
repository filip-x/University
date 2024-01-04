;4. Convert a tree of type (2) to type (1).
; ConvertType2(a1..an) = {
;       [], list a is empty
;       [a1, n - 1] U ConvertType2(a2) U ... U ConvertType2(an), otherwise
;    }
;(caddr x)       (car (cdr (cdr x))) 3th element
;(cadr x)        (car (cdr x)) 2nd element
(defun ConvertType2(ListA)
    (let ( (st (cadr ListA)) (dr (caddr ListA)))
        (cond
            ((null ListA)
                nil)
            ((null st)
                (list (car ListA) 0))
            ((null dr)
                (append (list (car ListA) 1) ( ConvertType2 st)))
            (t 
                (append (list (car ListA) 2) ( ConvertType2 st) ( ConvertType2 dr)))
        )
    )
)
(write (ConvertType2 (list "A" (list "B" (list "D") (list "E" (list "H"))) (list "C" (list "F" (list "I")) (list "G")))))