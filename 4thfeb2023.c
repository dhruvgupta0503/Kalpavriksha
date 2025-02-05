// // Problem: Given a list of file system commands (cd folder/, cd ../, cd ./), determine the current working directory.
 
// // Example:
// // Input: ["cd usr/", "cd local/", "cd ../", "cd bin/"]
// // Output: "/usr/bin/"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void commands(char c[],int n){
    char path[1000]="/";
    char temp[1000];
    for(int i=0;i<n;i++){
       sscanf(c[i], "cd %s", temp);
          //scanf("cd %s",temp);   
    }
    if(strcmp(temp,"../")==0){
        int len=strlen(path);
        if(len>1){
        for (int j = len - 2; j >= 0; j--) {
                    if (path[j] == '/') {
                        path[j + 1] = '\0';
                        break;
                    }
                }
        }
        else if(strcmp(temp,"./")==0){
             if (temp[strlen(temp) - 1] == '/') {
                temp[strlen(temp) - 1] = '\0';
            }
        }
        strcat(path,temp);
        strcat(path, "/");

        

 

    }
     printf("Current working directory: %s\n", path);
}
    

// }
// // #include<stdio.h>
// // #include<stdlib.h>
// // #include<string.h>
// // #define max_len 100
 
// // typedef struct Node{
// //     char dir[max_len];
// //     struct Node*next;
// // }Node;
 
// // typedef struct Stack{
// //     Node*top;
// // }Stack;
 
// // initstack(Stack*s){
// //     s->top=NULL;
// // }
 
// // void push(Stack*s,char dir){
// //     Node*newnode=(Node*)malloc(sizeof(Node));
// //     strycpy(newnode->dir,dir);
// //     newnode->next=s->top;
// //     return newnode;
 
// // }
 
// // void pop(Stack*s){
// //     if(s->top){
// //         Node*temp=s->top;
// //         s->top=s->top->next;
// //         free(temp);
// //     }
// // }
// // void function()


int main(){
    int n;
    printf("enter the number of commands");
    scanf("%d",&n);
    getchar();
   char **command = (char**)malloc(n * sizeof(char*));
     printf("Enter the commands (e.g., 'cd usr/', 'cd ../', 'cd ./'):\n");
    for (int i = 0; i < n; i++) {
         command[i] = (char*)malloc(1000 * sizeof(char));
        fgets(command[i], 1000, stdin);
        
        command[i][strcspn(command[i], "\n")] = '\0';


    }
     printf("Enter the commands (e.g., 'cd usr/', 'cd ../', 'cd ./'):\n");
    for (int i = 0; i < n; i++) {
        fgets(command[i], 1000, stdin);
       
        command[i][strcspn(command[i], "\n")] = '\0';
    }
    commands(command,n);

     for (int i = 0; i < n; i++) {
        free(command[i]);
    }
    return 0;
}

//Problem: Given a list of file system commands (cd folder/, cd ../, cd ./), determine the current working directory.

    // Input: ["cd usr/", "cd local/", "cd ../", "cd bin/"]

    // Output: "/usr/bin/"

    // #include <stdio.h>

    // #include<stdlib.h>

    // #include<string.h>

    // #define SIZE 5

    // struct stack{

    //     int size;

    //     int front;

    //     char** arr;

    // };

    // struct stack * createstack(int size)

    // {

    //     struct stack* stack=(struct stack*)malloc(sizeof(struct stack));

    //     stack->size=size;

    //     stack->front=-1;

    //     stack->arr=(char**)malloc(100*sizeof(char*));

    //     return stack;

    // }

    // int isFull(struct stack* stack)

    // {

    //     return stack->front==stack->size-1;

    // }

    // int isEmpty(struct stack* stack)

    // {

    //     return stack->front==-1;

    // }

    // void Push(struct stack* stack,char str[])

    // {

    //     if(isFull(stack))

    //     {

    //         return;

    //     }

    //     stack->front++;

    //     stack->arr[stack->front]=(char*)malloc(100*sizeof(char));

    //     strcpy(stack->arr[stack->front],str);

    // }

    // void pop(struct stack*stack)

    // {

    //     if(isEmpty(stack))

    //     {

    //         return ;

    //         }

    //     char* val=stack->arr[stack->front];

    //     stack->front--;

    // }

    // void printStack(struct stack* stack)

    // {

    //     for(int i=0;i<=stack->front;i++)

    //     {

    //         printf("%s\n",stack->arr[i]);

    //     }

    // }

    // void my_function(struct stack* stack, char input_str[5][100]) {

    //     for (int i = 0; i < SIZE; i++) {

    //         if (strcmp(input_str[i], "cd ../") == 0) {

    //             pop(stack); 

    //         } else if(strcmp(input_str[i],"cd ./")==0) {

    //             continue;


    //         }else {
    //             Push(stack,input_str[i]);
    //         }

    //     }

    //     printStack(stack);

    // }

    // int main()

    // {

    //     struct stack* stack = createstack(SIZE);

    //     char input_str[5][100] = {"cd usr/", "cd local/", "cd ../", "cd bin/","cd ./"};

    //     my_function(stack, input_str);


    //     return 0;

    // }

 