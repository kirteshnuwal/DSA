// write a program to swap two numbers using temp variables.

#include <stdio.h>

int main() {
	
	int a, b, temp;
	
	printf("Enter the first number: ");
	scanf("%d", &a);
	
	printf("Enter the second number: ");
	scanf("%d", &b);
	
	temp = a;
	a = b;
	b = temp;
	
	printf("%d", a);
	printf("%d", b); 
	
	return 0;
	
}
