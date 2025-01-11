#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void mergeMatrices(char ***matrix1, char ***matrix2, char ***mergeMatrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            strcpy(mergeMatrix[i][j], matrix1[i][j]);  
            strcat(mergeMatrix[i][j], matrix2[i][j]); 
        }
    }
}


void printMatrix(char ***matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%s ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;

    
    printf("Enter the number of rows and columns: ");
    scanf("%d%d", &rows, &cols);

    
    char ***matrix1 = (char ***)malloc(rows * sizeof(char **));
    char ***matrix2 = (char ***)malloc(rows * sizeof(char **));
    char ***mergeMatrix = (char ***)malloc(rows * sizeof(char **));

    for (int i = 0; i < rows; i++) {
        matrix1[i] = (char **)malloc(cols * sizeof(char *));
        matrix2[i] = (char **)malloc(cols * sizeof(char *));
        mergeMatrix[i] = (char **)malloc(cols * sizeof(char *));
        for (int j = 0; j < cols; j++) {
            matrix1[i][j] = (char *)malloc(100 * sizeof(char));
            matrix2[i][j] = (char *)malloc(100 * sizeof(char));
            mergeMatrix[i][j] = (char *)malloc(200 * sizeof(char)); 
        }
    }

   
    printf("Enter the elements of the first matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%s", matrix1[i][j]);
        }
    }


    printf("Enter the elements of the second matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%s", matrix2[i][j]);
        }
    }

 
    mergeMatrices(matrix1, matrix2, mergeMatrix, rows, cols);

   
    printf("Merged Matrix:\n");
    printMatrix(mergeMatrix, rows, cols);

   
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            free(matrix1[i][j]);
            free(matrix2[i][j]);
            free(mergeMatrix[i][j]);
        }
        free(matrix1[i]);
        free(matrix2[i]);
        free(mergeMatrix[i]);
    }
    free(matrix1);
    free(matrix2);
    free(mergeMatrix);

    return 0;
}
