//linked list 
#include<stdio.h>
#include <stdlib.h>
typedef struct{
    int data;
    struct node* next;
}Node;

Node *createList(int value){
    Node *newNode=(Node*)malloc(sizeof(Node*));
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}
void insertAtStart(Node** head,int value){
    Node *newNode = createList(value);
    if(head == NULL){
        head = newNode;
        }
    newNode->next = *head;
     head=newNode;
}
void insertAtEnd(Node** head,int value){
    Node* newNode=createList(value);
    if(*head==NULL){
        *head=newNode;
        return;
    }
    Node *temp=*head;
    while(temp!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;

}


// hashmap