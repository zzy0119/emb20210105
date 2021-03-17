#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	int ch;
	char buf[10] = {};
	int cnt;

	if (argc < 2)
		return 1;

	fp = fopen(argv[1], "r");
	if (NULL == fp) {
		perror("fopen()");
		return 1;
	}
	
	while (1) {
#if 0
		ch = fgetc(fp);
		if (ch == EOF) {
			if (feof(fp))
				break;
			else
				goto ERROR;
		}
		fputc(ch, stdout);
#endif
#if 0
		memset(buf, '\0', 10);
		if (fgets(buf, 10, fp) == NULL) {
			if (feof(fp))
				break;
			goto ERROR;
		}
		fputs(buf, stdout);
		sleep(1);
#endif
		cnt = fread(buf, 1, 10, fp);
		if (cnt == 0) {
			if (feof(fp))
				break;
			goto ERROR;
		}
		fwrite(buf, 1, cnt, stdout);
	}

	fclose(fp);

	return 0;
ERROR:
	fclose(fp);
	return 1;
}

