/* 7.	Write a C program to implement a Doubly Linked List. The program should perform all basic operations on the list. The program must support the following operations:
->	Creation of a Doubly Linked List, display and counting the number of nodes
->	Insertion of a node (At the beginning, At the end, After a given node)
->	Deletion of a node (From the beginning, From the end, of a given node)
->	Traversal of the list (Forward traversal and Backward traversal)*/

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
    newnode->next = NULL;

    if (head == NULL) {
        newnode->prev = NULL;
        head = newnode;
        return;
    }

    struct node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    newnode->prev = temp;
}

void deleteBeginning() {
    if (head == NULL) return;

    struct node *temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    free(temp);
}

void display() {
    struct node *temp = head;
    int count = 0;

    printf("List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        count++;
        temp = temp->next;
    }
    printf("NULL\n");
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
