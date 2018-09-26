#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	int file_descriptors[2]; // 0 for input, 1 for output
	int child_pid;

	char * string = "text to be transfered\n";
	//char * input_string = malloc(256 * sizeof(char));
	char input_string[256];

	pipe(file_descriptors);

	child_pid = fork();
	if (child_pid == -1) {
		perror("fork");
		exit(1);
	}
	
	if (child_pid == 0) {
		close(file_descriptors[0]); // Close child input
		write(file_descriptors[1], string, (strlen(string) + 1));
		//free(input_string);
		exit(0);
	}
	else
	{
		close(file_descriptors[1]); // Close parent output
		read(file_descriptors[0], input_string, sizeof(input_string));
		printf("%s", input_string);
	}
	
	//free(input_string);

	return 0;
}
