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
    Term* temp = NULL;

    
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
   
    
    Term* k1 = NULL;
    
    insertNode(&k1, 2, 3);
    insertNode(&k1, 3, 1);
    insertNode(&k1, 1, 0);
 

    Term* k2 = NULL;
    insertNode(&k2, 3, 4);
    insertNode(&k2, 2, 2);
    insertNode(&k2, -1, 1);
 

   Term* sum = addPolynomial(k1, k2);

  printPolynomial(sum);

    return 0;
}
