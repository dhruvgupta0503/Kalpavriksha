#include <stdio.h>
#include <stdlib.h>

void nextGreaterElement(int *a, int n) {
    int *result = (int*)malloc(n * sizeof(int));

    
    for (int i = 0; i < n; i++) {
        result[i] = -1;
    }
    int *stack = (int*)malloc(n * sizeof(int));
    int top = -1;

       for (int i = 0; i < 2 * n; i++) {
        int current = i % n;  
        
      
        while (top != -1 && a[stack[top]] < a[current]) {
            int index = stack[top--];
            result[index] = a[current];  
        }
        
        
        if (i < n) {
            stack[++top] = current;
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    free(result);
    free(stack);
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
      for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }  
    nextGreaterElement(a, n);

    return 0;
}
