#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;

	printf("Enter the number of elements of the array:\n");
	scanf("%d", &n);

	int * arr = calloc(n, n * sizeof(int));
	
	for (int i = 0; i < n; ++i)
		*(arr + i) = i;

	for (int i = 0; i < n; ++i)
		printf("%d ", *(arr + i));

	printf("\n");
	
	free(arr);

	return EXIT_SUCCESS;
}
