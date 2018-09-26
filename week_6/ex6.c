#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>

#define TRUE 1

int main()
{

	int file_d[2];

	int c1_pid, c2_pid;
	int status;

	pipe(file_d);

	printf("Creation of the first child...\n");
	c1_pid = fork();
	
	if (c1_pid == 0)
	{	
		close(file_d[1]);

		printf("I am the first child.\n");
		printf("In 3 seconds I will pause the second child.\n");

		sleep(3);

		read(file_d[0], &c2_pid, sizeof(c2_pid));	
		close(file_d[0]);		

		printf("Pausing (PID - %d) process...\n", c2_pid);
		kill(c2_pid, SIGSTOP);

		exit(0);
	}
	else 
	{
		printf("Creation of the second child...\n");
		c2_pid = fork();

		if (c2_pid == 0)
		{
			close(file_d[0]);
			close(file_d[1]);

			while (TRUE) 
			{	
				sleep(1);
				printf("I am the second child (PID - %d)!\n", getpid());	
			}
		}
		else
		{
			close(file_d[0]);
			write(file_d[1], &c2_pid, sizeof(c2_pid));

			printf("Main process is waiting...\n");
			printf("Waiting of the process (PID - %d) is over\n", 		
				waitpid(c2_pid, &status, 0));	
			printf("Shutting down...\n");
			exit(status);
		}
	}	

	return 0;
}
