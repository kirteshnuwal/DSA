// 9.	Write a C program to show the difference in memory allocation between structure and union using sizeof().

#include <stdio.h>

struct StudentStruct {
    int roll;
    float marks;
    char grade;
};

union StudentUnion {
    int roll;
    float marks;
    char grade;
};

int main() {

    printf("Size of Structure: %lu bytes\n", sizeof(struct StudentStruct));
    printf("Size of Union: %lu bytes\n", sizeof(union StudentUnion));

    return 0;
}
