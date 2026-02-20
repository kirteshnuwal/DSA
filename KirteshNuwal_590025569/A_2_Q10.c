// 10.	Write a C program to maintain Student Records using a Linked List. Each node should store student details such as roll number, name, and marks. Implement operations to insert, delete, search, and display records.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int roll;
    char name[30];
    float marks;
    struct student *next;
};

int main() {

    struct student *head, *second;

    head = (struct student*)malloc(sizeof(struct student));
    second = (struct student*)malloc(sizeof(struct student));

    head->roll = 1;
    strcpy(head->name, "Aman");
    head->marks = 85;
    head->next = second;

    second->roll = 2;
    strcpy(second->name, "Riya");
    second->marks = 90;
    second->next = NULL;

    struct student *temp = head;
    printf("Student Records:\n");
    while (temp != NULL) {
        printf("Roll: %d | Name: %s | Marks: %.2f\n",
               temp->roll, temp->name, temp->marks);
        temp = temp->next;
    }

    return 0;
}

