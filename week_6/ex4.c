#include <signal.h>
#include <stdio.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0

int was_caught_sigkill = FALSE;
int was_caught_sigstop = FALSE;
int was_caught_sigusr1 = FALSE;

void handle_sigkill(int n) 
{
	was_caught_sigkill = TRUE;
}
void handle_sigstop(int n) 
{
	was_caught_sigstop = TRUE;
}
void handle_sigusr1(int n) 
{
	was_caught_sigusr1 = TRUE;
}

int main()
{   
 
	signal(SIGKILL, handle_sigkill);
	signal(SIGSTOP, handle_sigstop);
	signal(SIGUSR1, handle_sigusr1);
 
    while(!(was_caught_sigkill || was_caught_sigstop || was_caught_sigusr1)) {
        sleep(1);
    }
 
	if(was_caught_sigkill)
	{
    	printf("\nSIGKILL signal was caught!\n");
	}
	else if(was_caught_sigstop)
	{
    	printf("\nSIGSTOP signal was caught!\n");
	}
	else if(was_caught_sigusr1)
	{
    	printf("\nSIGUSR1 signal was caught!\n");
	}
	printf("Termination...\n");

    return 0;
}
