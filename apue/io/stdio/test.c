#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFSIZE	100

int cpyFile(FILE *src, FILE *dest, int line)
{
	int n = 0;
	char buf[BUFSIZE] = {};
	// line--->-1 全部
	while (1) {
		if (fgets(buf, BUFSIZE, src) == NULL) {
			if (feof(src))
				break;
			return -1;
		}
		fputs(buf, dest);
		if (line > 0) {
			if (strchr(buf, '\n') != NULL) {
				n ++;
				if (n == line)
					break;
			}
		}
	}

	return 0;
}

int main(int argc, char *argv[])
{
	FILE *fp, *tmpfp;

	if (argc < 4)
		return 1;

	fp = fopen(argv[1], "r+");
	if (NULL == fp) {
		perror("fopen()");
		return 1;
	}
	tmpfp = tmpfile();
	// if error
	cpyFile(fp, tmpfp, atoi(argv[2])-1);
	fputs(argv[3], tmpfp);
	cpyFile(fp, tmpfp, -1);

	rewind(fp);
	rewind(tmpfp);

	cpyFile(tmpfp, fp, -1);

	fclose(fp);
	fclose(tmpfp);

	return 0;
}
