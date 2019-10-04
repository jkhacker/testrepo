#include <stdio.h>
#include <stdlib.h>

void* my_realloc(void* ptr, size_t size, size_t prev) {
	void* new_ptr = NULL;
	if(size != 0) {
		new_ptr = malloc(size);
	}
	if(ptr != NULL) {
		for(size_t i = 0; i < prev; i++) {
			*((char*) new_ptr + i) = *((char*) ptr + i);
		}
		free(ptr);
	}
	return new_ptr;
}

int main() {
	int* a = my_realloc(NULL, 20, 0);
	return 0;
}