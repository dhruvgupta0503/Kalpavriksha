#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Node {
    char url[MAX];
    struct Node* next;
} Node;

Node* top = NULL;

void push(char* url) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }
    strcpy(newNode->url, url); 
    newNode->next = top;       
    top = newNode;             
    printf("Added: %s\n", url); 
}

void pop() {
    if (top == NULL) {
        printf("History is empty\n");
        return;
    }
    Node* temp = top;
    top = top->next;
    printf("Removed: %s\n", temp->url);
    free(temp);
}

void viewHistory() {
    if (top == NULL) {
        printf("History is empty\n");
        return;
    }
    Node* current = top;
    printf("Browser History:\n");
    while (current) {
        printf("- %s\n", current->url);
        current = current->next;
    }
}

void peek() {
    if (top == NULL) {
        printf("History is empty\n");
        return;
    }
    printf("Most recent URL: %s\n", top->url);
}

void Editurl(char* oldUrl, char* newUrl) {
    Node* current = top;
    while (current) {
        if (strcmp(current->url, oldUrl) == 0) {
            printf("Edited: %s -> %s\n", oldUrl, newUrl);
            strcpy(current->url, newUrl);
            return;
        }
        current = current->next;
    }
    printf("URL not found: %s\n", oldUrl);
}

void clearHistory() {
    Node* temp;
    while (top) {
        temp = top;
        top = top->next;
        free(temp);
    }
    printf("All history removed\n");
}

int main() {
    int choice;
    char url[MAX], newUrl[MAX];
    while (1) {
        printf("\nBrowser History Management\n");
        printf("1. Add a website\n");
        printf("2. View History\n");
        printf("3. Edit a URL\n");
        printf("4. Remove recent website\n");
        printf("5. Peek\n");
        printf("6. Clear history\n");
        printf("7. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                printf("Enter URL: ");
                scanf("%99s", url);
                push(url);
                break;
            case 2:
                viewHistory();
                break;
            case 3:
                printf("Enter URL to edit: ");
                scanf("%99s", url);
                printf("Enter the new URL: ");
                scanf("%99s", newUrl);
                Editurl(url, newUrl);
                break;
            case 4:
                pop();
                break;
            case 5:
                peek();
                break;
            case 6:
                clearHistory();
                break;
            case 7:
                clearHistory();
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}