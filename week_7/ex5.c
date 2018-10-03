#include <stdio.h>
#include <stdlib.h>

int main() 
{
	char **s = malloc(sizeof(char *)); // There was no memory allocation
	char foo[] = "Hello World";
	*s = foo;
	
	printf("s is %ld\n", s); // I changed it to the long integer
	
	s[0] = foo;
	
	printf("s[0] is %s\n",s[0]);
	
	return(0);
}
