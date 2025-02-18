// 2. Warehouse Inventory Tracking System You are building a warehouse inventory system to track item quantities. The system supports adding items, updating quantities, and querying the quantity of a specific item. • "ADD " → Adds a new item with the given quantity. If the item already exists, increase its quantity. • "UPDATE " → Updates the quantity of an existing item to the new quantity. • "QUERY " → Returns the current quantity of the specified item. If the item does not exist, return "Item not found". Input: The first line contains an integer n (1 ≤ n ≤ 100) — the number of commands. The next n lines contain a command of one of the following types: • "ADD " • "UPDATE " • "QUERY " Output: For each "QUERY" command, print the current quantity of the item or "Item not found"


#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#define TABLE 101

typedef struct Node{
    char item [50];
    int quantity;
    struct Node* next;
}Node;

Node* hashTable[TABLE];
unsigned int hashFunction(char* str) {
    unsigned int hash = 0;
    while (*str) {
        hash = hash * 31 + *str++;  
    }
    return hash%TABLE;  
}


void addItem(char *item,int quantity){
    unsigned int index =hashFunction(item);
    Node* current=hashTable[index] ;
    while(current){
        if(strcmp(current->item,item)==0){
            current->quantity+=quantity;
            return;
        }
        current=current->next;
    }
    Node* newNode=(Node*)malloc(sizeof(Node));
    strcpy(newNode->item,item);
    newNode->quantity=quantity;
    newNode->next=hashTable[index];
    hashTable[index]=newNode;
}

void update(char *item,int quantity){
    unsigned int index=hashFunction(item);
    Node* current=hashTable[index];
    while(current){
        if(strcmp(current->item,item)==0){
            current->quantity=quantity;
            return;
        }
        current=current->next;
    }
}
void query(char *item){
    unsigned int index=hashFunction(item);
    Node* current=hashTable[index];
    while(current){
        if(strcmp(current->item,item)==0){
            printf("%d",current->quantity);
            return ;
        }
        current=current->next;
    }
    printf("Item not found");
}

int main(){
    int n;
    scanf("%d",&n);
    char command[10],item[50];
    int quantity;
    for(int i=0;i<n;i++){
        scanf("%s",command);
        if(strcmp(command,"ADD")==0){
            scanf("%s %d",item,&quantity);
            addItem(item,quantity);

        }else if (strcmp(command,"UPDATE")==0){
            scanf("%s %d",item,&quantity);
            update(item,quantity);
        }else if(strcmp(command,"QUERY")==0){
            scanf("%s",item);
            query(item);
        }
    }
    return 0;
}