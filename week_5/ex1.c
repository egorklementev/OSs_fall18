#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

long int * thread_id;

void * PrintHello(int i) 
{
	printf("Hello from thread %ld!\n", pthread_self());
	printf("Thread %ld was terminated.\n", pthread_self());
	pthread_exit(NULL);
}

int main(int argc, char * argv[])
{
	int n, rc;
	printf("Enter the number of threads:\n");
	scanf("%d", &n);
	thread_id = malloc(n * sizeof(int));
	for(int i = 0; i < n; ++i)
	{
		rc = pthread_create((thread_id + i), NULL, (void *) PrintHello, &i);
		if (rc) 
		{
			printf("\nERROR: return code from pthread_create is %d\n", rc);
			exit(1);
		}
		printf("\nThis is thread %ld. There was created new thread.\n", pthread_self());
		pthread_join(*(thread_id + i), NULL);
	}
	pthread_exit(NULL);
}
