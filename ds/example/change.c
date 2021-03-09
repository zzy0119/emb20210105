#include <stdio.h>
#include <stdlib.h>

#include <stack.h>

char *change(int num, int n);
int main(int argc, char **argv)
{
	if (argc < 3)
		return 1;

	char *p = change(atoi(argv[1]), atoi(argv[2]));
	puts(p);

	free(p);

	return 0;
}

char *change(int num, int n)
{
	stack_t *s;
	int r;
	char ch;
	char *res = NULL;
	int i;

	stackInit(sizeof(char), 32, &s);

	while (num) {
		r = num % n;	
		if (r < 10)	{
			ch = r + '0';	
		} else {
			ch = r-10+'a';
		}
		stackPush(s, &ch);
		num /= n;
	}

	i = 0;
	while (!stackIsEmpty(s)) {
		res = realloc(res, i+1);	
		stackPop(s, res+i);
		i++;
	}
	res = realloc(res, i+1); // '\0' 
	res[i] = '\0';

	stackDestroy(s);

	return res;
}


