#include <stdio.h>
#include <stdlib.h>

typedef struct singlyLinkedList {
    int data;
    struct singlyLinkedList *next;
} node;

node *createNode(int value) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void findPairWithSum(node *head, int target) {
    if (head == NULL || head->next == NULL) {
        printf("No pair found.\n");
        return;
    }

    // Store the linked list elements in an array to make pair finding easier
    node *temp = head;
    int length = 0;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }

    // If the list has fewer than 2 elements, no pair is possible
    if (length < 2) {
        printf("No pair found.\n");
        return;
    }

    // Create an array to hold the list values
    int *arr = (int *)malloc(length * sizeof(int));
    temp = head;
    int index = 0;
    while (temp != NULL) {
        arr[index++] = temp->data;
        temp = temp->next;
    }

    // Use two pointers to find the pair
    int left = 0;
    int right = length - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            printf("Pair found: (%d, %d)\n", arr[left], arr[right]);
            free(arr);  // Free allocated memory
            return;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }

    printf("No pair found.\n");
    free(arr);  // Free allocated memory
}

void printLinkedList(node *head) {
    node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

node *createLinkedList() {
    node *head = NULL;
    node *current = NULL;
    int number;

    printf("Enter elements for the linked list (enter non-numeric value to stop):\n");
    while (scanf("%d", &number) == 1) {
        if (head == NULL) {
            current = createNode(number);
            head = current;
        } else {
            current->next = createNode(number);
            current = current->next;
        }
        if (getchar() == '\n') {
            break;
        }
    }
    return head;
}

int main() {
    node *head = createLinkedList();

    printf("Linked List: ");
    printLinkedList(head);

    printf("Enter the target sum: ");
    int target;
    scanf("%d", &target);

    findPairWithSum(head, target);

    return 0;
}
