#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void  reverse(char *str){
    int len=strlen(str);
    char *stack=(char*)malloc(len*sizeof(int));
    int top=-1;
    for(int i=0;i<len;i++){
        stack[++top]=str[i];
    }
    for(int i=0;i<len;i++){
        str[i]=stack[top--];
    }
    free(stack);
}

int main(){
    char str[]="hello world";
    printf("original string %s",str);
    reverse(str);
    printf("reverse string %s",str);
    return 0;
}