#include <stdio.h>

char output[512];
char * func(int n);

int main()
{
	int size;
	scanf("%d", &size);

	printf("%s", func(size));
}

char * func(int n)
{
	int star_num = 2*n;
	int cur_stars = 1;
	int h = 0;	

	for (; cur_stars <= star_num; cur_stars += 2)
	{
		for (int i = 0; i < (star_num - cur_stars) / 2; ++i)
			output[star_num * h + i] = ' ';	
		
		for (int i = 0; i < cur_stars; ++i)
			output[star_num * h + (star_num - cur_stars) / 2 + i] = '*';
		
		for (int i = 0; i < (star_num - cur_stars) / 2; ++i)
			output[star_num * h + (star_num - cur_stars) / 2 + cur_stars + i] = ' ';

		output[star_num * (h + 1) - 1] = '\n';
	
		h++;
	}

	return output;
}
