/*
14.a
is_in_set(nr,list)
	-false, if list is empty
	-true, if l1 == nr
	-is_in_set(nr,l2....ln) otherwise

remove_from_set(nr,list)
	-[], if list is empty
	-l2....ln ,if nr == l1
	-l1 U remove_from_set(nr,l2....ln)otherwise
	
sets_are_equal(list1,list2)
	-false, if is_in_set(l1,list2) == false
	-true, if list1 is empty and list 2 is empty 
	-false ,first is empty ands -2nd is not
	-sets_are_equal(l2...ln,remove_from_set(l1,list2)),otherwise
			-removes from list 1 and then we remove it from list 2 

14.b
m_element(m,list)
	-l1, if m == 1
	-m_element(m-1,l2..ln)otherwise
    -false, if n == 0 (m is not in list)
    */

is_in_set([First| _ ],Element):-
    First =:= Element.

is_in_set([First| Rest ],Element):-
    First =\= Element,
    is_in_set(Rest,Element).

% is_in_set

remove_from_set([],_,Result):-
    Result =[].

remove_from_set([First | Rest],Element,Result):-
    First=:= Element,
    remove_from_set(Rest,Element,Result).

remove_from_set([First | Rest],Element,[First|Result]):-
    First=\=Element,
    remove_from_set(Rest,Element,Result).

%remove_from_set

sets_are_equal([],[]).%returns true if both lists are empty


sets_are_equal([First | Rest],List2):-
    is_in_set(List2,First),
    remove_from_set(List2,First,Result),
    sets_are_equal(Rest,Result).
%sets_are_equal

%b
th_element(N,[First|_],Result):-
    N=:=1,
    Result=First.


th_element(N,[_|Rest],Result):-
    N=\=1,
    Index is N-1,
    th_element(Index,Rest,Result).

    
    






