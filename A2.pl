% Julia Garant Fall 2021 104987469
% FACTS 
% Map has 5 sections
map([[1,2],[1,3],[1,4],[1,5],[2,3],[2,4],[3,4],[4,5]]).
colours(['R','G','B','Y']).

% RULE Call result to run the code and get the desired output
result(Pairs):-
    map(Map),
    colours(Colours),    
    start(Map, Colours, Pairs).

% RULE Start contains the main recursive steps
start(Map, Colours, Pairs):-
    % find points
    getVertex(Map,AllVertex),
    sort(AllVertex,SortedVertex),
    % colour points
    colourVertex(SortedVertex,Colours,Pairs),
	% check for issues between points
    \+sameColour(Map,Pairs). 


% RULE Pass in map and 2 empty lists 
% (1 
% Send back full map and newly full vertex
% (5
getVertex(Map,Vertex) :- 
    getVertex(Map,Vertex,[]).
% When Map is empty, vertex and temp list should be equal 
% (all points have been collected, set vertex to temp list)
% (3
getVertex([], Vertex, Vertex). 
% Else put points from map into one big list with repeating values
% (2 
% Refil Map with values
% (4
getVertex([[X,Y]|RestOfMap], Vertex, TempList) :- 
    getVertex(RestOfMap, Vertex,[X,Y|TempList]).


% RULE Base case of every vertex being assigned the same colour
% Creates an empty list to fill recursively with [vertex,colour]
colourVertex([],_,[]).
    
% Takes in vertex, colours, pairs
% Check to see if colour in pairs is in colours list, 
% eventually colouring every vertex the same colour then adjusting
colourVertex([V|RestOfVertex],Colours,[[V,C]|RestOfPairs]):-
    member(C,Colours), 
    colourVertex(RestOfVertex,Colours,RestOfPairs). 
    

% RULE check if regions are in the pairs list with the same colour    
sameColour(Map,Pairs):- 
     member([J,C],Pairs), % Check if region 1 has colour C
     member([K,C],Pairs), % Check if region 2 has colour C
     neighbors(J,K,Map). % Check if regions are adjacent

% RULE j and k are neighbors if 
neighbors(J,K,Map):-
    member([J,K], Map); % if map contains j,k relationship
    member([K,J], Map). % or if k,j relationship




