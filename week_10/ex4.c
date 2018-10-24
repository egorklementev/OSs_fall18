#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

int main()
{
	struct stat st[16];
	struct dirent *de;
	
	char directory[16];
	strcpy(directory, ".");

	DIR *dr = opendir(directory);

	if (dr == NULL)
	{
		printf("Could not open current directory.\n");
		return -1;
	}
	
	int i = 0;
	while ((de = readdir(dr)) != NULL)
	{
		printf("%s ", de->d_name);
		char next_file[16];
		strcpy(next_file, directory);
		strcat(next_file, de->d_name);
		stat(next_file, st + i);
		printf("%ld %ld\n", (st + i)->st_ino, (st + i)->st_nlink);
		i++;
	}
	
	closedir(dr);
	return 0;
}
