#include <stdio.h>
#include <stdlib.h>

#define M 3
#define N 3


void print(int** matrix, int matrixSize, int colSize){
    printf("\n[\n");
    for(int i = 0; i < matrixSize; i++){
        printf("[ ");
        for(int j = 0; j < colSize; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("]\n");
    }
    printf("]\n");
}


void rotate(int** matrix, int matrixSize, int* matrixColSize){

    int** temp = (int**) malloc(matrixSize * sizeof(int*));
    for(int i = 0; i < matrixSize; i++){
        temp[i] = (int*) calloc(matrixSize, sizeof(int));
    }

    for(int i = 0; i < matrixSize; i++){
        for(int j = 0; j < matrixSize; j++){
            temp[j][matrixSize - (i + 1)] = matrix[i][j];
        }
    }

    for(int i = 0; i < matrixSize; i++){
        for(int j = 0; j < matrixSize; j++){
            matrix[i][j] = temp[i][j];
        }
    }
}


int main(){

    int** matrix = (int**) malloc(M * sizeof(int*));
    for(int i = 0; i < M; i++){
        matrix[i] = (int*) malloc(N * sizeof(int));
    }

    matrix[0][0] = 1;
    matrix[0][1] = 2;
    matrix[0][2] = 3;
    matrix[1][0] = 4;
    matrix[1][1] = 5;
    matrix[1][2] = 6;
    matrix[2][0] = 7;
    matrix[2][1] = 8;
    matrix[2][2] = 9;

    int temp[] = {3, 3, 3};

    printf("Before rotation : \n");
    print(matrix, M, N);
    rotate(matrix, M, temp);
    printf("\nAfter rotation:\n");
    print(matrix, M, N);

    return 0;
}