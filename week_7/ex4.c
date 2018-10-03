#include <stdio.h>
#include <stdlib.h>

int * my_realloc(int * ptr, int new_size);

int main()
{
	int * arr = calloc(10,10*sizeof(int));	
	
	arr = my_realloc(arr, 15);	

	return EXIT_SUCCESS;
}

int * my_realloc(int * ptr, int new_size)
{
	if (new_size == 0) 
	{
		free(ptr);
		return ptr;
	}
	else
	{	
		int * new_ptr = malloc(sizeof(new_size));
	
		if (!(ptr == NULL))
			for (int i = 0; i < new_size; ++i)
				*(new_ptr + i) = *(ptr + i);
	
		free(ptr);
		
		return new_ptr;
	}
	return ptr;
}
