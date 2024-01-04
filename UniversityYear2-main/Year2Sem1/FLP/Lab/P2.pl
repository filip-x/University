
/*

merge_two_s_lists(list1,list2)
{
[], if both lists are empty
list1,if list2 is empty
list2,if list1 is empty 
l1_1 U merge_two_s_lists(l1_2...l1_n, list2),if l1_1 < l2_1
l2_1 U merge_two_s_lists(list1, l2_2....l2_n),if l2_1 < l1_1
merge_two_s_lists(list1,l2_2....l2_n),if l1_1 = l2_1
}
*/

%merge_two_s_lists (i,i,o)flow model
% Merge two sorted lists with removing the double values

merge_two_s_lists([],[],Rez):-
    Rez=[].

merge_two_s_lists([Head|Rest],[],[Head|Rez]):- 
    merge_two_s_lists(Rest,[],Rez).

merge_two_s_lists([],[Head|Rest],[Head|Rez]):- 
    merge_two_s_lists([],Rest,Rez).

merge_two_s_lists([Head|Rest],[Head2|Rest2],Rez):- 
    Head=:=Head2,
    merge_two_s_lists([Head|Rest],Rest2,Rez).

merge_two_s_lists([Head|Rest],[Head2|Rest2],[Head|Rez]):- 
    Head<Head2,
    merge_two_s_lists(Rest,[Head2|Rest2],Rez).

merge_two_s_lists([Head|Rest],[Head2|Rest2],[Head2|Rez]):- 
    Head>Head2,
    merge_two_s_lists([Head|Rest],Rest2,Rez).

%For a heterogeneous list, formed from integer numbers and list of numbers,
%  merge all sublists with removing the double values.

/*


remove_from_set(nr,list)

	-[], if list is empty
	-remove_from_set(nr,l2....ln) ,if nr == l1
    -l1 U remove_from_set(nr,l2....ln)otherwise
    
delete_duplicates(list)-where we delete from set if there are duplicates
    -[],if list is empty
    -l1 U delete_duplicates(remove_from_set(l1,l2..ln))otherwise

is_list(element) -we only want to see if a element is a list
    TRUE,if element is alist
    FALSE,if element is not a list


merge_hetero(list1)
    -[], if list1 is empty
    -merge_hetero(l2...ln),if l1 is not a list
    -(merge_two_s_lists(l1,merge_heter(l2...ln))),l1 is a list 


merge() - we only call the functions
[1, [2, 3], 4, 5, [1, 4, 6], 3, [1, 3, 7, 9, 10], 5, [1, 1, 11], 8]
Rez=[1, 2, 3, 4, 6, 7, 9, 10, 11]
merge(i,o)-flow model
*/


remove_from_set([],_,Result):-
    Result =[].

remove_from_set([First | Rest],Element,Result):-
    First=:= Element,
    remove_from_set(Rest,Element,Result).

remove_from_set([First | Rest],Element,[First|Result]):-
    First=\=Element,
    remove_from_set(Rest,Element,Result).

delete_duplicates([],[]).

delete_duplicates([Head|Rest],[Head|Rez]):-
    remove_from_set(Rest,Head,Rez2),
    delete_duplicates(Rez2,Rez).
    

is_list([_|_]).

merge_hetero([],Rez):-
    Rez=[].

merge_hetero([Head|Rest],Rez):-
    not(is_list(Head)),
    merge_hetero(Rest,Rez).

merge_hetero([Head|Rest],Rez):-
    is_list(Head),
    merge_hetero(Rest,Rez2), % not result
    merge_two_s_lists(Head,Rez2,Rez).

merge(List, Result):-
    merge_hetero(List, Result2),
    delete_duplicates(Result2, Result).
