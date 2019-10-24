#include <stdio.h>
#include <dirent.h>

int main() {
	ino_t arr[100];
	char *files[100];
	int num_of_files = 0;
	
	DIR *dir = opendir("./tmp");

	if (!dir) {
		return 1;
	}

    struct dirent *dp;
    while (dp = readdir(dir)) {
        arr[num_of_files] = dp->d_ino;
        files[num_of_files] = dp->d_name;
        num_of_files++;
    }

    for (int j = 0; j < num_of_files; j++) {
        printf("Pointed to the same: %s", files[j]);
        for (int k = j + 1; k < num_of_files; k++) {
            if (arr[k] == arr[j] && arr[k] != 0) {
                printf(", %s", files[k]);
                arr[k] = 0;
            }
        }
       	printf("\n");
    }

    closedir(dir);
    return 0;
}