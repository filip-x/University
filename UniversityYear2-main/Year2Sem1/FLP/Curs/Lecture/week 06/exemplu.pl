% candidat(L:list, E:integer)
% parametrii: lista, elementul rezultat
% (i, o) - nedeterminist
candidat([E|_], E) :- E mod 2 =:= 1.
candidat([_|T], E) :- candidat(T, E).

% submSP(L:list, S:list)
% parametrii: lista, submultimea
% (i, o) - nedeterminist
submSP(L, S) :-
	candidat(L, E),
	subm_aux(L, S, [E], E).

% submSP_aux(L:list, S:list, Col: list, Sum:integer)
% parametrii: lista, submultimea rezultat, colectoarea, suma din colectoare
% (i, o, i, i) - nedeterminist

subm_aux(_, Col, Col, Sum) :- Sum mod 2 =:=0.
% subm_aux(_, S, Col, Sum) :- Sum mod 2 =:=0, S = Col.
subm_aux(L, S, [H|Col], Sum) :-
	candidat(L, E),
	E < H,
	SumN is Sum + E,
	subm_aux(L, S, [E|[H|Col]], SumN).

