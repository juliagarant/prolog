% Julia Garant Fall 2021 UWindsor

% Base case displaying correct list but also assigning vars
knightsPath(N,Reversed) :- 
    Move is N*N-1,  
    knightsPath(N,Move,[1/1],Knights),
    reverse(Knights, Reversed).

% Base case
knightsPath(_,0,Knights,Knights).
% Else
knightsPath(N,Move,Past,Knights) :-
    % Past is a list of completed spots on board
   Past = [X/Y|_],
    % Calculates the next move
   next(N,X/Y,A/B),
    % Check if position is (\+ not) part of past moves
   \+ memberchk(A/B,Past),
    % Decrease(each time) total number of moves left
   TotalM is Move-1,
    
    % Recursive call w updated values
   knightsPath(N,TotalM,[A/B|Past],Knights).

% Reverse the list so it will display beginning to end
reverse(List, Rev) :- reverse(List, Rev, []).

reverse([], List, List).
reverse([X/Y|Tail], List, SoFar) :- 
    reverse(Tail, List, [X/Y|SoFar]).

% Next move on NxN board from C/D to E/F
next(N,C/D, E/F) :- 
   nextMove(X,Y), 
   E is C+X, E > 0, E =< N,
   F is D+Y, F > 0, F =< N.

% Possible location additions for next spot on the board
nextMove(1,2).
nextMove(2,1).
nextMove(2,-1).
nextMove(1,-2).
nextMove(-1,-2).
nextMove(-2,-1).
nextMove(-2,1).
nextMove(-1,2).