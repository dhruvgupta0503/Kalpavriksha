#include <stdio.h>
#include <stdlib.h>

typedef struct singlyLinkedList
{
    int data;
    struct singlyLinkedList *next;
} node;

node *createNode(int value)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void printLinkedList(node *head)
{
    node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int linearSearch(node *head, int value)
{
    int position = 1;
    node *current = head;

    while (current != NULL)
    {
        if (current->data == value)
            return position;
        current = current->next;
        position++;
    }

    return -1;
}

node *createLinkedList()
{
    node *head = NULL;
    node *current = NULL;
    int number;

    printf("Enter numbers for the linked list (enter any non-number to stop):\n");
    while (scanf("%d", &number) == 1)
    {
        if (head == NULL)
        {
            current = createNode(number);
            head = current;
        }
        else
        {
            current->next = createNode(number);
            current = current->next;
        }
    }
    getchar();  
    return head;
}

void freeLinkedList(node *head)
{
    node *current = head;
    while (current != NULL)
    {
        node *temp = current;
        current = current->next;
        free(temp);
    }
}

int main()
{
    node *head = createLinkedList();
    int value;

    printf("Linked List: ");
    printLinkedList(head);

    printf("Enter key to search: ");
    scanf("%d", &value);
    
    int linearPosition = linearSearch(head, value);
    if (linearPosition != -1)
        printf("Value found at position: %d\n", linearPosition);
    else
        printf("Value not found\n");

    // Free memory allocated for the linked list
    freeLinkedList(head);

    return 0;
}
