#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

    // open files
    FILE * fpWords;
    fpWords = fopen("words.txt", "r"); 

    FILE * fpBin;
    fpBin = fopen("binpattern.txt", "r"); 

    // create step2.pl file
    FILE * fpProlog;
    fpProlog = fopen("step2.pl", "w+"); 
    //-----------------------------------
    
    char lineW[100]; // lines from words.txt

    // read in words.txt
    while(!feof(fpWords)){
        fgets(lineW,sizeof(lineW),fpWords);
        lineW[strcspn(lineW,"\n")] = 0;
        // write whole word into prolog
        fprintf(fpProlog, "word(%s ", lineW);

        // write chars of word into prolog
        for (int i = 0; i < strlen(lineW); i++){
            fprintf(fpProlog, ",%c", lineW[i]);
        }
        // close line of code prolog
        fprintf(fpProlog, ").\n");        
    }
    //-----------------------------------
    // read binpattern.txt
    int row = 100;
    int col = 100;
    int matrix[row][col];

    //char lineBin[100];

    int count = 0;
    while(!feof(fpBin)){
        //fgetc(lineBin, sizeof(lineBin), fpBin);
        
        // get char
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                // check var before storing
                if( SOMETHING != '\n'){
                matrix[i][j] = fgetc(fpBin);
                }
                // if \n 
                else{
                    j++;
                }
            }
        }
        // put in [0][0]
        // move to [0][1]
        // stop at \n
    }

    

    //-----------------------------------
    // find horizontal words
    // length of each word
    // how many horizontal words
    // find vertical words
    // length of each
    // how many vertical words
    //-----------------------------------


    //----------------------------------
    // close files
    fclose(fpWords);
    fclose(fpBin);
    fclose(fpProlog);

    return 0;
}