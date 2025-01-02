#include<stdio.h>
int main()
{
    int B,N,M;
    printf("Enter Base exponent and modulus \n");
    scanf("%d%d%d",&B,&N,&M);
    if(N<0 || M<1)
    {
        printf("Invalid Input");
        return 1;
    }
    int result=1;
    B=B%M; // Ensuring base is always in the range of modulus.
    while(N>0){
        if(N%2==1){
            result=(result*B)%M;
        }
        N=N/2;
        B=B*B%M;
    }
    printf("Result=%d",result);

}
