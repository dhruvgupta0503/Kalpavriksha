// Q: Decode a String Encoded with Run-Length Encoding
// Given a compressed string like "3[a]2[bc]", expand it to "aaabcbc".
// Example: 
// Input: "3[a2[c]]"
// Output: "accaccacc"


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    char **data;
    int top;
    int capacity;

}Stack;
Stack* createStack(int capacity){
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->data = (char**)malloc(sizeof(char*) * capacity);
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
    }
    Stack* push(Stack* stack, char* data){
        if(stack->top == stack->capacity - 1){
            stack->capacity *= 2;
            stack->data = (char**)realloc(stack->data, sizeof(char*) * stack->capacity
            );
            }
            stack->data[++stack->top] = data;
            return stack;
            }
int main(){
    


}








#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PATH 1000
#define MAX_CMD_LENGTH 100

void processCommands(char* commands[], int n) {
    char path[MAX_PATH] = "/";  // Initialize the path to the root directory
    char temp[MAX_PATH];
    
    for (int i = 0; i < n; i++) {
        sscanf(commands[i], "cd %s", temp);  // Extract the directory from the command
        
        // If the command is "cd ../", pop the last directory from the path
        if (strcmp(temp, "../") == 0) {
            int len = strlen(path);
            if (len > 1) {
                // Remove the last directory, find the last '/' and set it to '\0'
                for (int j = len - 2; j >= 0; j--) {
                    if (path[j] == '/') {
                        path[j + 1] = '\0';
                        break;
                    }
                }
            }
        }
        // If the command is "cd ./", do nothing
        else if (strcmp(temp, "./") != 0) {
            // Remove the trailing '/' if it exists in temp
            if (temp[strlen(temp) - 1] == '/') {
                temp[strlen(temp) - 1] = '\0';
            }
            // Append the directory to the path
            strcat(path, temp);
            strcat(path, "/");
        }
    }
    
    // Output the final path
    printf("Current working directory: %s\n", path);
}

int main() {
    int n;
    
    // Ask the user how many commands they want to input
    printf("Enter the number of commands: ");
    scanf("%d", &n);
    getchar();  // Consume newline character from input buffer after reading integer
    
    // Allocate memory for the commands
    char* commands[n];
    for (int i = 0; i < n; i++) {
        commands[i] = (char*)malloc(MAX_CMD_LENGTH * sizeof(char));
    }

    // Read commands from the user
    printf("Enter the commands (e.g., 'cd usr/', 'cd ../', 'cd ./'):\n");
    for (int i = 0; i < n; i++) {
        fgets(commands[i], MAX_CMD_LENGTH, stdin);
        // Remove the trailing newline character if present
        commands[i][strcspn(commands[i], "\n")] = '\0';
    }

    // Process the commands
    processCommands(commands, n);
    
    // Free the allocated memory
    for (int i = 0; i < n; i++) {
        free(commands[i]);
    }
    
    return 0;
}


