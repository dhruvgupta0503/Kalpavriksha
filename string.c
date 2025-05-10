#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
 
int main() {
 
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    char str[100001];
    int i;
    int freq[256];
    //scanf("%s",str);
    fgets(str,sizeof(str),stdin);
    str[strcspn(str,"\n")] = '\0';
    int n = strlen(str);
    for(i = 0 ;i < n ; i++){
        int index = (unsigned char)str[i];
        freq[index]++;
    }
    printf("{");
    int first = 1;
    for(i = 0 ; i< 256 ; i++){
        if(freq[i] > 0){
            if(!first){
                printf(", ");
            }
            printf("%c:%d", i, freq[i]);
            first = 0;
        }
    }
    printf("}\n");
    return 0;
}