#include<stdio.h>
#include <limits.h>
#define ROW 6
#define COL 6


int main(){
    int A[ROW][COL];
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            scanf("%d",&A[i][j]);
        }
    }
    int maxi=INT_MIN;
    for(int i=0;i<ROW-2;i++){
        for(int j=0;j<COL-2;j++){
            int currentSum=A[i][j]+A[i][j+1]+A[i][j+2]+A[i+1][j+1]+A[i+2][j]+A[i+2][j+1]+A[i+2][j+2];
            if(currentSum>maxi){
                maxi=currentSum;
            }
        }
    }
    printf("%d",maxi);
    return 0;
}