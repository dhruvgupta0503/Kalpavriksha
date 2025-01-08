#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isVowel(char ch) {
    ch = tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

void findLongestName(int rows, int cols, char names[rows][cols][51], char *longestName) {
    int maxLength = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int currentLength = strlen(names[i][j]);
            if (currentLength > maxLength) {
                maxLength = currentLength;
                strcpy(longestName, names[i][j]);
            }
        }
    }
}

int main() {
    int rows, cols;
    printf("Enter number of rows (1-10): ");
    scanf("%d", &rows);
    while (rows < 1 || rows > 10) {
        printf("Invalid input. Enter number of rows (1-10): ");
        scanf("%d", &rows);
    }

    printf("Enter number of columns (1-10): ");
    scanf("%d", &cols);
    while (cols < 1 || cols > 10) {
        printf("Invalid input. Enter number of columns (1-10): ");
        scanf("%d", &cols);
    }

    char names[rows][cols][51]; 
    int vowelCount = 0;
    char longestName[51] = "";

    
    printf("Enter the names:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Name at (%d,%d): ", i, j);
            scanf("%s", names[i][j]);

            
            if (isVowel(names[i][j][0])) {
                vowelCount++;
            }
        }
    }

   
    findLongestName(rows, cols, names, longestName);

  
    printf("\nThe 2D array of names is:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%s ", names[i][j]);
        }
        printf("\n");
    }

   
    printf("Number of names starting with a vowel: %d\n", vowelCount);
    printf("The longest name: %s\n", longestName);

    return 0;
}
