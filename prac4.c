// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int Kdifferent(char *arr,int k){
//     int n=strlen(arr);
//     int maxi=0;
//     int left=0;
//     int right=0;
//     int freq[128]={0};
//     int distinct=0;
//     while(right<n){
//         if(freq[arr[right]]==0){
//             distinct++;

//         }
//         freq[arr[right]]++;
//         while(distinct>k){
//             freq[arr[left]]--;

//             if(freq[arr[left]]==0){
//                 distinct--;
//             }
//             left++;
//         }
//         if (distinct == k) {
//             int len = right - left + 1;
//             maxi = (maxi > len) ? maxi : len;
//         }
//    right++;

//     }
//    return (maxi == 0) ? -1 : maxi;

// }

// int main(){
//     char str[102];
//     int k;
//     scanf("%s",str);
//     scanf("%d",&k);
//     int n=Kdifferent(str,k);
//     printf("The length of the longest substring with exactly %d distinct characters is: %d\n", k, n);
//     return 0;

// }

// #include <stdio.h>
// #include <stdlib.h>

// void printSubarraysWithExactlyK(int* arr, int n, int K) {
//     int left = 0, right = 0;
//     int freq[100001] = {0};  // Frequency array to count the elements in the window
//     int distinct = 0;
//     int count = 0;

//     // Iterate through the array with the right pointer
//     while (right < n) {
//         // If arr[right] is a new distinct element
//         if (freq[arr[right]] == 0) {
//             distinct++;
//         }

//         // Increment the frequency of the current element
//         freq[arr[right]]++;

//         // Shrink the window from the left if the number of distinct elements exceeds K
//         while (distinct > K) {
//             freq[arr[left]]--;
//             if (freq[arr[left]] == 0) {
//                 distinct--;
//             }
//             left++;
//         }

//         // If we have exactly K distinct elements, collect the subarrays
//         if (distinct == K) {
//             // Record all subarrays ending at 'right' and starting at any index between 'left' and 'right'
//             for (int i = left; i <= right; i++) {
//                 // Print the subarray arr[i] to arr[right]
//                 printf("[");
//                 for (int j = i; j <= right; j++) {
//                     printf("%d", arr[j]);
//                     if (j < right) printf(", ");
//                 }
//                 printf("]\n");
//             }
//         }

//         // Move the right pointer forward
//         right++;
//     }
// }

// int main() {
//     int arr[] = {1, 2, 1, 2, 3};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     int K = 2;

//     printf("The subarrays with exactly %d distinct integers are:\n", K);
//     printSubarraysWithExactlyK(arr, n, K);

//     return 0;

//}

#include <stdio.h>
#include <stdlib.h>

void printsubarray(int *arr, int n, int k)
{
    int left = 0;
    int right = 0;
    int distinct = 0;
    int freq[100001] = {0};
    int maxi = 0;
    while (right < n)
    {
        if (freq[arr[right]] == 0)
        {
            distinct++;
        }
        freq[arr[right]]++;
        while (distinct > k)
        {
            if (freq[arr[left]] == 0)
            {
                distinct--;
            }
            left++;
        }
        if (distinct == k)
        {
            for (int i = left; i <= right; i++)
            {

                printf("[");
                for (int j = i; j <= right; j++)
                {
                    printf("%d", arr[j]);
                    if (j < right)
                        printf(", ");
                }
                printf("]\n");
            }
        }
        right++;
    }
}

int main() {
    int arr[] = {1, 2, 1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int K = 2;

    printf("The subarrays with exactly %d distinct integers are:\n", K);
    printsubarray(arr, n, K);

    return 0;
}
