#include <unistd.h>
#include <signal.h>
#include <stdio.h>

#define TRUE 1

int main()
{
	
	int child_pid;

	child_pid = fork();
	
	if (child_pid != 0)
	{
		sleep(10);
		kill(child_pid, SIGTERM);	
		printf("Child process was killed.\n");
	}
	else 
	{
		while (TRUE)
		{
			printf("I am alive!\n");
			sleep(1);
		}
	}

	printf("End of parent process.\n");

	return 0;
}
 
