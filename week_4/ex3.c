#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define TRUE 1

void main()
{
	// Read command from the input
	char command[256];

	while(TRUE)
	{
		// Print shell symbols (like $ in Ubuntu)
		printf(">>> ");

		fgets(command, sizeof(command), stdin);
		
		// Exit the shell
		if (!(strcmp(command, "exit\n"))) break;

		system(command);	
	}

}
