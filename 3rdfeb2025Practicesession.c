#include<stdio.h>
#include <stdlib.h>
#include <string.h>


//  struct Student{

// };

typedef struct Node{
    char name[50];
    int marks;
    int rollNumber;
    struct Node*next;
}Node;

Node* createNode(char name[10],int marks,int rollNumber){
    Node* newNode=(Node*)malloc(sizeof(Node));
   strcpy(newNode->name,name);
    newNode->marks=marks;
    newNode->rollNumber=rollNumber;
    newNode->next=NULL;
    return newNode;
}
void insertAtStart(Node** head,  char name[],int marks,int rollNumber) {
    Node* newNode = createNode(name,marks,rollNumber);
    newNode->next = *head; 
    *head = newNode; 
}
void inserAtEnd(Node** head,char name[],int marks,int rollNumber){
    Node* newNode=createNode(name,marks,rollNumber);
    if(*head==NULL)
    {
        *head=newNode;
    }
        Node* temp=*head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
}

Node *split(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;
 
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
 
    Node *second_half = slow->next;
    slow->next = NULL;
 
    return second_half;
}
Node* mergeLists(Node* left, Node* right) {
    if (left == NULL) return right;
    if (right == NULL) return left;

    if (left->marks > right->marks || (left->marks == right->marks && left->rollNumber < right->rollNumber)) {
        left->next = mergeLists(left->next, right);
        return left;
    } else {
        right->next = mergeLists(left, right->next);
        return right;
    }
}

Node* mergeSort(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head; 
    }

    Node* secondHalf = splitList(head);

   
    head = mergeSort(head);
    secondHalf = mergeSort(secondHalf);

   
    return mergeLists(head, secondHalf);
}





void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("Name: %s, Marks: %d, Roll Number: %d\n", temp->name, temp->marks, temp->rollNumber);
        temp = temp->next;
    }
}

int main(){
     int n;
    scanf("%d",&n);
    Node* head=NULL;
    for(int i=0;i<n;i++){
        char name[50];
        int marks,rollNumber;
        scanf("%d%d%d",name,&marks,&rollNumber);
        inserAtEnd(&head,name,marks,rollNumber);
    }
    Node* temp=head;
   
  
    
    
    // for (int i = 0; i < n; i++) {
    //     scanf("%s %d %d", students[i].name, &students[i].marks, &students[i].roll_number);
    // }
    // compare()
}