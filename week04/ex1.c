#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "sys/types.h"

int main()
{
	pid_t n = fork();
	printf("Hello from child %d\n", n);
	return 0;
}