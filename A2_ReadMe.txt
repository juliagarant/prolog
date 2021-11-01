In my code I have defined map and colour at the top of my program. 

map([[1,2],[1,3],[1,4],[1,5],[2,3],[2,4],[3,4],[4,5]]).
colours(['R','G','B','Y']).

Map is holding essentially the edge set of a map. You can change it to ordered pairs of adjacent sections. Example sections 1 and 2 are adjacent on the map so they are set as an ordered pair.
Colours has string variables of red, green, blue, and yellow but I only used the first character of each for simplicity. They could be replaced with a list of anything. [1,2,3,4,5] would also work you just need to remember their values.

Each predicate has code comments along side in my prolog file.

Call result to run the code and get the desired output of the pairs list
result(Pairs)

Start contains the main recursive steps, get the vertex values, sort the vertex values(removing duplicates),colour the points, check to see if there are any point issues
start(Map, Colours, Pairs)

GetVertex takes in map and sends each value from the list of lists into tempList. 
It then refils map with its values and assigns a value to vertex from tempList.
(1(5 getVertex(Map,Vertex)
(3 getVertex([], Vertex, Vertex). 
(2 (4 getVertex([[X,Y]|RestOfMap], Vertex, TempList)

ColourPoints colours all vertex the same colour to start and then sends to sameColour to find issues 
colourPoints([],_,[])
colourPoints([V|RestOfVertex],Colours,[[V,C]|RestOfPairs])

SameColour checks if regions are in the pairs list with the same colour, then sends it to neighbors to confirm and they send to colourVertex to    
sameColour(Map,Pairs)

Neighbors checks to see if there is an existing pair [J,K] within Map but it also checks for the reverse [K,J]
neighbors(J,K,Map)