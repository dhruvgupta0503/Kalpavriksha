#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} s;

typedef struct Queue {
    struct Node* front;
    struct Node* rear;
} q;

void initializeQueue(q* q) {
    q->front = NULL;
    q->rear = NULL;
}

void enqueue(q* q, int data) {
    s* temp = (s*)malloc(sizeof(s));
    temp->data = data;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

int dequeue(q* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    int data = q->front->data;
    s* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return data;
}

void display(q* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    s* temp = q->front;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next; 
    }
    printf("NULL\n");  
}

void freeQueue(q* q) {
    s* temp;
    while (q->front != NULL) {
        temp = q->front;
        q->front = q->front->next;
        free(temp);
    }
    q->rear = NULL;
}

int main() {
    q* q1 = (q*)malloc(sizeof(q));
    initializeQueue(q1);

    enqueue(q1, 10);
    enqueue(q1, 20);
    enqueue(q1, 30);
    enqueue(q1, 40);

    display(q1);  

    freeQueue(q1);  

    return 0;
}
