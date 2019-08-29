#include "stdio.h" 
#include "limits.h"
#include "float.h"

int main()
{
	int a = INT_MAX;
	float b = FLT_MAX;
	double c = DBL_MAX;
	printf("Max int: %d\nSize of int: %lu\n\n", a, sizeof(a) );
	printf("Max float: %f\nSize of float: %lu\n\n", b, sizeof(b) );
	printf("Max double: %f\nSize of double: %lu\n", c, sizeof(c) );
	return 0;
}