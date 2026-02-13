// 6.	Write a C program using array of structures with dynamic memory allocation to store employee details and find the employee with the highest salary.

#include <stdio.h>
#include <stdlib.h>

struct Employee {
    int id;
    char name[50];
    float salary;
};

int main() {
    int n;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    struct Employee *emp = (struct Employee *)malloc(n * sizeof(struct Employee));

    if (emp == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\nEmployee %d\n", i + 1);

        printf("Enter ID: ");
        scanf("%d", &emp[i].id);

        printf("Enter Name: ");
        scanf("%s", emp[i].name);

        printf("Enter Salary: ");
        scanf("%f", &emp[i].salary);
    }

    int maxIndex = 0;

    for (int i = 1; i < n; i++) {
        if (emp[i].salary > emp[maxIndex].salary) {
            maxIndex = i;
        }
    }

    printf("\nEmployee with Highest Salary:\n");
    printf("ID: %d\n", emp[maxIndex].id);
    printf("Name: %s\n", emp[maxIndex].name);
    printf("Salary: %.2f\n", emp[maxIndex].salary);

    free(emp);

    return 0;
}
