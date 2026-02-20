/* 8.	Write a C program to implement a Doubly Circular Linked List. The program should perform all basic operations on the list. The program must support the following operations:
->	Creation of a Doubly Circular Linked List, display and counting the number of nodes
->	Insertion of a node (At the beginning, At the end)
->	Deletion of a node (From the beginning, From the end)*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void insertEnd(int value) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;

    if (head == NULL) {
        head = newnode;
        head->next = head;
        head->prev = head;
    } else {
        struct node *last = head->prev;

        newnode->next = head;
        newnode->prev = last;

        last->next = newnode;
        head->prev = newnode;
    }
}

void deleteBeginning() {
    if (head == NULL) return;

    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        struct node *last = head->prev;
        struct node *temp = head;

        head = head->next;
        head->prev = last;
        last->next = head;

        free(temp);
    }
}

void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head;
    int count = 0;

    printf("List: ");
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
        count++;
    } while (temp != head);

    printf("(Back to Head)\n");
    printf("Total Nodes: %d\n", count);
}

int main() {

    insertEnd(10);
    insertEnd(20);
    insertEnd(30);

    display();

    deleteBeginning();

    display();

    return 0;
}
