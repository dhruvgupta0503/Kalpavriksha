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

void swap(node *first, node *second) {
    int temp = first->data;
    first->data = second->data;
    second->data = temp;
}

void sortLinkedList(node *head) {
    if (head == NULL)
        return;

    node *current = head;
    while (current != NULL) {
        node *minNode = current;
        node *nextNode = current->next;

        while (nextNode != NULL) {
            if (nextNode->data < minNode->data) {
                minNode = nextNode;
            }
            nextNode = nextNode->next;
        }

        if (minNode != current) {
            swap(current, minNode);
        }

        current = current->next;
    }
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

    printf("Enter numbers for the linked list (enter non-numeric value to stop):\n");
    while (scanf("%d", &number) == 1) {
        if (head == NULL) {
            current = createNode(number);
            head = current;
        } else {
            current->next = createNode(number);
            current = current->next;
        }
    }
    // Clear the input buffer if necessary
    getchar(); // to consume any newline left by scanf

    return head;
}

// Function to get the middle node of the linked list
node* getMiddle(node* start, node* end) {
    if (start == NULL) {
        return NULL;
    }

    node* slow = start;
    node* fast = start;

    while (fast != end && fast->next != end) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Function to implement binary search on a sorted linked list
int binarySearch(node* head, int value) {
    node *start = head;
    node *end = NULL;  // We will keep track of the end for binary search
    int position = 1;  // Initialize position to 1 (as linked lists are 1-indexed)

    while (start != end) {
        node *mid = getMiddle(start, end);  // Get middle node
        
        if (mid->data == value) {
            return position;  // Return the position when the value is found
        } else if (mid->data < value) {
            start = mid->next;  // Search the right half
            position++;  // Increment the position as we move to the next segment
        } else {
            end = mid;  // Search the left half
        }
    }
    
    return -1;  // Value not found
}

int main() {
    node *head = createLinkedList();
    int value;

    printf("Original Linked List: ");
    printLinkedList(head);

    // Sort the linked list
    sortLinkedList(head);
    printf("Sorted Linked List: ");
    printLinkedList(head);

    // Perform binary search
    printf("Enter value to search: ");
    scanf("%d", &value);

    int binaryPosition = binarySearch(head, value);
    if (binaryPosition != -1) {
        printf("Value found at position: %d\n", binaryPosition);  // Display position
    } else {
        printf("Value not found\n");
    }

    return 0;
}
