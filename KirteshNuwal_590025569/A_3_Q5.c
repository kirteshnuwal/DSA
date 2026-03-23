//5.	Write a C program to convert a given infix expression (A+B*(C^D-E)^(F+G*H)-I) into its corresponding postfix expression (ABCD^E-FGH*+^*+I-) using a stack implemented with arrays.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    char arr[MAX_SIZE];
    int  top;
} Stack;

void initStack(Stack *s)        { s->top = -1; }
int  isEmpty  (Stack *s)        { return s->top == -1; }
int  isFull   (Stack *s)        { return s->top == MAX_SIZE - 1; }

void push(Stack *s, char ch) {
    if (!isFull(s))  s->arr[++(s->top)] = ch;
}

char pop(Stack *s) {
    if (!isEmpty(s)) return s->arr[(s->top)--];
    return '\0';
}

char peek(Stack *s) {
    if (!isEmpty(s)) return s->arr[s->top];
    return '\0';
}

int precedence(char op) {
    if (op == '+' || op == '-')  return 1;
    if (op == '*' || op == '/')  return 2;
    if (op == '^')               return 3;
    return 0;
}

int isRightAssociative(char op) {
    return op == '^';
}

int isOperator(char ch) {
    return (ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^');
}

void infixToPostfix(char *infix, char *postfix) {
    Stack s;
    int i, j;
    char ch, top;

    initStack(&s);
    i = 0;
    j = 0;

    printf("\n%-6s %-12s %-30s %s\n",
           "Step", "Symbol", "Stack (bottom?top)", "Postfix so far");
    printf("---------------------------------------------------------------\n");

    while (infix[i] != '\0') {
        ch = infix[i];

        if (isalnum(ch)) {
            postfix[j++] = ch;
        }

        else if (ch == '(') {
            push(&s, ch);
        }

        else if (ch == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s);
        }

        else if (isOperator(ch)) {
            while (!isEmpty(&s) && isOperator(peek(&s)) &&
                   (precedence(peek(&s)) > precedence(ch) ||
                   (precedence(peek(&s)) == precedence(ch) &&
                    !isRightAssociative(ch)))) {
                postfix[j++] = pop(&s);
            }
            push(&s, ch);
        }

        postfix[j] = '\0';
        printf("%-6d %-12c ", i + 1, ch);

        int k;
        char stackStr[MAX_SIZE];
        int  sLen = 0;
        for (k = 0; k <= s.top; k++) stackStr[sLen++] = s.arr[k];
        stackStr[sLen] = '\0';
        printf("%-30s %s\n", sLen ? stackStr : "(empty)", postfix);

        i++;
    }

    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);

        postfix[j] = '\0';
        printf("%-6s %-12s %-30s %s\n",
               "-", "pop remaining",
               isEmpty(&s) ? "(empty)" : "...",
               postfix);
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];

    printf("====== INFIX TO POSTFIX CONVERTER ======\n");
    printf("Enter infix expression: ");
    fgets(infix, MAX_SIZE, stdin);
    infix[strcspn(infix, "\n")] = '\0';

    infixToPostfix(infix, postfix);

    printf("\n========================================\n");
    printf("Infix   Expression : %s\n", infix);
    printf("Postfix Expression : %s\n", postfix);
    printf("========================================\n");

    return 0;
}
