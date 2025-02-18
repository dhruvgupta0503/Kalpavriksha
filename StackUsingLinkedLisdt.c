#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void push(Node** top, int value) {
    Node* newNode = createNode(value);
    newNode->next = *top;
    *top = newNode;
}

int pop(Node **top) {
    if (*top == NULL) {
        return -1;
    }
    Node* temp = *top;
    int data = temp->data;
    *top = temp->next;
    free(temp);
    return data;
}

int peek(Node* top) {
    if (top == NULL) {
        return -1;
    }
    return top->data;
}

int main() {
    Node* stack = NULL;  // Initialize an empty stack

    // Push some values onto the stack
    printf("Pushing 10 onto the stack.\n");
    push(&stack, 10);
    
    printf("Pushing 20 onto the stack.\n");
    push(&stack, 20);
    
    printf("Pushing 30 onto the stack.\n");
    push(&stack, 30);

    // Peek the top value
    printf("Top of the stack: %d\n", peek(stack));

    // Pop values from the stack
    printf("Popped: %d\n", pop(&stack));  // Should print 30
    printf("Popped: %d\n", pop(&stack));  // Should print 20

    // Peek the new top value
    printf("Top of the stack after pops: %d\n", peek(stack));  // Should print 10

    // Pop the last element
    printf("Popped: %d\n", pop(&stack));  // Should print 10

    // Try to pop from an empty stack
    printf("Popped from empty stack: %d\n", pop(&stack));  // Should print -1

    // Final state of the stack (should be empty now)
    printf("Top of the stack after emptying: %d\n", peek(stack));  // Should print -1

    return 0;
}
