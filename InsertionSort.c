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


void swap(node *first, node *second)
{
    int temp = first->data;
    first->data = second->data;
    second->data = temp;
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


void insertionSortLinkedList(node **head)
{
    if (*head == NULL) 
        return;

    node *sorted = NULL; 
    node *current = *head; 

    while (current != NULL)
    {
        node *next = current->next; 
        if (sorted == NULL || sorted->data >= current->data) 
        {
            current->next = sorted;
            sorted = current;
        }
        else
        {
            node *temp = sorted;
           
            while (temp->next != NULL && temp->next->data < current->data)
            {
                temp = temp->next;
            }
            
            current->next = temp->next;
            temp->next = current;
        }
        current = next; 
    }

    *head = sorted; 
}


node *createLinkedList()
{
    node *head = NULL;
    node *current = NULL;
    int number;

    printf("Enter numbers for the linked list (enter non-numeric value to stop):\n");
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

        if (getchar() == '\n') 
        {
            break;
        }
    }

    return head;
}

int main()
{
    node *head = createLinkedList(); 

    printf("Original list:\n");
    printLinkedList(head); 

    insertionSortLinkedList(&head); 

    printf("Sorted list:\n");
    printLinkedList(head);

    return 0;
}
