#include <stdio.h>
#define MAX 100

void generateSnakeMatrix(int matrix[MAX][MAX], int rows, int cols) {
    int value = 1;  
    for (int i = 0; i < rows; i++) {
        if (i % 2 == 0) {
            
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = value++;
            }
        } else {
          
            for (int j = cols - 1; j >= 0; j--) {
                matrix[i][j] = value++;
            }
        }
    }
}

void printMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;
    int matrix[MAX][MAX];

   
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

   
    generateSnakeMatrix(matrix, rows, cols);

   
    printf("Snake Pattern Matrix:\n");
    printMatrix(matrix, rows, cols);

    return 0;
}
