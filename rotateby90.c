#include <stdio.h>
#include <stdlib.h>

void Rotateby90(int matrix[][100],int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int temp=matrix[i][j];
            matrix[i][j]=matrix[j][i];
            matrix[j][i]=temp;
        }
    }
    for(int i=0;i<n;i++){
        
        int start=0,end=n-1;
        while(start<=end){
        int temp=matrix[i][start];
        matrix[i][start]=matrix[i][end];
        matrix[i][end]=temp;
        start++;
        end--;
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int matrix[100][100];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    Rotateby90(matrix,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");

}
return 0;
}
