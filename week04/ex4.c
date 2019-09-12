#include "stdio.h"
#include "stdlib.h"

int main()
{
	printf("For exit please use C-c\n");
	char command[100];
	printf("mysh 1.0 > ");
	while(!fgets(command, 100, stdin))
	{
		printf("Something went wrong. Try again\n");
	}
	while(1)
	{
		system(command);
		printf("mysh 1.0 > ");
		while(!fgets(command, 100, stdin))
			{
				printf("Something went wrong. Try again\n");
			}
	}
	return 0;
}