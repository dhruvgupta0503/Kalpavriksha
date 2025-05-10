#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Function to find the nearest smaller element for each element in the array
// void nearestSmaller(int arr[], int n) {
//     int stack[MAX]; // Stack to store potential candidates
//     int top = -1;   // Top of the stack
//     int result[n];  // Array to store the results

//     // Traverse the array
//     for (int i = 0; i < n; i++) {
//         // Pop elements from the stack that are greater than or equal to the current element
//         while (top >= 0 && stack[top] >= arr[i]) {
//             top--;
//         }

//         // If the stack is empty, there is no smaller element to the left
//         if (top == -1) {
//             result[i] = -1;
//         } else {
//             // The nearest smaller element is the top element of the stack
//             result[i] = stack[top];
//         }

//         // Push the current element onto the stack
//         stack[++top] = arr[i];
//     }

//     // Print the results
//     for (int i = 0; i < n; i++) {
//         printf("%d ", result[i]);
//     }
//     printf("\n");
// }


void nextSmallerElement(int n,int *arr,int *nse){
    int *stack=(int*)malloc(n*sizeof(stack));
}
int main() {
    int n;

    // Read the size of the array
    scanf("%d", &n);

    // Validate the input size
    if (n <= 0 || n > MAX) {
        printf("Invalid input\n");
        return 1;
    }

    int arr[n];

    // Read the array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Call the function to find the nearest smaller elements
    nearestSmaller(arr, n);

    return 0;
}