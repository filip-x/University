;a
(defun dot_product(ListA ListB)
    (cond
     ((null ListA) 0)
     (t ( + (* (car ListA) (car ListB)) (dot_product (cdr ListA) (cdr ListB))))
    )
)

(format t "a) ")
(write (dot_product (list 1 2 3) (list 4 5 6)))
(fresh-line )

;b
(defun maxim(a b)
    (cond
        ((> a b) a) ; if a bigger then b return a 
        (t b) ;otherwise return b everytime
    )
)
(defun depth(ListA)
    (cond
        ((null ListA) 1)
        ((null (listp (car ListA))) (depth (cdr ListA))) ; we negate that the first element is not a list
        ((listp (car ListA)) (maxim (+ 1 (depth (car ListA))) (depth (cdr ListA)))) 
    )
)
(format t "b) ")
(write (depth (list 1 2 3 (list 4 5 (list 3)))))
(fresh-line )
(format t "b) ")
(write (depth (list 1 2 3)))
(fresh-line )

;c

(defun minim(a b)
    (cond
        ((< a b) a) ; if a smaller then b return a 
        (t b) ;otherwise return b everytime
    )
)

(defun get_min(ListA nr)
    (cond 
        ( (null ListA) 99999)
        ( (> (car ListA) nr) (minim (car ListA) (get_min (cdr ListA) nr ) ) )
        ( (<= (car ListA) nr) (get_min (cdr ListA) nr ) )
    )
)

(defun sorted(ListA last_nr)
    (cond
        ((null ListA ) (list ) )
        ((= (get_min ListA last_nr) 99999) (list ) )
        ((/= (get_min ListA last_nr) last_nr ) (cons (get_min ListA last_nr) (sorted ListA (get_min ListA last_nr) ) ) ) 
    )
)
(format t "c) ")
(write (sorted (list 1 1 2 5 3 1 6 7) -1) )
(fresh-line )
;d
(defun is_in_set(ListA nr)
    (cond 
        ((null ListA) nil)
        ((= (car ListA) nr) t)
        (t (is_in_set (cdr ListA) nr))
    )
)

(defun intersect(ListA ListB)
    (cond
        ((null ListA) (list ))
        ((null ListB) (list ))
        ((null (is_in_set ListB (car ListA) ) ) (intersect (cdr ListA) ListB) )
        ((is_in_set ListB (car ListA) ) (cons (car ListA) (intersect (cdr ListA) ListB) ) )
    )
)

(format t "d) ")
(write (intersect (list -1 -2 -3 0 1 2) (list 1 2 3 4 5 6)) )
(fresh-line )
