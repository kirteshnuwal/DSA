// 2.	Write a C program to implement a singly linked list and search for a given element in the list. If the element is found, display the position of the element in the linked list; otherwise, display element does not exit.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *newNode, *temp;
    int n, i, item, position = 1, found = 0;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i);
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while(temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    printf("Enter element to search: ");
    scanf("%d", &item);

    temp = head;
    while(temp != NULL) {
        if(temp->data == item) {
            found = 1;
            break;
        }
        temp = temp->next;
        position++;
    }

    if(found)
        printf("Element found at position %d\n", position);
    else
        printf("Element does not exist\n");

    return 0;
}
