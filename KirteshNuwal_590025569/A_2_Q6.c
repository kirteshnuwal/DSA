/* 6.	Write a C program to implement a Circular Singly Linked List and perform all basic operations on it. The program must support the following operations:
->	Creation of a Circular Linked List
->	Insertion of a node (At the beginning and at the end of the list)
->	Deletion of a node (From the beginning and from the end of the list)
->	Traversal and display of the circular linked list and counting the number of nodes in the list.*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *last = NULL;

// Insert at End (also used for creation)
void insertEnd(int value) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;

    if (last == NULL) {
        last = newnode;
        last->next = last;
    } else {
        newnode->next = last->next;
        last->next = newnode;
        last = newnode;
    }
}

// Insert at Beginning
void insertBeginning(int value) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;

    if (last == NULL) {
        last = newnode;
        last->next = last;
    } else {
        newnode->next = last->next;
        last->next = newnode;
    }
}

// Delete from Beginning
void deleteBeginning() {
    if (last == NULL) return;

    struct node *temp = last->next;

    if (last == temp) {
        last = NULL;
    } else {
        last->next = temp->next;
    }
    free(temp);
}

// Delete from End
void deleteEnd() {
    if (last == NULL) return;

    struct node *temp = last->next;
    struct node *prev = NULL;

    if (last == temp) {
        free(last);
        last = NULL;
        return;
    }

    while (temp->next != last->next) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = last->next;
    free(temp);
    last = prev;
}

// Display and Count
void display() {
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = last->next;
    int count = 0;

    printf("List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
        count++;
    } while (temp != last->next);

    printf("(Back to Start)\n");
    printf("Total Nodes: %d\n", count);
}

int main() {

    insertEnd(10);
    insertEnd(20);
    insertEnd(30);

    insertBeginning(5);

    display();

    deleteBeginning();
    deleteEnd();

    display();

    return 0;
} 
