#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>  

#define MAX 100

typedef struct {
    char *arr[MAX];
    int top;
} Stack;

void init(Stack* s) {
    s->top = -1;
}

void push(Stack* s, char* value) {
    if (s->top == MAX - 1) {
        printf("Stack is full\n");
    } else {
        s->arr[++s->top] = value;
    }
}

char* pop(Stack* s) {
    if (s->top == -1) {
        printf("Stack is empty\n");
        return NULL;
    } else {
        return s->arr[s->top--];
    }
}

int isOperand(char c) {
    return isalpha(c) || isdigit(c);
}

void prefixtoInfix(char* prefix) {
    Stack s;
    init(&s);
    int len = strlen(prefix);

    for (int i = len - 1; i >= 0; i--) {
        char c = prefix[i];

        if (isOperand(c)) {
            char* operand = (char*)malloc(2 * sizeof(char));  // Allocate memory for operand (2 chars: one for char and one for null terminator)
            operand[0] = c;
            operand[1] = '\0';  
            push(&s, operand);
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            char* op1 = pop(&s);
            char* op2 = pop(&s);

           
            char* temp = (char*)malloc(strlen(op1) + strlen(op2) + 4);  // Extra space for parentheses and operator
            sprintf(temp, "(%s%c%s)", op1, c, op2);

            push(&s, temp);
        }
    }

    
    printf("Infix expression: %s\n", pop(&s));
}

int main() {
    char prefix[MAX];
    

    printf("Enter the prefix expression: ");
    scanf("%s", prefix);
    
    
    prefixtoInfix(prefix);

    return 0;
}
