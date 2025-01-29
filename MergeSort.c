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

node *mergeSortedLists(node *a, node *b)
{
    // Base cases for recursion
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;

    // Compare the nodes for descending order
    if (a->data >= b->data)
    {
        a->next = mergeSortedLists(a->next, b);
        return a;
    }
    else
    {
        b->next = mergeSortedLists(a, b->next);
        return b;
    }
}

void splitLinkedList(node *source, node **front, node **back)
{
    node *slow = source;
    node *fast = source->next;

    // Advance fast by two steps, and slow by one step
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *front = source;
    *back = slow->next;
    slow->next = NULL;
}

void mergeSortLinkedList(node **head)
{
    // Base case: list is empty or has one node
    if (*head == NULL || (*head)->next == NULL)
        return;

    node *front, *back;

    // Split the list into two halves
    splitLinkedList(*head, &front, &back);

    // Recursively sort the two halves
    mergeSortLinkedList(&front);
    mergeSortLinkedList(&back);

    // Merge the sorted halves
    *head = mergeSortedLists(front, back);
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
        if (getchar() == '\n')  // Stop input when newline is encountered
        {
            break;
        }
    }
    return head;
}

int main()
{
    node *head = createLinkedList();

    mergeSortLinkedList(&head);
    printf("Descending order of elements: \n");
    printLinkedList(head);

    return 0;
}
