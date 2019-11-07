#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char** argv) {
	if(argc != 2 && argc != 3) {
		printf("Usage: %s [-a] [file]\n", argv[0]);
		printf("-a Append the output to the file rather than overwriting it");
		exit(1);
	}
	int fileind = argc - 1;
	char *fflag = "w";
	if(argc > 2 && !strcmp(argv[1], "-a")) {
		fflag = "a";
	}
	FILE *fout = fopen(argv[fileind], fflag);
// 
	// int fd = open(argv[i + offset], O_CREAT, oflag);
	
	
	char temp = 0;
	while(read(STDIN_FILENO, &temp, 1)) {
		fputc(temp, fout);
		write(STDOUT_FILENO, &temp, 1);
	}
	return 0;
}