// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #define TABLE 10
// typedef struct Node{
//  char name[21];
//  int phone;
//  struct Node* next;   
// }Node;
//  Node* hashTable[TABLE];
//  unsigned int hash(char *str){
//     int value=0;
//     for(int i=0;i<strlen(str);i++){
//         value+=str[i];
//     }
//     return value%TABLE;
//  }

//  void add(char *str,int ph){
//     unsigned int index=hash(str);
//     Node* current=hashTable[index];
//     while(current!=NULL){
//         if(strcmp(current->name,str)==0){
//             current->phone=ph;
//             return;
//         }
//         current=current->next;
//     }
//     Node* newNode=(Node*)malloc(sizeof(Node));
//     strcpy(newNode->name,str);
//     newNode->phone=ph;
//     newNode->next=hashTable[index];
//     hashTable[index]=newNode;
//  }
//  void delete(char *str)
//  {
//     unsigned int index=hash(str);
//     Node*current=hashTable[index];
//     Node*prev=NULL;
//     while(current!=NULL){
//         if(strcmp(current->name,str)==0){
//             if(prev==NULL){
//                 hashTable[index]=current->next;

//             }else {
//                 prev->next=current->next;
//             }
//             free(current);
//             return;
//         }
//         prev=current;
//         current=current->next;
//     }
//  }

// void searchContact(char *str){
//     unsigned int index=hash(str);
//     Node* current=hashTable[index];
//     while(current!=NULL){
//         if(strcmp(current->name,str)==0){
//             printf("%d->",current->phone);
//             return;
//         }
//         current=current->next;
//     }
//     printf("Not found\n");
// }

// int main() {
//     int n;
//     scanf("%d", &n);
//     getchar();  
//     char operation[10], name[21];
//     int number;
    
//     for (int i = 0; i < n; i++) {
//         scanf("%s", operation);
//         getchar();  
        
//         if (strcmp(operation, "add") == 0) {
//             scanf("%s %d", name, &number);
//             add(name, number);
//         } else if (strcmp(operation, "delete") == 0) {
//             scanf("%s", name);
//             delete(name);
//         } else if (strcmp(operation, "search") == 0) {
//             scanf("%s", name);
//             searchContact(name);
//         }
//     }
    
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE 10
typedef struct Node{
 char action[21];
 int count;
 struct Node* next;   
}Node;
 Node* hashTable[TABLE];
 unsigned int hash(char *str){
    int value=0;
    for(int i=0;i<strlen(str);i++){
        value+=str[i];
    }
    return value%TABLE;
 }

 void insert(char*action ){
    unsigned int index=hash(action);
    Node* current=hashTable[index];
    while(current!=NULL){
        if(strcmp(current->action,action)==0){
            current->count++;
            return;
        }
        current=current->next;
    }
    Node* newNode=(Node*)malloc(sizeof(Node));
    strcpy(newNode->action,action);
    newNode->count=1;
    newNode->next=hashTable[index];
    hashTable[index]=newNode;

 }

 void print(int threshold){
    for(int i=0;i<TABLE;i++){
        Node* current=hashTable[i];
        while(current!=NULL){
            if(current->count<threshold){
                printf("%s ",current->action);
            }
            current=current->next;
        }
    }
  //  printf("\n");
 }

int main(){
    char logs[][21] = {"login", "logout", "upload", "login", "upload", "download"};
    int n=sizeof(logs)/sizeof(logs[0]);
    int threshold=1;
    for(int i=0;i<n;i++){
        insert(logs[i]);

    }
    printf("Actions with fewer than %d occurrences: [", threshold);
     print(threshold);
     printf("]");
     return 0;
}



