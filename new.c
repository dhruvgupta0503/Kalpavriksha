// You are given a string. Your task is to count the frequency of each character in the string and return the frequency in the form of a map, where each key-value pair corresponds to a character and its count.

// Input Format

// A string str consisting of letters (both lowercase and uppercase), digits, and special characters.

// Constraints

// 1 <= len(str) <= 10^5

// Output Format

// The output should be a map where each key is a character from the input string and its value is the count of its occurrences. The keys should be sorted according to their ASCII equivalent code.

// Sample Input 0

// programming
// Sample Output 0

// {a:1, g:2, i:1, m:2, n:1, o:1, p:1, r:2}
// Sample Input 1

// abcabc
// Sample Output 1

// {a:2, b:2, c:2}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHAR 256

void count(const char* str){
    int freq[MAX_CHAR]={0};
    for(int i=0;str[i]!=0;i++){
        freq[(int)str[i]]++;
    }
    printf("{");
    int first=1;
    for(int i=0;i<MAX_CHAR;i++){
        if(freq[i]>0){
            if(!first){
                printf(", ");
            }
            printf("%c:%d",i,freq[i]);
            first=0;
        }
    }
    printf("}\n");
}

