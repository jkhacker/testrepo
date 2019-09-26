#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int fd[2], nbytes;
	
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <string>\n", argv[0]);
		exit(EXIT_FAILURE);
	}	

	char buffer[80];
	
	if (pipe(fd) == -1) {
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	
	write(fd[1], argv[1], (strlen(argv[1])+1));
	nbytes = read(fd[0], buffer, sizeof(buffer));
	printf("%s", buffer);
	close(fd[0]);
	close(fd[1]);

	return 0;
	
}