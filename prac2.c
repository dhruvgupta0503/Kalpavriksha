// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #define TABLE 10
// typedef struct Node{
//     char name[21];
//     int on;
//     struct Node* next;
// }Node;

// Node*hashTable[TABLE];
// unsigned int hashFunction(char* str) {
//     unsigned int hash = 0;
//     while (*str) {
//         hash = hash * 31 + *str++;  
//     }
//     return hash%TABLE;  
// }


// // unsigned int hash(char *room){
// //     unsigned int value=0;
 
// //     for(int i = 0; i < strlen(room);i++){
// //         value+=room[i];
// //     }
// //     return value%TableSize;
// // }

// Node* findRoom( char*room){
//     unsigned int index=hashFunction(room);
//     Node*current=hashTable[index];
//     while(current!=NULL){
//         if(strcmp(current->name,room)==0){
//             return current;
//         }
//         current=current->next;
//     }
//     return NULL;
// }
// void update(char *room,int status){
//     int index=hashFunction(room);
//     Node* existing=findRoom(room);
//     if(existing==NULL){
//         Node*newRoom=(Node*)malloc(sizeof(Node));
//         strcpy(newRoom->name,room);
//         newRoom->on=status;
//         newRoom->next=hashTable[index];
//         hashTable[index]=newRoom;
//     }
//     else {
//         existing->on=status;
//     }
// }
// void turn_on(char *room){
//     update(room,1);
// }
// void turn_off(char *room){
//     update(room,0);
// }



// void status(char *room){
//     Node* existingRoom=findRoom(room);
//     if(existingRoom==NULL || existingRoom->on==0){
//         printf("OFF\n");
//     }
//     else {
//         printf("ON\n");
//     }
// }
// int main() {
//     int n;
//     scanf("%d", &n);  
//     char command[30], room[21];
   
//     for (int i = 0; i < n; i++) {
//         scanf("%s %s", command, room);
//         if (strcmp(command, "TURN_ON") == 0) {
//             turn_on(room);  
//         } else if (strcmp(command, "TURN_OFF") == 0) {
//             turn_off(room);  
//         } else if (strcmp(command, "STATUS") == 0) {
//             status(room);  
//         }
//     }
//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>
#define TABLE 100
typedef struct Node{
    char name[21];
    int isOn;
    struct Node* next;
}Node;

Node*hashTable[TABLE];
unsigned int hash(char *str ){
    int value=0;
    for(int i=0;strlen(str);i++){
        value+=str[i];
    }
    return value%TABLE;
}
Node* findRoom(char *room){
    unsigned int index=hash(room);
    Node* current=hashTable[index];
    while(current !=NULL){
        if(strcmp(current->name,room)==0){
            return current;
        }
        current=current->next;
    }
    return NULL;
}

void update(char *room,int status){
    int index=hash(room);
    Node*existing=findRoom(room);
    if(existing==NULL){
        Node* newRoom=(Node*)malloc(sizeof(Node));
        strcpy(newRoom->name,room);
        newRoom->isOn=status;
        newRoom->next=hashTable[index];
        hashTable[index]=newRoom;
    }else {
        existing->isOn=status;

    }
}
void turn_on(char*room){
    update(room,1);

}
void turn_off(char *room){
    update(room,0);
}


