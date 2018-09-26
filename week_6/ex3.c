#include <signal.h>
#include <stdio.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0

int was_caught = FALSE;

void handle(int n) 
{
	was_caught = TRUE;
}

int main()
{   
 
	signal(SIGINT, handle);
 
    while(!was_caught) {
        printf("Waiting for the signal...\n");
        sleep(1);
    }
 
    printf("\nSIGINT signal was caught!\n");
	printf("Termination...\n");

    return 0;
}
