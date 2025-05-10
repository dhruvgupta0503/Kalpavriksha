#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char* arr[100];
    int top;
} Stack;


void initStack(Stack* stack) {
    stack->top = -1;
}


void push(Stack* stack, char* val) {
    stack->arr[++(stack->top)] = val;
}


char* pop(Stack* stack) {
    return stack->arr[(stack->top)--];
}


int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^');
}


int precedence(char op) {
    if (op == '^') {
        return 3;  // highest precedence
    }
    if (op == '*' || op == '/' || op == '%') {
        return 2;  // medium precedence
    }
    return 1;  // lowest precedence for + and -
}

// Function to check if parentheses are needed based on operator precedence
int needsParentheses(char* left, char* right, char op) {
    // Check if left or right should be wrapped in parentheses due to operator precedence
    int leftPrecedence = (strchr("*/%^", left[0]) != NULL) ? 2 : 1;
    int rightPrecedence = (strchr("*/%^", right[0]) != NULL) ? 2 : 1;

    // If the current operator has higher precedence than the operands, no parentheses needed
    if (precedence(op) > leftPrecedence || precedence(op) > rightPrecedence) {
        return 1; // Parentheses needed
    }
    return 0; // No parentheses needed
}

// Function to convert prefix to infix
char* prefixToInfix(char* prefix) {
    Stack stack;
    initStack(&stack);

    // Reverse the prefix expression for easier processing
    int len = strlen(prefix);

    // Process each character from right to left
    for (int i = len - 1; i >= 0; i--) {
        char c = prefix[i];

        if (isOperator(c)) {
            // Pop two operands from the stack
            char* operand1 = pop(&stack);
            char* operand2 = pop(&stack);

            // Create a new string in the format (operand1 operator operand2)
            char* temp = (char*)malloc(strlen(operand1) + strlen(operand2) + 4); // +4 for operator and parentheses
            if (needsParentheses(operand1, operand2, c)) {
                sprintf(temp, "((%s%c%s))", operand1, c, operand2);
            } else {
                sprintf(temp, "%s%c%s", operand1, c, operand2);
            }

            // Push the new string back onto the stack
            push(&stack, temp);
        } else {
            // If it's an operand, push it onto the stack
            char* operand = (char*)malloc(2);
            operand[0] = c;
            operand[1] = '\0';
            push(&stack, operand);
        }
    }

    // At the end, the stack should contain the final infix expression
    return pop(&stack);
}

int main() {
    char prefix[100];  // Array to hold the user input (prefix expression)

    // Take input from the user
    printf("Enter a prefix expression: ");
    fgets(prefix, sizeof(prefix), stdin);

    // Remove newline character if it's there (from fgets)
    prefix[strcspn(prefix, "\n")] = '\0';

    // Convert the prefix expression to infix
    char* infix = prefixToInfix(prefix);
    printf("Infix expression: %s\n", infix);

    // Clean up the allocated memory
    free(infix);

    return 0;
}
