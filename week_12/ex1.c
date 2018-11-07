#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define EXIT_ERROR -1

int main()
{
	int dev_rand = open("/dev/random", O_RDONLY);
	if (dev_rand < 0)
	{
		return EXIT_ERROR;
	}
	else
	{
		char rand_data[20];
		ssize_t result = read(dev_rand, rand_data, 20 * sizeof(char));
		if (result < 0) 
		{
			return EXIT_ERROR;	
		}
		else
		{
			printf("%s\n", rand_data);
		}
	}

	return 0;
}
