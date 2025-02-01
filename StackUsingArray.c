#include <stdio.h>
#include <stdlib.h>
#define MAX 5
struct Stack{
    int arr[MAX];
    int top;
};
void initStack(struct Stack*s){
    s->top = -1;
}
int isFull(struct Stack*s){
    return s->top==MAX-1;
}
int isEmpty(struct Stack*s){
    return s->top== -1;
}
void push(struct Stack*s,int value){
    s->arr[++s->top]=value;

}
int pop(struct Stack* s){
    int poppedValue=s->arr[s->top--];
    return poppedValue;
}




int main() {
    struct Stack myStack;
    initStack(&myStack);  

   
    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);
    push(&myStack, 40);
    push(&myStack, 50);
    push(&myStack, 60); 

    
    pop(&myStack);
    pop(&myStack);
    pop(&myStack);
    pop(&myStack);
    pop(&myStack);
    pop(&myStack);  

    return 0;
}