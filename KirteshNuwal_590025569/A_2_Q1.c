// 1.	Write a C program to traverse a singly linked list and count the number of nodes present in the list.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *second = NULL, *third = NULL;
    int count = 0;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    struct Node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    printf("Total nodes = %d", count);

    return 0;
}
