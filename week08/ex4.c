#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>
#include <stdio.h>

int main(){
	const unsigned long mb10 = 10 * 1024 * 1024;
	char * mem = NULL;

	struct rusage using;
	
	for(int i = 0; i < 10; i++){
		mem = malloc(mb10);
		memset(mem, 0, mb10);
		getrusage(RUSAGE_SELF, &using);
		printf("Max resident set size: %ld\n", using.ru_maxrss);
		sleep(1);
	}
	return 0;
}