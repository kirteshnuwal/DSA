// 8.	Write a C program to demonstrate the use of union by storing integer, float, and character data and explain memory sharing.

#include <stdio.h>

union Data {
    int i;
    float f;
    char ch;
};

int main() {
    union Data d;

    d.i = 10;
    printf("Integer value: %d\n", d.i);

    d.f = 25.5;
    printf("Float value: %.2f\n", d.f);

    d.ch = 'A';
    printf("Character value: %c\n", d.ch);

    printf("\nSize of union: %lu bytes\n", sizeof(d));

    return 0;
}
