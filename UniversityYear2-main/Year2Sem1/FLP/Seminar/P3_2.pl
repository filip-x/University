/* get element and rest of the list after the element */
getElement([H | T], H, T).
getElement([_ | T], E, R) :-
    getElement(T, E, R).


/* check coliniar */
valid([_]).

valid([_, _]).

valid([[A, B], [M, N], [X, Y] | _]) :-
    A * (N - Y) + M * (Y - B) + X * (B - N) =:= 0.

subset(_, _, []). 

subset(L, N, R) :-
    not(N = 0),
    N1 is N - 1,
    getElement(L, E, Rest),
    subset(Rest, N1, R1),
    R = [E | R1],
    valid(R).

test(R) :- subset([[1, 1], [2, 2], [3, 3], [3, 4]], 4, R).