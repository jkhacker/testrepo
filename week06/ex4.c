#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void catch_SIGKILL()
{
	printf("\nI caught SIGKILL!\n");
}

void catch_SIGSTOP()
{
	printf("\nI caught SIGSTOP!\n");
}

void catch_SIGUSR1()
{
	printf("\nI caught SIGUSR1!\n");
}


int main()
{
	signal(SIGUSR1, catch_SIGUSR1);
	signal(SIGSTOP, catch_SIGSTOP);
	signal(SIGKILL, catch_SIGKILL);
	sleep(10);
	return 0;
}