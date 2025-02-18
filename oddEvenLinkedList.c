#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Noded*next;
}Node;

Node* createNode(int value){
    Node*newNode=(Node*)malloc(sizeof(Node*));
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}
Node*

