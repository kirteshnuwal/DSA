#include <stdio.h>

int main() {
    int n, i;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n <= 1) {
        printf("%d is not a prime number", n);
        return 0;
    }

    for (i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            printf("%d is not a prime number", n);
            return 0;
        }
    }

    printf("%d is a prime number", n);
    return 0;
}
