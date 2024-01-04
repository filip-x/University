/* Predicate which gives me an element from the list, and the list without that one element */
getElement([H | T], H, T).

getElement([H | T], E, [H | R1]) :-
    getElement(T, E, R1).

/* Predicate which gives me an element from the list, and the rest of the list after it */
getElement2([H | T], H, T).

getElement2([_ | T], E, R) :-
    getElement2(T, E, R).

/* Sublist algorithm */
sublist(_, 0, []).

sublist(L, N, R) :-
    not(N = 0),
    N1 is N - 1,
    getElement2(L, E, Rest),
    sublist(Rest, N1, R1),
    R = [E | R1].

/* Get all solutions in a list */
back(L, N, A) :-
    findall(R, sublist(L, N, R), A).