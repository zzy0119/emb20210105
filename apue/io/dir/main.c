#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFSIZE	128

int main(int argc, char *argv[])
{
	DIR *dp;
	struct dirent *entry;
	char buf[BUFSIZE] = {};
	struct stat res;
	int sum;

	if (argc < 2)
		return 1;

	dp = opendir(argv[1]);
	if (NULL == dp) {
		perror("opendir()");
		return 1;
	}
	
	sum = 0;
	while (1) {
		entry = readdir(dp);
		if (NULL == entry) {
			if (!errno)
				break;
			perror("readdir()");
			goto READERROR;
		}
		// printf("%s\n", entry->d_name);
		memset(buf, '\0', BUFSIZE);
		strncpy(buf, argv[1], BUFSIZE);
		strncat(buf, "/", BUFSIZE);
		strncat(buf, entry->d_name, BUFSIZE);
		stat(buf, &res);
		sum += res.st_size;
	}

	printf("%d\n", sum);
	
	closedir(dp);

	return 0;
READERROR:
	closedir(dp);
	return 1;
}

