//6.	Write a C program to evaluate a postfix expression using a stack implemented with an array. 
//(i)	Postfix Expression: 23*54*+9-
//(ii)	Result = 17

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *s)  { s->top = -1; }
int  isEmpty  (Stack *s)  { return s->top == -1; }
int  isFull   (Stack *s)  { return s->top == MAX_SIZE - 1; }

void push(Stack *s, int val) {
    if (!isFull(s))
        s->arr[++(s->top)] = val;
}

int pop(Stack *s) {
    if (!isEmpty(s))
        return s->arr[(s->top)--];
    return 0;
}

int peek(Stack *s) {
    if (!isEmpty(s))
        return s->arr[s->top];
    return 0;
}

int applyOp(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return (b != 0) ? a / b : 0;
        default : return 0;
    }
}

int evaluatePostfix(char *expr) {
    Stack s;
    int i, len, operand1, operand2, result;
    char ch;

    initStack(&s);
    len = strlen(expr);

    printf("\n%-6s %-10s %-35s %s\n",
           "Step", "Symbol", "Stack (bottom?top)", "Action");
    printf("------------------------------------------------------------------\n");

    for (i = 0; i < len; i++) {
        ch = expr[i];

        if (isdigit(ch)) {
            push(&s, ch - '0');

            printf("%-6d %-10c [", i + 1, ch);
            {
                int k;
                for (k = 0; k <= s.top; k++) {
                    printf("%d", s.arr[k]);
                    if (k < s.top) printf(", ");
                }
            }
            printf("]%-*s Push %d\n",
                   (int)(27 - s.top * 3), " ", ch - '0');
        }

        else if (ch=='+' || ch=='-' || ch=='*' || ch=='/') {
            operand2 = pop(&s);
            operand1 = pop(&s);
            result   = applyOp(operand1, operand2, ch);
            push(&s, result);

            printf("%-6d %-10c [", i + 1, ch);
            {
                int k;
                for (k = 0; k <= s.top; k++) {
                    printf("%d", s.arr[k]);
                    if (k < s.top) printf(", ");
                }
            }
            printf("] ");
            printf("Pop %d & %d ? %d %c %d = %d ? Push %d\n",
                   operand1, operand2,
                   operand1, ch, operand2,
                   result, result);
        }
    }

    return pop(&s);
}

int main() {
    char expr[MAX_SIZE];
    int  result;

    printf("====== POSTFIX EXPRESSION EVALUATOR ======\n");
    printf("Enter postfix expression: ");
    fgets(expr, MAX_SIZE, stdin);
    expr[strcspn(expr, "\n")] = '\0';

    result = evaluatePostfix(expr);

    printf("\n==========================================\n");
    printf("Postfix Expression : %s\n", expr);
    printf("Result             : %d\n", result);
    printf("==========================================\n");

    return 0;
}

