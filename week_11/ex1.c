#include <stdlib.h>
#include <string.h>

#define BASEPORT 0x378

int main()
{
	if (ioperm(BASEPORT, 3, 1))
	{
		perror("ioperm");
		exit(1);
	}

	
	
	return 0;
}
