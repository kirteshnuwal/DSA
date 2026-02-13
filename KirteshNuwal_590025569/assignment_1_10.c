// 10.	Write a C program using structure and dynamic memory allocation to sort student record based on marks.

#include <stdio.h>
#include <stdlib.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

int main() {
    int n, i, j;

    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student *ptr = (struct Student*)malloc(n * sizeof(struct Student));

    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("\nStudent %d\n", i + 1);

        printf("Enter Roll: ");
        scanf("%d", &ptr[i].roll);

        printf("Enter Name: ");
        scanf("%s", ptr[i].name);

        printf("Enter Marks: ");
        scanf("%f", &ptr[i].marks);
    }

    struct Student temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (ptr[j].marks > ptr[j + 1].marks) {
                temp = ptr[j];
                ptr[j] = ptr[j + 1];
                ptr[j + 1] = temp;
            }
        }
    }

    printf("\n--- Students Sorted by Marks (Ascending) ---\n");
    for (i = 0; i < n; i++) {
        printf("\nRoll: %d", ptr[i].roll);
        printf("\nName: %s", ptr[i].name);
        printf("\nMarks: %.2f\n", ptr[i].marks);
    }

    free(ptr);

    return 0;
}
