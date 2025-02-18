#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int *array;
    int top;   
    int capacity;  
} Stack;

void initStack(Stack *stack, int capacity) {
    stack->capacity = capacity;
    stack->top = -1; 
    stack->array = (int *)malloc(capacity * sizeof(int));  
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

int isFull(Stack *stack) {
    return stack->top == stack->capacity - 1;
}
void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->array[++stack->top] = value;
}

int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack->array[stack->top--];
}
int peek(Stack *stack) {
    if (isEmpty(stack)) {
        return -1;
    }
    return stack->array[stack->top];
}
void nextGreaterElement(int *a, int n) {
    int *result = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        result[i] = -1;
    }
    Stack stack;
    initStack(&stack, n); 

    for (int i = 0; i < 2 * n; i++) {
        int current = i % n; 

        
        while (!isEmpty(&stack) && a[peek(&stack)] < a[current]) {
            int index = pop(&stack); 
            result[index] = a[current];  
        }

       
        if (i < n) {
            push(&stack, current);
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    free(result);
    free(stack.array);  
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    nextGreaterElement(a, n);

    return 0;
}
