#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]){
	int pipefd[2];
	pid_t cpid;
	char buf[50];

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <string>\n", argv[0]);
		return EXIT_FAILURE;
	}

	if (pipe(pipefd) == -1) {
		perror("pipe");
		return EXIT_FAILURE;
	}

	if ( ( cpid = fork() ) == -1) {
		perror("fork");
		return EXIT_FAILURE;
	}

	if (cpid == 0) {
		close(pipefd[1]);

		read(pipefd[0], buf, strlen(buf) + 1);
		printf("%s\n", buf);
		close(pipefd[0]);
		return 0;

	} else {
		close(pipefd[0]);
		write(pipefd[1], argv[1], strlen(argv[1]) + 1);		
		close(pipefd[1]);
		wait(NULL);
		return 0;
	}
}