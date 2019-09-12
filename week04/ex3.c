#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main()
{
	const char str_exit[] = "exit";
	char command[100];
	scanf("%s", command);
	while(strcmp(str_exit, command) != 0)
	{
		system(command);
		scanf("%s", command);
	}
	return 0;
}