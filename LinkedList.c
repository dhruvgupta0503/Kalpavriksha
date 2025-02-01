#include<stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node*next;
}Node;
Node* createNode(int value){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}
void insertAtStart(Node** head,int value){
    Node* newNode=createNode(value);
    newNode->next=*head;
    *head=newNode;
}
void insertAtEnd(Node** head,int value){
    Node* newNode=createNode(value);
    if(*head==NULL){
        *head=newNode;
        return;
    }
    Node* temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
}