% 13. The list a1, ..., an is given and it consists of distinct integers. Write a predicate to determine all subsets
% with aspect of "mountain" (a set has a "mountain" aspect if the elements increase to a certain point
% and then decrease).

%part is for asc or des
%max has to be smaller then the first elem in the list


% mountain(l1...ln, max, part)
%    true n=0 and part = 2, 
%    mountain(l2...ln,l1,part), If part=1 and l1>max,  
%    mountain(l2...ln,l1,part+1), If part=1 and l1<max,  
%    mountain(l2...ln,l1,part), If l1<max, part=2  
%    False, otherwise 

% generate_subset(l1...ln)
%    l1 U generate_subset(l2...ln),
%    generate_subset(l2...ln)

% mount_set(l1..ln)
%    r, r=generate_subset(l1...ln) if r is a mountain



%mountain(L: List, M: Integer, P: Integer) 
%mountain(I,I,I) 


%final check if the list is empty and it was a mountain
mountain([], _, 2). 

%if it goes up or down 
mountain([H|T], M, P) :- 
    ((P=1,H>M);(P=2, H < M)), 
    mountain(T, H, P). 

%if it should change direction
mountain([H|T], M, P) :- 
    P=1,H < M,
    P2 is P+1, 
    mountain(T, H, P2). 

%it will give false if the list is empty and part is still 1
%it will give false part is allready 2 and it starts increasing


%check if a subset is a mountain
%mount_set(I,O)
%it generates and shows all the subsets 
mount_set(L, R):-
    generate_subset(L, R),
    mountain(R, 0, 1).

%generate_subset(I,O)
%the final when the first list is empty  and we initialize the rez with the empty list
generate_subset([], []).

%we add the current element
generate_subset([H|T], [H|T2]):-
    generate_subset(T, T2).

%we don't add the current element
generate_subset([_|T], T2):-
    generate_subset(T, T2).

%mount_set([1,3,5,4,2],R)
%mount_set([],R)