#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    char data;
    struct Node* next;
}Node;

Node* createNode(char value){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}
void insertAtStart(Node** head, int value) {
    Node* newNode = createNode(value); 
    newNode->next = *head;
    *head = newNode; 
}
Node* Findmiddle(Node* head){
    Node* slow=head;
    Node* fast=head;
while(fast!=NULL && fast->next!=NULL){
    slow=slow->next;
    fast=fast->next->next;
}
return slow;
}

Node* reverseList(Node* head){
    Node* prev=NULL;
    Node* current=head;
    Node* next=NULL;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;

    }
    return prev;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%c -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

bool isPalindrome(Node* head){
    if(head==NULL || head->next==NULL){
        return true;
    }
    Node* middle=Findmiddle(head);
    Node* secondHalf=reverseList(middle);
    Node* firstHalf=head;
    while(secondHalf!=NULL){
        if(firstHalf->data!=secondHalf->data){
            return false;
        }
        firstHalf=firstHalf->next;
        secondHalf=secondHalf->next;
    }
    return true;
}

int main(){
    Node* head=NULL;
   insertAtStart(&head,'a');
     insertAtStart(&head,'b');
    //   insertAtStart(&head,'d');
    //    insertAtStart(&head,'a');
    //     insertAtStart(&head,'p');
         if(isPalindrome(head)){
            printf("TRUE");
         }
         else {
            printf("False");
         }


return 0;

}
