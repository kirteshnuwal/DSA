//2.	Write a C program to implement a Stack using a Linked List. The program should support the following operations using separate functions:
//(i)	Push (Insert): Insert an element into the stack.
//(ii)	Pop (Delete): Remove an element from the stack.
//(iii)	Display: Display all elements of the stack.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
} Stack;

void initStack(Stack *s) {
    s->top = NULL;
}

int isEmpty(Stack *s) {
    return s->top == NULL;
}

void push(Stack *s, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed! Cannot push %d\n", value);
        return;
    }
    newNode->data  = value;
    newNode->next  = s->top;
    s->top         = newNode;
    printf("Pushed: %d\n", value);
}

void pop(Stack *s) {
    Node *temp;
    if (isEmpty(s)) {
        printf("Stack Underflow! Stack is empty.\n");
        return;
    }
    temp   = s->top;
    printf("Popped: %d\n", temp->data);
    s->top = s->top->next;
    free(temp);
}

void display(Stack *s) {
    Node *current;
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack (Top to Bottom): ");
    current = s->top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void freeStack(Stack *s) {
    Node *temp;
    while (s->top != NULL) {
        temp   = s->top;
        s->top = s->top->next;
        free(temp);
    }
}

int main() {
    Stack s;
    int choice, value;
    initStack(&s);

    do {
        printf("\n===== STACK MENU =====\n");
        printf("1. Push (Insert)\n");
        printf("2. Pop (Delete)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&s, value);
                break;
            case 2:
                pop(&s);
                break;
            case 3:
                display(&s);
                break;
            case 4:
                freeStack(&s);
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
