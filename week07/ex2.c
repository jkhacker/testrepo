#include <stdio.h>
#include <stdlib.h>

int main() {
	int N = 0;
	
	printf("Please, enter size of an array: ");
	scanf("%d", &N);
	
	int *arr = calloc(N, sizeof(int));
	
	for(int i = 0; i < N; i++) {
		arr[i] = i;
		printf("%d ", arr[i]);
	}
	
	free(arr);
	
	return 0;
}
