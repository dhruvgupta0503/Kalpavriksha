#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to partition the list and return the pivot node
Node* partition(Node* low, Node* high) {
    int pivot = high->data;
    Node* i = low->next; // i points to one node ahead of low
    Node* j = low;

    for (; i != high; i = i->next) {
        if (i->data <= pivot) {
            j = (j == NULL) ? low : j->next;
            int temp = j->data;
            j->data = i->data;
            i->data = temp;
        }
    }

    int temp = j->data;
    j->data = high->data;
    high->data = temp;

    return j;
}

// Function to implement Quick Sort on the linked list
void quickSort(Node* low, Node* high) {
    if (low != NULL && high != NULL && low != high && low != high->next) {
        Node* pivot = partition(low, high);
        quickSort(low, pivot);  // Before pivot
        quickSort(pivot->next, high);  // After pivot
    }
}

// Utility function to get the last node in the linked list
Node* getTail(Node* node) {
    while (node != NULL && node->next != NULL) {
        node = node->next;
    }
    return node;
}

// Main function to test Quick Sort on the linked list
int main() {
    Node* head = newNode(10);
    head->next = newNode(80);
    head->next->next = newNode(30);
    head->next->next->next = newNode(90);
    head->next->next->next->next = newNode(40);
    head->next->next->next->next->next = newNode(50);

    printf("Original list: ");
    printList(head);

    Node* tail = getTail(head);  // Get the tail of the linked list
    quickSort(head, tail);

    printf("Sorted list: ");
    printList(head);

    return 0;
}
