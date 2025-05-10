#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
 
#define MAX_SIZE 1000
 

typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;
 

void initialize(Stack *s) {
    s->top = -1;
}
 

bool isEmpty(Stack *s) {
    return s->top == -1;
}
 

bool isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}
 

void push(Stack *s, char value) {
    if (isFull(s)) {
        printf("Stack Overflow!\n");
        return;
    }
    s->items[++(s->top)] = value;
}
 

char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        return '\0'; 
    }
    return s->items[(s->top)--];
}
 

char peek(Stack *s) {
    if (isEmpty(s)) {
        return '\0'; 
    }
    return s->items[s->top];
}
 

bool isValid(char *s) {
    Stack st;
    initialize(&st);
 
    for (int i = 0; s[i] != '\0'; i++) {
        char it = s[i];
        if (it == '(' || it == '{' || it == '[') {
            push(&st, it); 
        } else {
            if (isEmpty(&st)) {
                return false; 
            }
            char ch = pop(&st); 
            if (!((it == ')' && ch == '(') || (it == ']' && ch == '[') || (it == '}' && ch == '{'))) {
                return false; 
            }
        }
    }
    return isEmpty(&st);
}
 
int main() {
    char s[] = "()[{}()]"; 
    if (isValid(s)) {
        printf("True\n");
    } else {
        printf("False\n");
    }
    return 0;
}