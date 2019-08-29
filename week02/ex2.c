#include "stdio.h"
#include "string.h"

void swap(char* a, char* b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	char str[100];
	unsigned long len = 0;
	scanf("%s", str);
	for(unsigned long i = 0; i < (strlen(str)-1)/2; i++)
	{
		len = strlen(str) - 1 - i;
		swap(&str[i], &str[len]);
	}
	printf("%s\n", str);
	return 0;
}