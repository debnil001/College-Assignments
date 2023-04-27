#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coefficient;
    int exponent;
    struct Node *next;
} Node;

Node *createNode(int coefficient, int exponent) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node **head, int coefficient, int exponent) {
    Node *newNode = createNode(coefficient, exponent);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void printList(Node *head) {
    if(head==NULL){
        printf("List is Empty\n");
        return;
    }
    Node *current = head;

    while (current != NULL) {
        printf("%dx^%d ", current->coefficient, current->exponent);
        if (current->next != NULL) {
            printf("+ ");
        }
        current = current->next;
    }
    printf("\n");
}

Node *addPolynomials(Node *p1, Node *p2) {
    Node *result = NULL;
    Node *current1 = p1;
    Node *current2 = p2;

    while (current1 != NULL && current2 != NULL) {
        if (current1->exponent > current2->exponent) {
            insertNode(&result, current1->coefficient, current1->exponent);
            current1 = current1->next;
        } 
        else if (current1->exponent < current2->exponent) {
            insertNode(&result, current2->coefficient, current2->exponent);
            current2 = current2->next;
        } 
        else {
            int sum = current1->coefficient + current2->coefficient;
            insertNode(&result, sum, current1->exponent);
            current1 = current1->next;
            current2 = current2->next;
        }
    }

    while (current1 != NULL) {
        insertNode(&result, current1->coefficient, current1->exponent);
        current1 = current1->next;
    }

    while (current2 != NULL) {
        insertNode(&result, current2->coefficient, current2->exponent);
        current2 = current2->next;
    }

    return result;
}
Node *subPolynomials(Node *p1, Node *p2) {
    Node *result = NULL;
    Node *current1 = p1;
    Node *current2 = p2;

    while (current1 != NULL && current2 != NULL) {
        if (current1->exponent > current2->exponent) {
            insertNode(&result, current1->coefficient, current1->exponent);
            current1 = current1->next;
        } else if (current1->exponent < current2->exponent) {
            insertNode(&result, current2->coefficient, current2->exponent);
            current2 = current2->next;
        } else {
            int sum = current1->coefficient - current2->coefficient;
            insertNode(&result, sum, current1->exponent);
            current1 = current1->next;
            current2 = current2->next;
        }
    }

    while (current1 != NULL) {
        insertNode(&result, current1->coefficient, current1->exponent);
        current1 = current1->next;
    }

    while (current2 != NULL) {
        insertNode(&result, current2->coefficient, current2->exponent);
        current2 = current2->next;
    }

    return result;
}
void removeDuplicates(Node* start){
    Node *ptr1, *ptr2, *dup;
    ptr1 = start;
    while (ptr1 != NULL && ptr1->next != NULL) {
        ptr2 = ptr1;
        while (ptr2->next != NULL) {
            if (ptr1->exponent == ptr2->next->exponent) {
                ptr1->coefficient = ptr1->coefficient + ptr2->next->coefficient;
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                free (dup);
            }
            else
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}
Node *multiplyPolynomials(Node *p1, Node *p2) {
    Node *result = NULL;
    Node *current1 = p1;

    while (current1 != NULL) {
        Node *current2 = p2;
        while (current2 != NULL) {
            int coefficient = current1->coefficient * current2->coefficient;
            int exponent = current1->exponent + current2->exponent;

            Node *node = result;
            while (node != NULL && node->exponent > exponent) {
                node = node->next;
            }

            if (node == NULL || node->exponent < exponent) {
                insertNode(&result, coefficient, exponent);
            } else {
                node->coefficient += coefficient;
            }

            current2 = current2->next;
        }
        current1 = current1->next;
    }

    return result;
}
int coef;
int expo;
void getInput(){
    printf("Enter Coefficient: ");
    scanf("%d",&coef);
    printf("Enter Exponent: ");
    scanf("%d",&expo);
}
int main() {
    Node *p1 = NULL;
    Node *p2 = NULL;
    Node *result = NULL;
    int choice;
    while (1){
        printf("1.Insert in polynomial 1::\n");
        printf("2.Insert in polynomial 2::\n");
        printf("3.Add two polynomials\n");
        printf("4.Subtract two polynomials\n");
        printf("5.Multiply two polynomials\n");
        printf("6.Display two polynomials\n");
        printf("Enter choice::");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            getInput();
            insertNode(&p1,coef,expo);
            break;
        case 2:
            getInput();
            insertNode(&p2,coef,expo);
            break;
        case 3:
            result=addPolynomials(p1,p2);
            removeDuplicates(result);
            printList(result);
            break;
            
        case 4:
            result= subPolynomials(p1,p2);
            removeDuplicates(result);
            printList(result);
            break;
        case 5:
            result=multiplyPolynomials(p1,p2);
            removeDuplicates(result);
            printList(result);
            break;
        case 6:
            printList(p1);
            printList(p2);
            break;
        case 0:
            exit(0);
        default:
            printf("Unknown");
            break;
        }
    }   
    return 0;
}