;; 1. Write a function to check if an atom is member of a 
;;list (the list is non-liniar)

(defun check (L elem)
(cond 
    ((AND (atom L) (eq elem L)) 1)
    ((atom L) 0)
    ((numberp L) 0)
    (t
        (apply #'+ (MAPCAR #' (lambda (L) (check L elem)) L) )
    )
)
)

;;suma atomilor numerici de pe toate nivelurile
(DEFUN calculSum(L)
    (cond
        ((numberp L) L)
        ((atom L) 0)
        (t
            (apply #'+ (MAPCAR #'calculSum L))
        )
    )
)

;; (setq l '(1 3 4 g (5 f  2 f (5 g (1)))))
;; (print (calculSum l))

;;Define a function to tests the membership of a node in a n-tree represented as (root
;; list_of_nodes_subtree1 ... list_of_nodes_subtreen)
;; Eg. tree is (a (b (c)) (d) (E (f))) and the node is "b" => true

;; (DEFUN getAppearences (L elem)
;;     (COND
;;        ((null L) 0)
;;         ((NUMBERP L) 0)
;;         ((AND (ATOM L) (eq L elem)) 1)
;;         ((ATOM L) 0)
;;         (T (apply #'MAX (MAPCAR #' (lambda (aux) ( getAppearences aux elem)) L))) ; reprezintă strategia de parcurgere
;;     )
;; )


;; (DEFUN isElementInTree(L elem)
;;     (COND
;;         ((null L) NIL)
;;         (t 
;;             (
;;                 (lambda (found)
;;                     (COND
;;                         ((= found 1) t)
;;                     )
;;                 )   
;;                 ( getAppearences l elem)
;;             )
;;         )
;;     )
;; )

;;Write a function that computes the sum of even numbers and the decrease the sum of odd numbers,
;; at any level of a list.

(DEFUN calculSumAndDif(L)
    (cond
        ((AND (numberp L) (= (mod L 2) 0)) L)
        ((numberp L) (* L -1))
        ((atom L) 0)
        (t
            (apply #'+ (MAPCAR #'calculSumAndDif L))
        )
    )
)

;; (setq l '(1 3 4 g (5 f  2 f (5 g (1)))))
;; (print (calculSumAndDif l))

;;Write a function that computes the sum of even numbers and the decrease the sum of odd numbers,
;; at any level of a list.

(DEFUN calculSumAndDif(L)
    (cond
        ((AND (numberp L) (= (mod L 2) 0)) L)
        ((numberp L) (* L -1))
        ((atom L) 0)
        (t
            (apply #'+ (MAPCAR #'calculSumAndDif L))
        )
    )
)

;; Write a function to determine the number of nodes on the level k from a n-tree represented as follows:
;; (root list_nodes_subtree1 ... list_nodes_subtreen)
;; Eg: tree is (a (b (c)) (d) (e (f))) and k=1 => 3 nodes

(DEFUN numberOfNodes (L k level)
    (COND
        ((null L) 0)
        ((AND (atom L) (eq level k)) 1)
        ((ATOM L) 0)
        (T (apply #'+ (MAPCAR #' (lambda (aux) ( numberOfNodes aux k (+ 1 level))) L))) ; reprezintă strategia de parcurgere
    )
)

(DEFUN WRAPPER(L k)
    ( numberOfNodes L k -1)
)

;; (setq L '(a (b (c)) (d) (e (f))))
;; (setq k '3)
;; (print (WRAPPER L k))

;; . Define a function that returns the depth of a tree represented as (root list_of_nodes_subtree1 ...
;; list_of_nodes_subtreen)
;; Eg. the depth of the tree (a (b (c)) (d) (e (f))) is 3

(DEFUN depth (L level)
    (COND
        ((null L) 0)
        ((atom L) level)
        (T (apply #'MAX (MAPCAR #' (lambda (aux) ( depth aux (+ 1 level))) L))) ; reprezintă strategia de parcurgere
    )
)

(DEFUN depthWrapper(L)
    ( depth L 0)
)

;; (setq L '(a (b (c)) (d) (e (f))))
;; (print (depthWrapper L))

;; Write a function that produces the linear list of all atoms of a given list, from all levels, and written in
;; the same order. Eg.: (((A B) C) (D E)) --> (A B C D E)

(DEFUN linearizare (L)
    (COND
        ((null L) nil)
        ((ATOM L) (LIST L))
        (t
            (MAPCAN #'linearizare L)
        )
    )
)

;; (setq L '(a (b (c)) (d) (e (f))))
;; (print ( linearizare L))


;; 15. Write a function that reverses a list together with all its sublists elements, at any level.
;; (defun reverseList(l)
;; 	(cond
;; 		((null l) nil)
;; 		( (AND (atom (car l)) (null (cdr l) ) ) l)
;; 		((atom (car l)) (list (reverseList(cdr l)) (car l)) )
;; 		(t (list (reverseList (cdr l) ) (list (reverseList (car l)) ) ) ) 
;; 	)
;; )

;; (setq L '(a (b (c)) (d) (e (f))))
;; (print ( reverseList L))

;; 15. Write a function that reverses a list together with all its sublists elements, at any level.
(DEFUN reverseList (L)
    (COND
        ((null L) nil)
        ((ATOM L) L)
        (t
            (MAPCAR #'reverseList (REVERSE L))
        )
    )
)

(setq L '(a (b (c)) (d) (e (f))))
(print ( reverseList L))
