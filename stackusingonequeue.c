#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int front, rear, size, capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->arr = (int*)malloc(capacity * sizeof(int));
    queue->front = queue->rear = -1;
    queue->size = 0;
    return queue;
}

int isEmpty(Queue* q) {
    return q->size == 0;
}

int isFull(Queue* q) {
    return q->size == q->capacity;
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue overflow\n");
        return;
    }
    if (q->rear == q->capacity - 1) {
        q->rear = -1;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->arr[++q->rear] = value;
    q->size++;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue underflow\n");
        return -1;
    }
    int value = q->arr[q->front++];
    if (q->front == q->capacity) {
        q->front = 0;
    }
    q->size--;
    return value;
}

int front(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->arr[q->front];
}


typedef struct {
    Queue* q;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->q = createQueue(capacity);
    return stack;
}


void push(Stack* s, int value) {
    if (s->q->size == s->q->capacity) {
        printf("Stack overflow\n");
        return;
    }

    int n = s->q->size;
    enqueue(s->q, value);

    
    for (int i = 0; i < n; i++) {
        int temp = dequeue(s->q);
        enqueue(s->q, temp);
    }
}


int pop(Stack* s) {
    if (isEmpty(s->q)) {
        printf("Stack underflow\n");
        return -1;
    }
    return dequeue(s->q);
}


int top(Stack* s) {
    if (isEmpty(s->q)) {
        printf("Stack is empty\n");
        return -1;
    }
    return front(s->q);
}


void freeStack(Stack* s) {
    free(s->q->arr);
    free(s->q);
    free(s);
}

int main() {
    Stack* s = createStack(10);

    push(s, 10);
    push(s, 20);
    push(s, 30);
    push(s, 40);

    printf("Top element is: %d\n", top(s));

    printf("Popped element is: %d\n", pop(s));
    printf("Top element after pop is: %d\n", top(s));

    freeStack(s);

    return 0;
}
