#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Node{
    char name[101];
    int ph;
    struct Node* next;
}Node;

Node* head=NULL;
Node* tail=NULL;
void push(char name[],int phone){
    Node* temp=head;
    while(temp)
    {
        if(strcmp(name,temp->name)==0){
            temp->ph=phone;
            printf("Success\n");
            return;
        }
        temp=temp->next;
    }
    
    Node* newNode=(Node*)malloc(sizeof(Node));
    if(!newNode){
        printf("Memory allocation failed");
        return;
    }
    strcpy(newNode->name,name);
    newNode->ph=phone;
    newNode->next=NULL;
     
    if(head==NULL)
    {
        head=tail=newNode;
    }
    else {
        tail->next=newNode;
        tail=newNode;
    }
    printf("Success");
    
}

void pop(char name[]){
    if(head==NULL){
        printf("Not found");
        return;
    }
    if(strcmp(name,head->name)==0){
        Node* temp=head;
        head=head->next;
        if(head==NULL) tail=NULL;
        free(temp);
        printf("Success");
        return;
    }
    Node* temp=head->next,*prev=head;
    while(temp){
        if(strcmp(name,temp->name)==0){
            prev->next=temp->next;
            if(tail==temp) tail=prev;
            free(temp);
            printf("Success\n");
            return;
            
        }
    }
}
void search(char name[]){
    Node* temp=head;
    while(temp){
        if(strcmp(name,temp->name)==0){
            printf("%d",temp->ph);
            return;
        }
        temp=temp->next;
    }
    printf("Not found\n");
}
void delete(char name[]){
    if(head==NULL){
        printf("Not found\n");
        return;
    }
    if(strcmp(name,head->name)==0){
        Node* temp=head;
        head=head->next;
        if(head==NULL) tail=NULL;
        free(temp);
        printf("Success\n");
        return;
    }
    Node* temp=head->next,*prev=head;
    while(temp){
        if(strcmp(name,temp->name)==0){
            prev->next=temp->next;
            if(tail==temp)tail=prev;
            free(temp);
            printf("Success\n");
            return;
        }
        prev=temp;
        temp=temp->next;
    }
    printf("Not found");
}
void freeMemory(){
    Node* temp;
    while(head){
        temp=head;
        head=head->next;
        free(temp);
    }
}

int main() {
    int n;
    char str[100];
    char name[101];
    int no;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf(" %[^\n]",str);
        if(strncmp(str,"add",3)==0){
           // sscanf(str," add(\%[^\"]"]\")
            sscanf(str, " add(\"%[^\"]\", %d)", name, &no);
            push(name,no);
            
        }else if(strncmp(str,"search",6)==0){
            sscanf((str," search(\"%[^\"]\")"),name);
            search(name);
        }
    }
    
    return 0;
}
