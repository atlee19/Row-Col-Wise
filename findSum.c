#include <stdio.h>


void loadMatrixFromFile(char file_name[], int matrix[1000][1000], int* numRowsPtr, int* numColsPtr);
void dumpToDisplay(int matrix[1000][1000], int numRows, int numCols);


int main(int argc, char* argv[])
{
    int numRows=0, numCols=0;
    int matrix[1000][1000];

    loadMatrixFromFile("intSmall", matrix, &numRows, &numCols);
    dumpToDisplay(matrix, numRows, numCols);

    return 0;
}

void loadMatrixFromFile(char file_name[], int matrix[1000][1000], int* numRowsPtr, int* numColsPtr){
    //open file
    FILE *fp;
    fp = fopen(file_name, "r");

    if(fp == NULL){ //not fan of null 
        fprintf(stderr, "Error: Failed to open provide the file name\n");
        return;
    } 

    //read in matrix size
    fscanf(fp, "%i", numRowsPtr);
    fscanf(fp, "%i", numColsPtr);

    //read in the rest of the matrix contents 
    for(int row=0; row < *numRowsPtr; row++){
        for(int col=0; col < *numColsPtr; col++){
            fscanf(fp, "%d", &matrix[row][col]);
        }
    }
   

    fclose(fp);
  
    return;
    
}

void dumpToDisplay(int matrix[1000][1000], int numRows, int numCols){

    fprintf(stdout, "Rows = %d \n", numRows);
    fprintf(stdout, "Columns = %d \n", numCols);

    // printf("%d", matrix[0][2]);

    for(int row=0; row < numRows; row++){
        for(int col=0; col < numCols; col++){
            fprintf (stdout, "%10d", matrix[row][col]);
        }
    }
    fprintf(stdout,"\n");
}