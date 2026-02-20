// 9.	Write a C program to represent and evaluate a Polynomial using a Linked List. Each node should represent a term containing coefficient and exponent.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node {
    int coeff, exp;
    struct node *next;
};

int main() {
    struct node *head = NULL, *temp;

    head = (struct node*)malloc(sizeof(struct node));
    head->coeff = 3; head->exp = 2;

    head->next = (struct node*)malloc(sizeof(struct node));
    head->next->coeff = 2; head->next->exp = 1;

    head->next->next = (struct node*)malloc(sizeof(struct node));
    head->next->next->coeff = 1; head->next->next->exp = 0;
    head->next->next->next = NULL;

    temp = head;
    printf("Polynomial: ");
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->exp);
        if (temp->next != NULL) printf(" + ");
        temp = temp->next;
    }

    int x = 2, result = 0;
    temp = head;
    while (temp != NULL) {
        result += temp->coeff * pow(x, temp->exp);
        temp = temp->next;
    }

    printf("\nValue at x = %d is: %d\n", x, result);

    return 0;
}
