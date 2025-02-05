#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function to place the pivot at the correct position
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Taking the last element as pivot
    int i = (low - 1);  // Pointer for the smaller element
    
    for (int j = low; j < high; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++;  // Increment the smaller element pointer
            swap(&arr[i], &arr[j]);  // Swap elements
        }
    }
    swap(&arr[i + 1], &arr[high]);  // Move pivot to its correct position
    return (i + 1);  // Return the index of the pivot
}

// QuickSort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partitioning index, arr[pi] is now at the right place
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: \n");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("\nSorted array: \n");
    printArray(arr, n);

    return 0;
}
