#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>

#define MB_10 2621440

int main()
{
	int n = 0;
	int ** mem = malloc(10 * sizeof(int *));
	
	while (10 > n) 
	{
		*(mem + n) = malloc(MB_10 * sizeof(int));
		
		memset(*(mem + n), 0, MB_10 * sizeof(int));
		
		struct rusage mem_usg;	
		int result = getrusage(RUSAGE_SELF, &mem_usg);

		printf("Memory usage - %ld kB\n", mem_usg.ru_maxrss);
	
		n++;
		sleep(1);
	}

	return 0;
}
