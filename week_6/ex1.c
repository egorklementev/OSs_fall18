#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main()
{
	int file_descriptors[2];
	
	char * to_transfer = "text to be transfered\n";
	char to_recieve[256];

	pipe(file_descriptors);

	write(file_descriptors[1], to_transfer, (strlen(to_transfer) + 1));
	read(file_descriptors[0], to_recieve, sizeof(to_recieve));

	printf("%s", to_recieve);

	return 0;
}
