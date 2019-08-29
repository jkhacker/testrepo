#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void triangle(int);

void ri_an_triangle(int);

void rect(int, int);

void square(int);

void diamond_square(int);

void print_help(void);

void arrow(int);

int main(int argc, char** argv)
{
	if(argc != 3 && argc != 4)
	{
		print_help();
		return 0;
	}
	if( !strcmp(argv[1], "triangle") )
	{
		if(argc != 3)
		{
			print_help();
			return 0;
		}
		triangle( atoi(argv[2]) );
	}
	else if( !strcmp(argv[1], "ri-an-triangle") )
	{
		if(argc != 3)
		{
			print_help();
			return 0;
		}
		ri_an_triangle( atoi(argv[2]) );
	}
	else if( !strcmp(argv[1], "rect") )
	{
		if(argc != 4)
		{
			print_help();
			return 0;
		}
		rect( atoi(argv[2]), atoi(argv[3]) );
	}
	else if( !strcmp(argv[1], "square") )
	{
		if(argc != 3)
		{
			print_help();
			return 0;
		}
		square( atoi(argv[2]) );
	}
	else if( !strcmp(argv[1], "diamond-square") )
	{
		if(argc != 3)
		{
			print_help();
			return 0;
		}
		diamond_square( atoi(argv[2]) );
	}
	else if( !strcmp(argv[1], "arrow") ) {
		if(argc != 3)
		{
			print_help();
			return 0;
		}
		arrow( atoi(argv[2]) );
	}
	else
	{
		print_help();	
	}
	return 0;
}


void print_help()
{
	printf("Usage: \n");
	printf("./ex5 triangle n - prints right triangle with size n\n");
	printf("./ex5 ri-an-triangle n - prints right angled triangle with size n\n");
	printf("./ex5 rect n m - prints rectangle with size nXm\n");
	printf("./ex5 square n - prints square with size n\n");
	printf("./ex5 diamond-square n - prints diamond square with size n\n");
	printf("./ex5 arrow n - prints arrow with size n\n");
}

void triangle(int n)
{
	if(n < 1)
	{
		print_help();
		return;
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n - 1 - i; j++)
		{
			putc(' ', stdout);
		}
		for(int j = 0; j < 1 + i*2; j++)
		{
			putc('*', stdout);
		}
		printf("\n");
	}
}

void ri_an_triangle(int n)
{
	if(n < 1)
	{
		print_help();
		return;
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < 1 + i; j++)
		{
			putc('*', stdout);
		}
		printf("\n");
	}
}

void arrow(int n)
{
	if(n < 1)
	{
		print_help();
		return;
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < 1 + i; j++)
		{
			putc('*', stdout);
		}
		printf("\n");
	}
	for(int i = n - 2; i >= 0; i--)
	{
		for(int j = 0; j < 1 + i; j++)
		{
			putc('*', stdout);
		}
		printf("\n");
	}
}

void rect(int n, int m)
{
	if(n < 1 || m < 1)
	{
		print_help();
		return;
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			putc('*', stdout);
		}
		printf("\n");
	}
}

void square(int n)
{
	rect(n, n);
}

void diamond_square(int n)
{
	if(n < 1)
	{
		print_help();
		return;
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n - 1 - i; j++)
		{
			putc(' ', stdout);
		}
		for(int j = 0; j < 1 + i*2; j++)
		{
			putc('*', stdout);
		}
		printf("\n");
	}
	for(int i = n - 1; i >= 0; i--)
	{
		for(int j = 0; j < n - 1 - i; j++)
		{
			putc(' ', stdout);
		}
		for(int j = 0; j < 1 + i*2; j++)
		{
			putc('*', stdout);
		}
		printf("\n");
	}
}