#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void do_something()
{
	printf("\nI caught SIGINT!\n");
}

int main()
{
	signal(SIGINT, do_something);
	sleep(10);
	return 0;
}