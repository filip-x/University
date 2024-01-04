fact1(0,1).
fact1(N,F):-
    N>0,N1 is N-1, fact1(N1,F1),F is N*F1.
    % n > 0 and n1 = n-1 and fact(n1,f1) and f  = n*f1

go1:- fact1(3,6).



                        