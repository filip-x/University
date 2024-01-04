getElement(0, 0) :- !.

getElement(N, R) :-
    N1 is N - 1,
    getElement(N1, R).

getElement(N, N).
   

decomposition(0, [0], 1) :- !.

decomposition(0, [], I) :- !.

decomposition(N, [I1 | R1], I) :-
    I1 is I - 1,
    N1 is N - I1,
    N1 >= 0,
    I1 >= 0,
    decomposition(N1, R1, I1).

decomposition(N, [E | R]) :-
    getElement(N, E),
    N1 is N - E,
    decomposition(N1, R, E).






