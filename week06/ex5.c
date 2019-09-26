#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
int main(){

	pid_t cpid;
	
	if ( ( cpid = fork() ) == -1) {
		perror("fork");
		return EXIT_FAILURE;
	}

	if (cpid == 0) {

		while(1) {
			printf("I'm your child, pls don't kill\n");
			sleep(1);
		}
		return EXIT_SUCCESS;

	} 
	else {
		sleep(10);
		kill(cpid, SIGTERM);
		return EXIT_SUCCESS;
	}
}