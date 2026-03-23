//4.	Write a program to check whether a given expression is balanced or not using a stack implemented with an array.

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
        return '\0';
    }
    return s->arr[(s->top)--];
}

char peek(Stack *s) {
    if (isEmpty(s)) {
        return '\0';
    }
    return s->arr[s->top];
}

int isOpening(char ch) {
    return (ch == '(' || ch == '[' || ch == '{');
}

int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

int isBalanced(char *expr) {
    Stack s;
    int i, len;
    char ch, top;
    initStack(&s);

    len = strlen(expr);

    for (i = 0; i < len; i++) {
        ch = expr[i];

        if (isOpening(ch)) {
            push(&s, ch);
            printf("  Push  : '%c'  |  Stack top: '%c'\n", ch, peek(&s));
        }
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (isEmpty(&s)) {
                printf("  Found '%c' but stack is empty — UNMATCHED!\n", ch);
                return 0;
            }
            top = pop(&s);
            if (!isMatchingPair(top, ch)) {
                printf("  Mismatch: '%c' does not match '%c'\n", top, ch);
                return 0;
            }
            printf("  Pop   : '%c' matched with '%c'\n", top, ch);
        }
    }

    return isEmpty(&s);
}

int main() {
    char expr[MAX_SIZE];
    int result;

    printf("===== BALANCED EXPRESSION CHECKER =====\n");
    printf("Enter an expression: ");
    fgets(expr, MAX_SIZE, stdin);

    expr[strcspn(expr, "\n")] = '\0';

    printf("\nExpression: %s\n", expr);
    printf("--- Stack Trace ---\n");

    result = isBalanced(expr);

    printf("-------------------\n");
    if (result) {
        printf("Result: BALANCED\n");
    } else {
        printf("Result: NOT BALANCED\n");
    }

    return 0;
}
