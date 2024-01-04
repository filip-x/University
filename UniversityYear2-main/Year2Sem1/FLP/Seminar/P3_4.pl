getElement([H | T], H, T).
getElement([_ | T], E, R) :-
    getElement(T, E, R).

sublist2(_, _, []).

sublist2(Last, [H | T], [H | R]) :-
    H > Last,
    Last2 is H,
    sublist2(Last2, T, R).

sublist(L, [E | R]) :-
    getElement(L, E, Rest),
    sublist2(E, Rest, R).