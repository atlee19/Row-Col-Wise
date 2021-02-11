#include <stdio.h>
#include <sys/time.h>

#define MAX 1000

void loadMatrixFromFile(char file_name[], int matrix[MAX][MAX], int* numRowsPtr, int* numColsPtr);
void dumpToDisplay(int matrix[MAX][MAX], int numRows, int numCols);
int matrixSumRowWise(int matrix[MAX][MAX], int numRows, int numCols);
int matrixSumColWise(int matrix[MAX][MAX], int numRows, int numCols);


int main(int argc, char* argv[])
{
    int numRows=0, numCols=0, sum=0;
    int matrix[MAX][MAX];
    struct timeval tstart, tend;
    double runtime=0.0;

    loadMatrixFromFile("intSmall", matrix, &numRows, &numCols);

    gettimeofday(&tstart, NULL);
    sum = matrixSumRowWise(matrix, numRows, numCols);
    gettimeofday(&tend, NULL);

    runtime = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/1.e6;
    fprintf(stdout, "Sum found processing row-wise: %d\n", sum);
    fprintf(stdout, "Run time = %.8lf\n", runtime);


    gettimeofday(&tstart, NULL);
    sum = matrixSumColWise(matrix, numRows, numCols);
    gettimeofday(&tend, NULL);

    runtime = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/1.e6;
    fprintf(stdout, "Sum found processing col-wise: %d\n", sum);
    fprintf(stdout, "Run time = %.8lf\n", runtime);

    return 0;
}

void loadMatrixFromFile(char file_name[], int matrix[MAX][MAX], int* numRowsPtr, int* numColsPtr){
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

void dumpToDisplay(int matrix[MAX][MAX], int numRows, int numCols){

    fprintf(stdout, "Rows = %d \n", numRows);
    fprintf(stdout, "Columns = %d \n", numCols);

    // printf("%d", matrix[0][2]);

    for(int row=0; row < numRows; row++){
        for(int col=0; col < numCols; col++){
            fprintf (stdout, "%8d", matrix[row][col]);
        }
    }
    fprintf(stdout,"\n");
}

int matrixSumRowWise(int matrix[MAX][MAX], int numRows, int numCols){
    int sum=0;
    for(int row=0; row < numRows; row++){
        for(int col=0; col < numCols; col++){
           sum += matrix[row][col];
        }
    }
    
    return sum;
}

int matrixSumColWise(int matrix[1000][1000], int numRows, int numCols){
    int sum=0;
    for(int col=0; col < numCols; col++){
        for(int row=0; row < numRows; row++){
            sum += matrix[col][row];
        }
    }

    return sum;
}