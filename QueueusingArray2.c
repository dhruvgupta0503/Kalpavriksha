#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100
typedef struct {
    int item[MAX];
    int top;
}Stack;


void initialize(Stack *s){
    s->top= -1;
}

bool isEmpty(Stack *s){
    return s->top==-1;
}
 bool isFull(Stack *s){
    return s->top==MAX-1;
 }

 void push(Stack *s,int value){
    s->top=s->top+1;
    s->item[s->top]=value;
 }
 int pop(Stack *s){
    if(isEmpty(s)){
        return -1;
    }
    int poppedValue=s->item[s->top];
    return poppedValue;
 }

 void display(Stack *s){
    if(isEmpty(s)){
        return;
    }
    for(int i=0;i<=s->top;i++){
        printf("%d ",s->item[i]);

    }
    printf("/n");
 }
 int main(){
    Stack s;
    initialize(&s);
    
 }