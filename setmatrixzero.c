#include<stdio.h>
#define MAX 100


void setzero(int matrix[MAX][MAX],int rows,int cols){
    int rowf[MAX]={0},colf[MAX]={0};
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(matrix[i][j]==0){
                rowf[i]=1;
                colf[j]=1;
            }
        }
        }
        for(int i=0;i<rows;i++){
            if(rowf[i]==1)
            for(int j=0;j<cols;j++){
                matrix[i][j]=0;
            }
        }
        for(int j=0;j<cols;j++){
            if(colf[j]==1){
            for(int i=0;i<rows;i++){
                matrix[i][j]=0;
            }
        }
        }
}
int main(){
    int rows,cols;
    int matrix[MAX][MAX];
    scanf("%d%d",&rows,&cols);
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            scanf("%d",&matrix[i][j]);
        }
        }
        setzero(matrix,rows,cols);
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                printf("%d ",matrix[i][j]);
            }
            printf("\n");
        }
        return 0;
}