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

void printFirstKElements(node *head, int k)
{
    if (head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }

    printf("First %d sorted elements:\n", k);
    node *current = head;
    int count = 0;

    while (current != NULL && count < k)
    {
        printf("%d", current->data);
        if (count < k - 1) 
            printf(" -> ");
        current = current->next;
        count++;
    }
    printf("\n");
}

void selectionSortLinkedList(node *head)
{
    if (head == NULL)
        return;

    node *current = head;
    while (current != NULL)
    {
        node *minNode = current;
        node *nextNode = current->next;

        while (nextNode != NULL)
        {
            if (nextNode->data < minNode->data)
            {
                minNode = nextNode;
            }
            nextNode = nextNode->next;
        }

        if (minNode != current)
        {
            swap(current, minNode);
        }

        current = current->next;
    }
}

node *createLinkedList()
{
    node *head = NULL;
    node *current = NULL;
    int number;
    char input;

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
        
       
        input = getchar(); 
        if (input == '\n') break;
    }

    return head;
}

int main()
{
    node *head = createLinkedList();


    if (head == NULL)
    {
        printf("The list is empty.\n");
        return 0;
    }

 
    selectionSortLinkedList(head);

    printf("Sorted elements are: ");
    printLinkedList(head);

   
    printf("Enter the number of first elements you want to print:\n");
    int k;
    scanf("%d", &k);

 
    printFirstKElements(head, k);

    return 0;
}
