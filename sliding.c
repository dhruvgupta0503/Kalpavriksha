// #include <stdio.h>
// #include <string.h>

// int longest(char *s,int k){
//     int n=strlen(s);
//     if(n==0 || k==0) return 0;
//     int freq[128]={0};
//     int left=0,right=0;
//     int maxi=0;
//     while(right<n){
//         freq[s[right]]++;
//         while(freq[s[right]]>k){
//             freq[s[left]]--;
//             left++;
//         }
//         if(right-left+1>maxi){
//             maxi=right-left+1;
//         }
//         right++;
//     }
//     return maxi;

// }




#include <stdio.h>
#include <stdlib.h>

int longest(char *s,int k){
    int left=0,right=0;
    int count=0;
    int maxi=0;
    int freq[128]={0};
    int n=strlen(s);
    while(right<n){
        freq[s[right]]++;
        while(freq[s[right]]>k){
            freq[s[left]]--;
            left++;
        }
        if(right-left+1>maxi){
            maxi=right-left+1;
        }
        right++;

    }
    return maxi;
}
