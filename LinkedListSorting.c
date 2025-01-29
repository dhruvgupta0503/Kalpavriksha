#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void append(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}


void printList(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}


void bubbleSort(Node* head) {
    if (head == NULL) return;

    int swapped;
    Node *ptr1, *lptr = NULL;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}


void selectionSort(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        Node* min = temp;
        Node* r = temp->next;

        while (r != NULL) {
            if (r->data < min->data) {
                min = r;
            }
            r = r->next;
        }

        
        int x = temp->data;
        temp->data = min->data;
        min->data = x;

        temp = temp->next;
    }
}


Node* insertionSort(Node* head) {
    if (!head || !head->next) return head;

    Node* sorted = NULL;
    Node* current = head;

    while (current != NULL) {
        Node* next = current->next;

        if (sorted == NULL || sorted->data >= current->data) {
            current->next = sorted;
            sorted = current;
        } else {
            Node* temp = sorted;
            while (temp->next != NULL && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }

        current = next;
    }
    return sorted;
}


Node* merge(Node* left, Node* right) {
    if (!left) return right;
    if (!right) return left;

    if (left->data <= right->data) {
        left->next = merge(left->next, right);
        return left;
    } else {
        right->next = merge(left, right->next);
        return right;
    }
}

Node* mergeSort(Node* head) {
    if (!head || !head->next) return head;

    Node* slow = head;
    Node* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* mid = slow->next;
    slow->next = NULL;

    Node* left = mergeSort(head);
    Node* right = mergeSort(mid);

    return merge(left, right);
}


Node* partition(Node* head, Node** left, Node** right) {
    Node* pivot = head;
    Node* current = head->next;

    *left = NULL;
    *right = NULL;

    while (current) {
        Node* next = current->next;
        if (current->data < pivot->data) {
            current->next = *left;
            *left = current;
        } else {
            current->next = *right;
            *right = current;
        }
        current = next;
    }

    return pivot;
}


Node* quickSort(Node* head) {
    if (!head || !head->next) return head;

    Node *left, *right;
    Node* pivot = partition(head, &left, &right);

    left = quickSort(left);
    right = quickSort(right);

    Node* sorted = left;

    if (sorted) {
        while (sorted->next) sorted = sorted->next;
        sorted->next = pivot;
    } else {
        left = pivot;
    }

    pivot->next = right;

    return left;
}


int main() {
    Node* head = NULL;
    int choice, n, data;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        append(&head, data);
    }

    printf("\nChoose Sorting Algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Merge Sort\n");
    printf("5. Quick Sort\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            bubbleSort(head);
            printf("\nSorted list using Bubble Sort: \n");
            break;
        case 2:
            selectionSort(head);
            printf("\nSorted list using Selection Sort: \n");
            break;
        case 3:
            head = insertionSort(head);
            printf("\nSorted list using Insertion Sort: \n");
            break;
        case 4:
            head = mergeSort(head);
            printf("\nSorted list using Merge Sort: \n");
            break;
        case 5:
            head = quickSort(head);
            printf("\nSorted list using Quick Sort: \n");
            break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }

    printList(head);
    return 0;
}