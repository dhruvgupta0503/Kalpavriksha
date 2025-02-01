#include <stdio.h>
#include <stdlib.h>

int findPeakElement(int arr[],int n){
    if(n==1) return 0;
    if(arr[0]>=arr[1]) return 0;
    if(arr[n-1]>=arr[n-2]) return n-1;
    int low=1,high=n-2;
    while(low<=high){
        int mid=(low+high)/2;

        if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1])
        return mid;

        if(arr[mid]>arr[mid-1]) low=mid+1;

        else high=mid-1;
    }

return -1;

} 

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};  
    int n = sizeof(arr) / sizeof(arr[0]);  
    int ans = findPeakElement(arr, n);  
    printf("%d\n", ans);  
    return 0;
}