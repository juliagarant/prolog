#include <stdio.h>
#include <string.h> // for strcspn
#include <stdbool.h> // for bool

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

    // generate prolog code for map based on input file
    fprintf(fpProlog, "map([");
    
    printf("count =%d\n", count);

    bool pair = false;
    
    for (int i = 0; i < count; i++){
        for (int j = i+1; j < count; j++){
            if(matrix[i][j] == 1){ 
                if(!pair){ // first occurrance of pair
                    pair = true;
                }else{
                    fprintf(fpProlog, ","); 
                }
                fprintf(fpProlog,"[%d, %d]", i+1, j+1);
            }
        }       
     }
     
    // close line of map code prolog
    fprintf(fpProlog, "]).\n"); 

    // rest of prolog code
    
    fprintf(fpProlog, "colours(['R','G']).\n");
    // used to be result
    fprintf(fpProlog, "\ncheckBipartite(Pairs):- \nmap(Map),colours(Colours),\nstart(Map, Colours, Pairs).\n");

    fprintf(fpProlog, "\nstart(Map, Colours, Pairs):- \ngetVertex(Map,AllVertex),\nsort(AllVertex,SortedVertex),\ncolourVertex(SortedVertex,Colours,Pairs),\n\\+sameColour(Map,Pairs).\n");
    
    fprintf(fpProlog, "\ngetVertex(Map,Vertex):- \ngetVertex(Map,Vertex,[]).\n");
    fprintf(fpProlog, "getVertex([], Vertex, Vertex).\n");
    fprintf(fpProlog, "getVertex([[X,Y]|RestOfMap], Vertex, TempList):- \ngetVertex(RestOfMap, Vertex,[X,Y|TempList]).\n");
    
    fprintf(fpProlog, "\ncolourVertex([],_,[]).\n");
    fprintf(fpProlog, "colourVertex([V|RestOfVertex],Colours,[[V,C]|RestOfPairs]):-\nmember(C,Colours), \ncolourVertex(RestOfVertex,Colours,RestOfPairs).\n");
    
    fprintf(fpProlog, "\nsameColour(Map,Pairs):- \nmember([J,C],Pairs), \nmember([K,C],Pairs), \nneighbors(J,K,Map).\n");

    fprintf(fpProlog, "\nneighbors(J,K,Map):-\nmember([J,K], Map);\nmember([K,J], Map).\n");
    
}