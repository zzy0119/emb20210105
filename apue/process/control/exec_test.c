#include <stdio.h>
#include <glob.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

/*
 模拟shell工作方式
 */

int parseString(char *p, glob_t *res);
int main(void)
{
	char *lineptr = NULL;
	size_t n = 0;
	glob_t str;
	pid_t pid;

	while (1) {
		// "ls -l -a -h "
		printf("[%s]$", getenv("PWD"));
		if (getline(&lineptr, &n, stdin) == -1)
			break;
		// strsep(3) / strtok(3)
		// lineptr--->str
		if (strcmp(lineptr, "exit\n") == 0) {
			free(lineptr);
			lineptr = NULL;
			break;
		}

		parseString(lineptr, &str);
		pid = fork();
		if (pid == 0) {
			execvp((str.gl_pathv)[0], str.gl_pathv);
			perror("execvp()");
			exit(1);
		}
		wait(NULL);
		free(lineptr);
		lineptr = NULL;
		n = 0;
	}

	exit(0);
}

int parseString(char *p, glob_t *res)
{
	char *r;
	int i = 0;

	while (1) {
		r = strtok(p, " \n");
		if (NULL == r)
			break;
		glob(r, GLOB_NOCHECK | GLOB_APPEND * i, \
				NULL, res);	
		i = 1;
		p = NULL;
	}

	return 0;
}




