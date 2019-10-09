#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(){
	const unsigned long mb10 = 10 * 1024 * 1024;
	char * mem = NULL;
	
	for(int i = 0; i < 10; i++){
		mem = malloc(mb10);
		memset(mem, 0, mb10);
		sleep(1);
	}
	return 0;
}