/*
   输入多个字符串，存储到堆空间中， (接口1)
   找到其中最长的第一个字符串输出(接口2)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 从终端读入一个字符串
int mygetline(char **ptr)
{
	int ch;
	int size = 0;

	*ptr = NULL;

	while (1) {
		*ptr = realloc(*ptr, (size+1) * sizeof(char));
		ch = getchar();
		if (ch == '\n') {
			// 存'\0'
			(*ptr)[size] = '\0';
			break;
		}
		(*ptr)[size] = ch;
		size ++;
	}

	return size;
}

char **getnString(int n)
{
	char **p;

	p = calloc(n+1, sizeof(char *));
	if (NULL == p)
		return NULL;

	for (int i = 0; i < n; i++) {
		mygetline(p+i);
	}

	return p;
}

// 最长

char *getLongString(int n, char **p)
{
	int len;
	int j;

	len = strlen(p[0]);
	j = 0;
	for (int i = 1; i < n; i++) {
		if (strlen(p[i]) > len) {
			j = i;	
			len = strlen(p[i]);
		}
	}

	return p[j];
}

int main(void)
{
	char **ret;
	int n;

	ret = getnString(10);

	for (n = 0; ret[n] != NULL; n++)
		;

	printf("%s\n", getLongString(n, ret));

	return 0;
}




