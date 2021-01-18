#include <stdio.h>

/*
 分支语句：
 	if (表达式) {
		代码块;
	}

	if (表达式) {
		代码块;
	} else {
		代码块;
	}
	多条件
	if (表达式) {
		代码块;	
	} else if (表达式) {
		代码块;
	} else if (表达式) {
	
	} else {
	
	}
 */

int main(void)
{
	int score;

	printf("成绩:");
	scanf("%d", &score);

	if (score < 50 && score >= 0) {
		printf("重听\n");
	} else if (score >= 50 && score < 60){
		printf("重新考试！\n");	
	} else if (score >= 60 && score < 90) {
		printf("恭喜你！进入下一段课程\n");
	} else if (score >= 90 && score < 100) {
		printf("通过！并获得一次相亲机会\n");
	} else {
		printf("输入不符合要求\n");
	}

	return 0;
}

