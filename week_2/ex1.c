#include <stdio.h>
#include <float.h>
#include <limits.h>

int main ()
{
	int var_int = INT_MAX;
	float var_float = FLT_MAX;
	double var_double = DBL_MAX;

	printf("Size of integer: %ld bytes\n", sizeof(var_int));
	printf("Max value of integer: %d\n\n", var_int);

	printf("Size of float: %ld bytes\n", sizeof(var_float));
	printf("Max value of float: %f\n\n", var_float);

	printf("Size of double: %ld bytes\n", sizeof(var_double));
	printf("Max value of double: %f\n", var_double);

	return 0;
}
