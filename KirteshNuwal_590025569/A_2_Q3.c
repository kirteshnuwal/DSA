/*3. Write a C program to implement insertion operations in a singly linked list. The program 
should perform the following operations: 
-> Insert a new element at the beginning of the linked list. 
-> Insert a new element at the end of the linked list. 
-> Insert a new element after a given node in the linked list. */

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

void insAtBeg(struct node **start, int val) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = val;
	newNode->next = *start;
	*start = newNode;
}

void insAtEnd(struct node **start, int val) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	struct node *ptr = *start;
	
	newNode->data = val;
	newNode->next = NULL;
	
	if (*start == NULL) {
		*start = newNode;
		return;
	}
	
	while (ptr->next != NULL)
		ptr = ptr->next;
		ptr->next = newNode;
} 

void insAfter(struct node *start, int key, int val) {
    struct node *ptr = start;

    while (ptr != NULL && ptr->data != key)
        ptr = ptr->next;

    if (ptr == NULL) {
        printf("Element not found\n");
        return;
    }

    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = ptr->next;
    ptr->next = newNode;
}

void display(struct node *start) {
    while (start != NULL) {
        printf("%d -> ", start->data);
        start = start->next;
    }
    printf("NULL\n");
}

int main() {
    struct node *start = NULL;

    insAtBeg(&start, 10);
    insAtEnd(&start, 20);
    insAtEnd(&start, 30);
    insAfter(start, 20, 25);

    printf("Linked List:\n");
    display(start);

    return 0;
} 
