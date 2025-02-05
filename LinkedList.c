#include<stdio.h>
#include <stdlib.h>

// Define the Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // Allocate memory
    newNode->data = value;
    newNode->next = NULL; // Set the next pointer to NULL
    return newNode;
}

// Function to insert a node at the beginning
void insertAtStart(Node** head, int value) {
    Node* newNode = createNode(value); // Create a new node
    newNode->next = *head; // Point the new node's next to the current head
    *head = newNode; // Update the head to point to the new node
}

// Function to insert a node at the end
void insertAtEnd(Node** head, int value) {
    Node* newNode = createNode(value); // Create a new node
    if (*head == NULL) { // If the list is empty, set the new node as the head
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) { // Traverse to the last node
        temp = temp->next;
    }
    temp->next = newNode; // Point the last node's next to the new node
}

// Function to print the linked list
void printList(Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data); // Print the node data
        temp = temp->next; // Move to the next node
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL; // Start with an empty linked list
    int value, choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at Start\n");
        printf("2. Insert at End\n");
        printf("3. Print List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert at the start: ");
                scanf("%d", &value);
                insertAtStart(&head, value); // Insert at the start
                break;
            case 2:
                printf("Enter the value to insert at the end: ");
                scanf("%d", &value);
                insertAtEnd(&head, value); // Insert at the end
                break;
            case 3:
                printList(head); // Print the list
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0); // Exit the program
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
