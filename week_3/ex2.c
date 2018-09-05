#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int * const arr_p, int size);

int main()
{
	int n = 0;
	int * array;	

	printf("Enter number of elements in the array:\n");
	
	scanf("%d", &n);
	array = malloc(n * sizeof(int));	

	printf("Enter %d elements of this array:\n", n);
	for (int i = 0; i < n; ++i)
		scanf("%d", array + i);

	bubble_sort(array, n);
	
	printf("The array after bubble sort is:\n");
	for (int i = 0; i < n; ++i)
		printf("%d ", *(array + i));
	printf("\n");

	return 0;
}

void bubble_sort(int * const arr_p, int size)
{
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size - 1; ++j)
			if (*(arr_p + j) > *(arr_p + j + 1))
				{
				int temp = *(arr_p + j);
				*(arr_p + j) = *(arr_p + j + 1);
				*(arr_p + j + 1) = temp;
				}
}
