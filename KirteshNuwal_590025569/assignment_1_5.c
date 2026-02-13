// 5.	Write a C program using structure and dynamic memory allocation to store and display student details such as roll number, name, and marks.

#include <stdio.h>
#include <stdlib.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

int main() {
    int n;

    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student *ptr = (struct Student *)malloc(n * sizeof(struct Student));

    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\nStudent %d\n", i + 1);

        printf("Enter Roll Number: ");
        scanf("%d", &ptr[i].roll);

        printf("Enter Name: ");
        scanf("%s", ptr[i].name);

        printf("Enter Marks: ");
        scanf("%f", &ptr[i].marks);
    }

    printf("\n----- Student Details -----\n");
    for (int i = 0; i < n; i++) {
        printf("\nStudent %d\n", i + 1);
        printf("Roll Number: %d\n", ptr[i].roll);
        printf("Name: %s\n", ptr[i].name);
        printf("Marks: %.2f\n", ptr[i].marks);
    }

    free(ptr);

    return 0;
}
