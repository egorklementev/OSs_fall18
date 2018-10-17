#include <stdio.h>
#include <stdlib.h>

// Comaration of binary numbers in string representation
int cmp(char * num1, char * num2, int size) 
{
	for (int i = size - 1; i >= 0; --i)
	{
		if (*(num1 + i) == '0' && *(num2 + i) == '0' ||
				*(num1 + i) == '1' && *(num2 + i) == '1')
		{
			continue;
		}
		else if(*(num1 + i) == '1' && *(num2 + i) == '0')
		{
			return 1; // num1 > num2
		}
		else if (*(num1 + i) == '0' && *(num2 + i) == '1')
		{
			return -1; // num1 < num2
		}
	}
	return 0; // num1 == num2
}

int main()
{
	FILE * f_in = fopen("Lab 09 input.txt", "r");

	int page_frames = 0;

	int miss = 0;
	int hit = 0;

	printf("Enter number of page frames:\n");
	scanf("%d", &page_frames);

	int cur_page_size = 0;
	int cur_pages[page_frames];
	char ** ref_data = malloc(page_frames * sizeof(char *));	

	for (int i = 0; i < page_frames; ++i)
	{
		*(ref_data + i) = malloc(1000 * sizeof(char));
	}		

	int next = 0;
	int index = 0;
	while (fscanf(f_in, "%d", &next) != EOF) 
	{	
		if (cur_page_size < page_frames)
		{
			if (cur_page_size == 0)
			{	
				// EMPTY PAGE TABLE == MISS
				*(cur_pages) = next;
				*(*(ref_data)) = '1';
				cur_page_size++;
				miss++;
			}
			else
			{
				int was_in_table = 0;
				for (int i = 0; i < cur_page_size; ++i)
				{
					if (*(cur_pages + i) != next)
					{
						*(*(ref_data + i) + index) = '0';
					}
					else
					{
						*(*(ref_data + i) + index) = '1';
						was_in_table = 1;
					}
				}
				if (!was_in_table)
				{
					// MISS
					*(cur_pages + cur_page_size) = next;
					for (int i = 0; i < index; ++i)
					{
						*(*(ref_data + cur_page_size) + i) = '0';
					}
					*(*(ref_data + cur_page_size) + index) = '1';
					cur_page_size++;
					miss++;
				} 
				else 
				{
					// HIT
					hit++;
				}
			}
		}
		else
		{
			int was_in_table = 0;
			for (int i = 0; i < page_frames; ++i)
			{
				if (next == *(cur_pages + i))
				{
					*(*(ref_data + i) + index) = '1';
					was_in_table = 1;
				}
				else
				{
					*(*(ref_data + i) + index) = '0';
				}
			}
			if (was_in_table)
			{
				// HIT
				hit++;
			}
			else
			{
				// MISS
				int to_replace = 0;
				for (int i = 0; i < page_frames; ++i)
				{
					if (cmp(*(ref_data + to_replace), *(ref_data + i), index + 1) == 1)
					{
						to_replace = i;	
					}
				}
				for (int i = 0; i < index; ++i)
				{
					*(*(ref_data + to_replace) + i) = '0';
				}
				*(*(ref_data + to_replace) + index) = '1';	
				miss++;
			}
		}
		index++;
	}

	fclose(f_in);
	
	printf("%f\n", ((float)hit / (float)miss));

	free(ref_data);

	return 0;
}
