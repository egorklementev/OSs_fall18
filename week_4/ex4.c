#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#define TRUE 1

int main(int argc, char *argv[], char *envp[])
{
	// Read command from the input
	char command[256];

	while(TRUE)
	{
		// Print shell symbols (like $ in Ubuntu)
		printf(">>> ");

		fgets(command, sizeof(command), stdin);
		
		// Background
		if(*(command + strlen(command) - 2) == '&')
		{
			int n = fork();
			int pid = getpid();
			if (n == 0) 
			{	
				system(command);
				execve("/home/erked/reps/OSs_fall18/week_4/ex4",argv,envp);
			} 
		}

		// Exit the shell
		if (!(strcmp(command, "exit\n"))) break;

		system(command);	
	}
	return 0;
}
