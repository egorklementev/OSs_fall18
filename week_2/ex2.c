#include <stdio.h>
#include <string.h>

int main ()
{
	char line[256];
	fgets(line, sizeof(line), stdin);

	// Reverse
	int size = strlen(line) - 1;
	char new_line[256];
	int index = 0;
	for (int i = size - 1; i >= 0; --i)
	{
		new_line[index] = line[i];
		index++;
	}
	new_line[size] = '\0';

	printf("%s", new_line);

	return 0;
}
