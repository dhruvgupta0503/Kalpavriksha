#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct stack {
    Node* top; 
    int size;    
} Stack;

Stack *createStack() {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->top = NULL;  
    s->size = 0;    
    return s;
}

int isEmpty(Stack *s) {
    return s->top == NULL; 
}

void push(Stack *s, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node)); 
    newNode->data = value;  
    newNode->next = s->top; 
    s->top = newNode; 
    s->size++; 
    printf("Pushed %d to the stack\n", value);
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1; 
    }
    Node* temp = s->top; 
    int poppedValue = temp->data; 
    s->top = s->top->next; 
    free(temp); 
    s->size--; 
    printf("Popped %d from the stack\n", poppedValue);
    return poppedValue;
}

int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Cannot peek.\n");
        return -1;  
    }
    return s->top->data;  
}

void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return;
    }
    Node* current = s->top;  
    while (current != NULL) {
        printf("%d -> ", current->data);  
        current = current->next;  
    }
    printf("NULL\n");  
}

int main() {
    Stack *myStack = createStack();  
    
    push(myStack, 10);
    push(myStack, 20);
    push(myStack, 30);
    push(myStack, 40);

    display(myStack);
    
    printf("Peek: %d\n", peek(myStack));

    pop(myStack);
    pop(myStack);
    
    display(myStack);
    
    printf("Peek: %d\n", peek(myStack));

    pop(myStack);
    pop(myStack);

    pop(myStack);
    
    free(myStack);  
    
    return 0;
}
