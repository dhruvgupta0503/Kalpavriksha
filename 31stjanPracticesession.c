#include <stdio.h>
#include <stdlib.h>

typedef struct Term {
    int coeff; 
    int power;
    struct Term* next;
} Term;

Term* createNode(int coeff, int power) {
    Term* newNode = (Term*)malloc(sizeof(Term));
    newNode->coeff = coeff;
    newNode->power = power;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Term** head, int coeff, int power) {
    Term* newNode = createNode(coeff, power);
    if (*head == NULL || (*head)->power < power) {
        newNode->next = *head;
        *head = newNode;
    } else {
        Term* temp = *head;
        while (temp->next != NULL && temp->next->power >= power) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void printPolynomial(Term* head) {
    while (head != NULL) {
        printf("%dx^%d", head->coeff, head->power);
        if (head->next != NULL) {
            printf(" + ");
        }
        head = head->next;
    }
    printf("\n");
}

Term* addPolynomial(Term* p1, Term* p2) {
    Term* result = NULL;
    while (p1 != NULL && p2 != NULL) {
        if (p1->power > p2->power) {
            insertNode(&result, p1->coeff, p1->power);
            p1 = p1->next;
        } else if (p1->power < p2->power) {
            insertNode(&result, p2->coeff, p2->power);
            p2 = p2->next;
        } else {
            int sum = p1->coeff + p2->coeff;
            if (sum != 0) {
                insertNode(&result, sum, p1->power);
            }
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1 != NULL) {
        insertNode(&result, p1->coeff, p1->power);
        p1 = p1->next;
    }

    while (p2 != NULL) {
        insertNode(&result, p2->coeff, p2->power);
        p2 = p2->next;
    }

    return result;
}

int main() {
    Term* poly1 = NULL;
    Term* poly2 = NULL;
    int n1, n2;

    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n1);
    printf("Enter the terms (coefficient and power) of the first polynomial:\n");
    for (int i = 0; i < n1; i++) {
        int coeff, power;
        printf("Term %d: ", i + 1);
        scanf("%d %d", &coeff, &power);
        insertNode(&poly1, coeff, power);
    }


    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n2);
    printf("Enter the terms (coefficient and power) of the second polynomial:\n");
    for (int i = 0; i < n2; i++) {
        int coeff, power;
        printf("Term %d: ", i + 1);
        scanf("%d %d", &coeff, &power);
        insertNode(&poly2, coeff, power);
    }

    Term* sum = addPolynomial(poly1, poly2);


    printf("The sum of the polynomials is: ");
    printPolynomial(sum);

    return 0;
}
