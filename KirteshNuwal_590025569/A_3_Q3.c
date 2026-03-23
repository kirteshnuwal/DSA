//3.	Write a C program to reverse a given string using a stack. The program should follow the Last In First Out (LIFO) principle of the stack.

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char arr[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, char ch) {
    if (isFull(s)) {
        printf("Stack Overflow!\n");
        return;
    }
    s->arr[++(s->top)] = ch;
}

char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        return '\0';
    }
    return s->arr[(s->top)--];
}

void reverseString(char *str) {
    Stack s;
    int i, len;
    initStack(&s);

    len = strlen(str);

    printf("\nPushing characters onto stack:\n");
    for (i = 0; i < len; i++) {
        push(&s, str[i]);
        printf("  Pushed: '%c'\n", str[i]);
    }

    printf("\nPopping characters from stack:\n");
    for (i = 0; i < len; i++) {
        str[i] = pop(&s);
        printf("  Popped: '%c'\n", str[i]);
    }
}

int main() {
    char str[MAX_SIZE];

    printf("===== STRING REVERSAL USING STACK =====\n");
    printf("Enter a string: ");
    fgets(str, MAX_SIZE, stdin);

    str[strcspn(str, "\n")] = '\0';

    printf("\nOriginal String : %s", str);

    reverseString(str);

    printf("\nReversed String : %s\n", str);

    return 0;
}
