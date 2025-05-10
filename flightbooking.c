#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char flight[10];
    char time[10];
    struct Node* next;
} Node;

int hrtomin(const char* time) {
    int h, r;
    sscanf(time, "%d:%d", &h, &r);
    return h * 60 + r;
}

Node* createNode(char *fnumber, char *time) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->flight, fnumber);
    strcpy(newNode->time, time);
    newNode->next = NULL;
    return newNode;
}

void append(Node** head, char *fnumber, char *time) {
    Node* newNode = createNode(fnumber, time);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        print(*head);

    }
}

void print(Node* head) {
    while (head) {
        printf("(%s, %s) -> ", head->flight, head->time);
        head = head->next;
    }
    printf("NULL\n");
}

Node* getMiddle(Node* head) {
    if (!head) return NULL;
    
    Node* slow = head;
    Node* fast = head->next;
    
    while (fast && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

Node* merge(Node* left, Node* right) {
    if (!left) return right;
    if (!right) return left;

    Node* result = NULL;
    if (hrtomin(left->time) <= hrtomin(right->time)) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }
    
    return result;
}

Node* mergeSort(Node* head) {
    if (!head || !head->next) {
        return head;
    }
    
    Node* middle = getMiddle(head);
    Node* left = head;
    Node* right = middle->next;
    
    middle->next = NULL;
    
    left = mergeSort(left);
    right = mergeSort(right);
    
    return merge(left, right);
}

int main() {
    Node* head = NULL;
    char input[] = "(AA101, 18:30)|(BA205, 15:45)|(UA303, 20:15)";
    
    char *token = strtok(input, "|");
    while (token) {
        char fnumber[10], ftime[10];
        sscanf(token, "(%[^,], %[^)])", fnumber, ftime);
        append(&head, fnumber, ftime);
        token = strtok(NULL, "|");
    }

    printf("Unsorted:\n");
    print(head);

    head = mergeSort(head);

    printf("\nSorted:\n");
    print(head);

    return 0;
}
