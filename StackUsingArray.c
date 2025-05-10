// #include <stdio.h>
// #include <stdlib.h>
// #define MAX 5
// struct Stack{
//     int arr[MAX];
//     int top;
// };
// void initStack(struct Stack*s){
//     s->top = -1;
// }
// int isFull(struct Stack*s){
//     return s->top==MAX-1;
// }
// int isEmpty(struct Stack*s){
//     return s->top== -1;
// }
// void push(struct Stack*s,int value){
//     s->arr[++s->top]=value;

// }
// int pop(struct Stack* s){
//     int poppedValue=s->arr[s->top--];
//     return poppedValue;
// }




// int main() {
//     struct Stack myStack;
//     initStack(&myStack);  

   
//     push(&myStack, 10);
//     push(&myStack, 20);
//     push(&myStack, 30);
//     push(&myStack, 40);
//     push(&myStack, 50);
//     push(&myStack, 60); 

    
//     pop(&myStack);
//     pop(&myStack);
//     pop(&myStack);
//     pop(&myStack);
//     pop(&myStack);
//     pop(&myStack);  

//     return 0;
// }



 
//     int choice, value;

//     while (1) {
//         printf("\nStack Operations:\n");
//         printf("1. Push\n");
//         printf("2. Pop\n");
//         printf("3. Exit\n");
//         printf("Enter your choice: ");
//         scanf("%d", &choice);

//         switch (choice) {
//             case 1:
//                 if (isFull(&myStack)) {
//                     printf("Stack is full! Cannot push more elements.\n");
//                 } else {
//                     printf("Enter a value to push: ");
//                     scanf("%d", &value);
//                     push(&myStack, value);
//                 }
//                 break;
//             case 2:
//                 pop(&myStack);
//                 break;
//             case 3:
//                 printf("Exiting...\n");
//                 exit(0);
//             default:
//                 printf("Invalid choice! Please try again.\n");
//         }
//     }

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
# define MAX 100

typedef struct {
    int arr[MAX];
    int top;
}Stack;

void init(Stack *s){
    s->top= -1;
}
int isFull(Stack *s){
    return s->top==MAX-1;
}
int isEmpty(Stack *s){
    return  s->top== -1;
}

void push(Stack *s,int value){
    s->arr[++(s->top)]=value;
}

int  pop(Stack *s){
    return s->arr[(s->top)--];
}

int main(){
    Stack myStack;
    init(&myStack);

    int choice,value;
    while(1){
        printf("Stack opration\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: 
                if(isFull(&myStack)){
                    printf("stack is full");
                    
                } 
                else {
                    printf("Enter a value to push");
                    scanf("%d",&value);
                    push(&myStack,value);
                }
                break;
            case 2:
                pop(&myStack);
                break;
                       case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
       
