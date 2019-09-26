#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void catch_SIGINT()
{
	printf("\nI caught SIGINT!\n");
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
	signal(SIGINT, catch_SIGINT);
	sleep(10);
	return 0;
}