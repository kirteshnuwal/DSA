// 5.	Write a C program to reverse the data of the nodes of a singly linked list without changing the links between the nodes.

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void reverseData(struct node *head) {
    int arr[100], i = 0, j;
    struct node *temp = head;

    // Store data in array
    while (temp != NULL) {
        arr[i++] = temp->data;
        temp = temp->next;
    }

    temp = head;
    j = i - 1;

    // Replace data in reverse order
    while (temp != NULL) {
        temp->data = arr[j--];
        temp = temp->next;
    }
}

int main() {
    struct node *head = NULL, *newnode, *temp;
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter value: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL)
            head = newnode;
        else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newnode;
        }
    }

    printf("Original List:\n");
    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    reverseData(head);

    printf("\nReversed Data List:\n");
    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    return 0;
}
