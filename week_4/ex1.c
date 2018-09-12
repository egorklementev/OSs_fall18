#include <stdio.h>

void main()
{
	int n;
	int pid = getpid();
	n = fork();
	if (pid == 0)	
		printf("Hello from child  [%d - %d]\n", pid, n);
	else
		printf("Hello from parent [%d - %d]\n", pid, n);
}
