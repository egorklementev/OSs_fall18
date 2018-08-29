#include <stdio.h>

void swap(int * a, int * b);

int main()
{
	int a, b;

	printf("Enter two integer numbers:\n");

	scanf("%d%d", &a, &b);
	
	swap(&a, &b);

	printf("Swapped numbers are: %d %d\n", a, b);	
}

void swap(int * a, int * b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
