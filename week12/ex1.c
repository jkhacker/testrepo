#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	int fdrand = open("/dev/random", O_RDONLY);
	int fdfile = open("ex1.txt", O_CREAT, O_WRONLY);
	char *temp = malloc(20);
	read(fdrand, temp, 20);
	write(fdfile, temp, 20);
	return 0;
}