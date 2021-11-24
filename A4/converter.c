#include <stdio.h>
#include <string.h> // for strcspn

int main()
{
    // open file
    FILE * fp;
    fp = fopen("matrix-test.txt", "r");
    // create variable here to rename pl the same eventaully
    // create prolog file
    FILE * fpProlog;
    fpProlog = fopen("bipartite-test.pl", "w+"); 

    char matrix[100][100]; // adjacency matrix
    char line[100]; // read in lines from file BUFFER

    int count = 0;
    // read in matrix.txt
    while(!feof(fp)){
        fgets(line, sizeof(line), fp);
        line[strcspn(line,"\n")] = 0; // get rid of \n

        // fill 2d matrix var w adjacency matrix
        for (int i = 0; i!= strlen(line); i++) { 
            matrix[count][i] = line[i] - '0';
        }

        count++;
    }

    // // generate prolog code for map based on input file
    // fprintf(fpProlog, "map( ");
    
    printf("count =%d\n", count);
    
    for (int i = 0; i < count; i++){
        for (int j = 0; j < count; j++){
    //         fprintf(fpProlog, "[%d, %d]", matrix[i][j]);
        }       
     }
        
    // // close line of map code prolog
    // fprintf(fpProlog, ").\n"); 

    // rest of prolog code
    /*
    fprintf(fpProlog, "colours(['R','G']).");
    // used to be result
    fprintf(fpProlog, "checkBipartite(Pairs):- map(Map),colours(Colours),start(Map, Colours, Pairs).");

    fprintf(fpProlog, "start(Map, Colours, Pairs):- getVertex(Map,AllVertex),sort(AllVertex,SortedVertex),colourVertex(SortedVertex,Colours,Pairs),\+sameColour(Map,Pairs).");
    
    fprintf(fpProlog, "getVertex(Map,Vertex):- getVertex(Map,Vertex,[]).");
    fprintf(fpProlog, "getVertex([], Vertex, Vertex).");
    fprintf(fpProlog, "getVertex([[X,Y]|RestOfMap], Vertex, TempList):- getVertex(RestOfMap, Vertex,[X,Y|TempList]).");
    
    fprintf(fpProlog, "colourVertex([],_,[]).");
    fprintf(fpProlog, "colourVertex([V|RestOfVertex],Colours,[[V,C]|RestOfPairs]):-member(C,Colours), colourVertex(RestOfVertex,Colours,RestOfPairs).");
    
    fprintf(fpProlog, "sameColour(Map,Pairs):- member([J,C],Pairs), member([K,C],Pairs), neighbors(J,K,Map).");

    fprintf(fpProlog, "neighbors(J,K,Map):-member([J,K], Map);member([K,J], Map).");
    */
}