#include  <stdio.h>
#include <stdlib.h>
#define MAX 10
typedef struct {
    int arr[MAX];
    int front,rear;
}Queue;

void init(Queue* q){
    q->front =- 1;
    q->rear = -1;
}
int isFull(Queue *q){
    if(q->rear == MAX-1);
    return 1;
}
int isEmpty(Queue *q){
    if(q->front == -1 && q->rear == -1);
    return 1;

}
void Enqueue(Queue *q,int value){
    if(isFull(q)){
        printf("Queue is full\n");
        return ;
        }
        if(isEmpty(q)){
            q->front = 0;
            q->rear = 0;
            }
            q->arr[q->rear] = value;
            q->rear = q->rear + 1;

}
int dequeue(Queue *q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return ;
    }
    int dequeuedValued=q->arr[q->front];
    q->front = q->front + 1;
    return dequeuedValued;

}

void display(Queue*q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
    }
    for(int i=q->front;i<=q->rear;i++){
        printf("%d",q->arr);
    }
    printf("\n");
}

int main(){
    Queue q;
    init(&q);
    Enqueue(&q, 1);
    Enqueue(&q, 2);
    Enqueue(&q, 3);
    Enqueue(&q, 4);
    Enqueue(&q, 5);
    display(&q);
    dequeue(&q);
    display(&q);

    return 0;
}