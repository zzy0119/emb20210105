#include <stdio.h>

#define FLNAME	"./mycat.c"
#define BUFSIZE	100

int main(void)
{
	char buf[BUFSIZE] = {};
	int cnt;

	FILE *fp = fopen(FLNAME, "r");
	if (NULL == fp) {
		perror("fopen()");
		return 1;
	}

	fseek(fp, 10, SEEK_CUR);
	printf("%ld\n", ftell(fp));
	
	rewind(fp);

	cnt = fread(buf, 1, BUFSIZE, fp);
	fwrite(buf, 1, cnt, stdout);

	fclose(fp);

	return 0;
}

