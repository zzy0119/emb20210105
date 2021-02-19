/* 
	"hello   world after  noon"
	ch ---> ' '
	"hello"
	"world"
	"after"
	"noon"
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **sep_str(const char *p, char ch);

int main(int argc, char *argv[])
{
	char **r;
	if (argc < 3)
		return 1;

	r = sep_str(argv[1], *argv[2]);
	for (int i = 0; r[i]; i++) {
		printf("%s\n", r[i]);
	}

	return 0;
}

char **sep_str(const char *p, char ch)
{
	char *tmp;	
	char **ret;
	int size = 1;

	tmp = malloc(strlen(p)+1);
	// if error
	strcpy(tmp, p);
	
	ret = calloc(size, sizeof(char *)); // 返回的
	// if error
	p = tmp;	
	while (*tmp) {
		if (*tmp != ch) {
			tmp ++;
		} else {
			*tmp = '\0';
			if (p == tmp) {
				p ++;
				tmp ++;
			} else {
				// 保存子串
				ret = realloc(ret, (size+1)*sizeof(char *));
				ret[size-1] = malloc(strlen(p)+1);
				strcpy(ret[size-1], p);
				size ++;
				tmp++;
				p = tmp;
			}
		}
	}

	return ret;
}


