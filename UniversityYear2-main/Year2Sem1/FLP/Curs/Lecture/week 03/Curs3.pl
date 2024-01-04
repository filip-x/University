adaug(Elem,[],[Elem]).% conditia de iesire 

adaug(Elem,[H|T],[H|Rest]):-% bagam initial elem si apoi adaugam head-ul primul dupa care punem restul adica punem elementele asa cum sunt ele
                            %daca nu faceam cu head asa ne punea invers numerele
    adaug(Elem,T,Rest).

invers([],[]).

invers([H|T],Rez):-
    invers(T,L),
    adaug(H,L,Rez).


lista_para([],[]).

lista_para([H|T],[H|Rez]):-
    H mod 2 =:= 0,
    lista_para(T,Rez).

lista_para([H|T],Rez):-
    H mod 2 =:= 1,
    lista_para(T,Rez).
    

concat([],[],[]).


concat([H|T],L2,[H|R]):-
    concat(T,L2,R).

concat([],[H|T],[H,R]):-
    concat([],T,R).

