#include <stdio.h>
#define MAX 100

// Function to replace all occurrences of 'old' with 'new' in the character matrix
void ReplaceCharacter(char matrix[MAX][MAX], char old, char new, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (matrix[i][j] == old) {
                matrix[i][j] = new;  // Replace old character with new character
            }
        }
    }
}

int main() {
    int row, col;
    char mat[MAX][MAX];

    // Input dimensions of the matrix
    scanf("%d %d", &row, &col);

    // Input character matrix
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf(" %c", &mat[i][j]);  // Note the space before %c to skip any whitespace
        }
    }

    // Replace all occurrences of 'a' with 'b'
    ReplaceCharacter(mat, 'a', 'b', row, col);

    // Output the updated matrix
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%c ", mat[i][j]);
        }
        printf("\n");  // Print each row on a new line
    }

    return 0;
}
