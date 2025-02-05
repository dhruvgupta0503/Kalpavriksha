//create a structure of string and 2d array and initialize it and dynamically allocate the memory and print it 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *str;
    int **arr;
    int row,col;
}Data;
void allocate_memory(Data *d,int strSize,int row,int col){
     
    d->str = (char*)malloc(10*sizeof(char));
    d->arr = (int**)malloc(row*sizeof(int*));
    for(int i=0;i<row;i++){
        d->arr[i] = (int*)malloc(col*sizeof(int));
    }
    d->row=row;
    d->col=col;
    


    

}
void takeInput(Data *d){
    printf("enter a string");
    scanf("%s",d->str);
    printf("enter the elements of matrix");
    for(int i=0;i<d->row;i++){
        for(int j=0;j<d->col;j++){
            scanf("%d",&d->arr[i][j]);
            }
            }
            

}
void printData(Data *d){
    printf("%s\n",d->str);
    for(int i=0;i<d->row;i++){
        for(int j=0;j<d->col;j++){
            printf("%d ",d->arr[i][j]);
            }
            printf("\n");
    }
}
void freeData(Data *d){
    free(d->str);
    for(int i=0;i<d->row;i++){
        free(d->arr[i]);
        }
        free(d->arr);
        }






int main(){
   Data *d = (Data *)malloc(sizeof(Data));
    allocate_memory(&d,10,3,3);
    takeInput(&d);
    printData(&d);
    freeData(&d);

    // s *ptr;
    // ptr = (s*)malloc(sizeof(s));
    // ptr->str = (char*)malloc(10*sizeof(char));
    // strcpy(ptr->str,"Hello");
    // ptr->arr = (int**)malloc(2*sizeof(int*));
    // ptr->arr[0] = (int*)malloc(2*sizeof(int));
    // ptr->arr[1] = (int*)malloc(2*sizeof(int));
    // ptr->arr[0][0] = 10;
    // ptr->arr[0][1] = 20;
    // ptr->arr[1][0] = 30;
    // ptr->arr[1][1] = 40;
    // printf("%s\n",ptr->str);
    // printf("%d %d\n",ptr->arr[0][0],ptr->arr[2][3]);
        
        return 0;
}
