map([[1, 4],[1, 5],[2, 4],[2, 5],[3, 4],[3, 5]]).
colours(['R','G']).

checkBipartite(Pairs):- 
map(Map),colours(Colours),
start(Map, Colours, Pairs).

start(Map, Colours, Pairs):- 
getVertex(Map,AllVertex),
sort(AllVertex,SortedVertex),
colourVertex(SortedVertex,Colours,Pairs),
\+sameColour(Map,Pairs).

getVertex(Map,Vertex):- 
getVertex(Map,Vertex,[]).
getVertex([], Vertex, Vertex).
getVertex([[X,Y]|RestOfMap], Vertex, TempList):- 
getVertex(RestOfMap, Vertex,[X,Y|TempList]).

colourVertex([],_,[]).
colourVertex([V|RestOfVertex],Colours,[[V,C]|RestOfPairs]):-
member(C,Colours), 
colourVertex(RestOfVertex,Colours,RestOfPairs).

sameColour(Map,Pairs):- 
member([J,C],Pairs), 
member([K,C],Pairs), 
neighbors(J,K,Map).

neighbors(J,K,Map):-
member([J,K], Map);
member([K,J], Map).
