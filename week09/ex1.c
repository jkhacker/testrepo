#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#ifndef WRONG_USAGE
#define WRONG_USAGE 0
#endif
#ifndef JUST_ERROR
#define JUST_ERROR 1
#endif
#ifndef EXIT_ERROR
#define EXIT_ERROR 1
#endif
#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif

typedef struct _page_table {
	int *table;
	unsigned char *counters;
	int size;
} ptable;

/*
/############################################
/										   //
/ Just tools prototypes					   //
/										   //
*/										   //
										   //
char *program_name;						   //
										   //
void init_table(ptable *table, int size);  //
										   //
int is_str_unumber(char* str);			   //
										   //
void az_5(int i);						   //
										   //
void process_input(int **data, int *size); //
										   //
int cmp(const void *a, const void *b);     //
										   //
int min_char(unsigned char *arr, int size);//
										   //
/*										   //
/										   //
/ Just tools prototypes					   //
/										   //
/############################################
*/

int main(int argc, char **argv) {
	program_name = argv[0];
	if(argc != 2 || !is_str_unumber(argv[1])) { // Checking if args are ok
		az_5(WRONG_USAGE);						// Stopps program if something is not
												// ok
	}
	
	int num_of_pages = atoi(argv[1]);

	if(num_of_pages < 1) {
		az_5(WRONG_USAGE);
	}

	ptable table;								// Pages table

	init_table(&table, num_of_pages);
	printf("");									// Without it SIGTERM occurs if num_of_pages>=260. I don't know why

	int *data = NULL;							// Array with input pages numbers
	int size = 0;								// Size (in ints, not bytes) of previous
												// array
	int hit = 0;
	int miss = 0;
	int pages_counter = 1;						// Crutch
	int min = 0;								// This var will contain min counter in table
	void* pos = NULL;
	
	int* flags = malloc( num_of_pages*sizeof(int) ); // For flagging changed entries in table
	memset( flags, 0, num_of_pages*sizeof(int) );
	
	process_input(&data, &size);

	for(int i = 0; i < size; i++) {
		pos = bsearch((data + i), table.table, (size_t)table.size, sizeof(int), cmp); // Trying to search current page in the table
		if( !pos ) {																  // Page fault occurs
			miss++;
			min = min_char(table.counters, table.size);
			table.table[min] = data[i];
			flags[min] = 1;
		}
		else {																		  // Hit occurs
			hit++;
			flags[(int)((long)(table.table) - (long)pos)] = 1;						  // This: flags[something], where something - index of current page in table
		}
		if(															       			  //									
			pages_counter%num_of_pages == 0 ||						                  // I'm very sorry for this
		    (														                  // It should emulate clock ticking
		    	size/num_of_pages == pages_counter/num_of_pages &&	                  // I'm really sorry
		     	pages_counter%num_of_pages == size%num_of_pages		                  //
		    )
		  ) {
			for(int j = 0; j < num_of_pages; j++) {
				table.counters[j] >>= 1;
				if(flags[j]) {
					table.counters[j] |= 0x80;
				}
			}
			memset( flags, 0, num_of_pages*sizeof(int) );
		}
		pages_counter++;
	}

	printf("%f", (double)hit/(double)miss);

	return EXIT_SUCCESS;
} 

/*
/########################################
/
/ Code below is just useful (and properly tested) tools for me
/ It should not disturb you
/
/########################################
*/

void init_table(ptable *table, int size) {
	table->table = malloc(size*sizeof(int));
	table->counters = malloc(size*sizeof(unsigned char));
	
	if(!table->table || !table->counters) {
		az_5(JUST_ERROR);
	}
	
	for(int i = 0; i < size; i++) {
		table->table[i] = i;
	}
	memset(table->counters, 0, size);

	table->size = size;
}

int is_str_unumber(char* str) {
	if(!str) {
		return 0;
	}
	for(unsigned long i = 0; i < strlen(str); i++) {
		if(!isdigit(str[i])) {
			return 0;
		}
	}
	return 1;
}

void az_5(int i) { // function name is just a stupid "Chernobyl" series reference, don't mind
	switch(i) {
		case WRONG_USAGE:
			printf("Usage: %s [number of pages]\n", program_name);
			printf("File with page numbers should be called input.txt and should be present in current directory\n");
			printf("File should be not empty and contain >=[number of pages] amount of numbers (only numbers!)");
			exit(EXIT_ERROR);
			break;
		case JUST_ERROR:
			printf("Some error just occured. Not great but not terrible, please try again");
			exit(EXIT_ERROR);
			break;
	}
}

void process_input(int **data, int *size) {
	FILE *fin = fopen("input.txt", "r");
	if(!fin) {
		az_5(WRONG_USAGE);
	}
	char c = 0;
	char prev_c = 0;
	long pos = ftell(fin);
	int str_len = 0;
	char *str = NULL;
	int num_count = 0;
	c = fgetc(fin);
	while( c != -1 && c != 0 && c != 0x0A) {
		if(!isdigit(c) && c != ' ') {
			az_5(WRONG_USAGE);
		}
		if(prev_c == ' ' && c == '0') {
			az_5(WRONG_USAGE);
		}
		prev_c = c;
		str_len++;
		c = fgetc(fin);
	}
	num_count++;
	if(!str_len) {
		az_5(WRONG_USAGE);
	}
	str = malloc( (str_len + 1) * sizeof(char) );
	if(!str) {
		az_5(JUST_ERROR);
	}
	fseek(fin, pos, SEEK_SET);
	for(int i = 0; i < str_len; i++) {
		str[i] = fgetc(fin);
	}
	str[str_len] = '\0';
	
	*data = malloc(10000*sizeof(int));
	if(!data) {
		az_5(JUST_ERROR);
	}
	*size = 0;
	
	char *token = strtok(str, " ");
	while(token) {
		(*data)[*size] = atoi(token);
		token = strtok(NULL, " ");
		(*size)++;
	}
	*data = realloc(*data, (*size + 1)*sizeof(int));
	if(!data) {
		az_5(JUST_ERROR);
	}	
}

int cmp(const void *a, const void *b) {
	int aa = *( (int*)a );
	int bb = *( (int*)b );
	if(aa < bb) return -1;
	else if(aa == bb) return 0;
	else return 1;
}

int min_char(unsigned char *arr, int size) {
	unsigned char min = 255;
	int index = 0;
	for(int i = 0; i < size; i++) {
		if(arr[i] < min) { 
			min = arr[i];
			index = i;
		}
	}
	return index;
}















