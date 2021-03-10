#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack.h>
#include <queue.h>

static int errornumber = 0;

char *midToLast(const char *p);
int lastRes(const char *p);
int main(int argc, char *argv[])
{
	if (argc < 2)	
		return 1;

	char *r = midToLast(argv[1]);
	puts(r);
	printf("%d\n", lastRes(r));

	free(r);

	return 0;
}

static int isDigital(char ch)
{
	return ch >= '0' && ch <= '9';
}

static int isOperator(char ch)
{
	return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

static int charactorToInt(char ch)
{
	return ch - '0';
}

static int operatorLevel(char ch)
{
	int level = 0;

	if (ch == '+' || ch == '-')
		level = 1;
	else if (ch == '*' || ch == '/')
		level = 2;

	return level;
}

char *midToLast(const char *p)
{
	int len;
	stack_t *s;
	queue_t *q;
	char top;
	char *res = NULL;
	int i;

	len = strlen(p);

	stackInit(sizeof(char), len, &s);	
	queueInit(sizeof(char), len, &q);	

	while (*p) {
		if (isDigital(*p)) {
			enq(q, p);
		} else if (isOperator(*p)) {
			while (!stackIsEmpty(s)) {
				stackPop(s, &top);
				if (operatorLevel(*p) > operatorLevel(top)) {
					stackPush(s, &top);
					break;
				}
				enq(q, &top);
			}
			stackPush(s, p);
		} else if (*p == '(') {
			stackPush(s, p);
		} else if (*p == ')') {
			while (!stackIsEmpty(s)) {
				stackPop(s, &top);
				if (top == '(')
					break;
				enq(q, &top);
			}
		} else
			break;
	
		p ++;
	}
	if (*p != '\0') {
		stackDestroy(s);
		queueDestroy(q);
		return NULL;
	}
	while (!stackIsEmpty(s)) {
		stackPop(s, &top);
		enq(q, &top);
	}
	i = 0;
	while (!queueEmpty(q)) {
		res = realloc(res, i+1);	
		deq(q, res+i);
		i++;
	}
	res = realloc(res, i+1);	
	res[i] = '\0';

	stackDestroy(s);
	queueDestroy(q);

	return res;
}

static int op2num(int left, int right, char op)
{
	int res;

	switch (op) {
		case '+':
			res = left + right;
			break;
		case '-':
			res = left - right;
			break;
		case '*':
			res = left * right;
			break;
		case '/':
			res = left / right;
			break;
		default:
			// 异常
			break;
	}

	return res;
}

int lastRes(const char *p)
{
	stack_t *s;
	int left, right;
	int res;
	int push;

	stackInit(sizeof(int), strlen(p), &s);

	while (*p) {
		if (isDigital(*p))	{
			push = charactorToInt(*p);
			stackPush(s, &push);
		} else {
			stackPop(s, &right);
			stackPop(s, &left);
			// if error
			res = op2num(left, right, *p);

			stackPush(s, &res);
		}
		p++;
	}
	stackPop(s, &res);
	if (!stackIsEmpty(s)) {
		errornumber = 1;
		res = 0;
	}

	stackDestroy(s);
	
	return res;
}



