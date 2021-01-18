/*
 读入一个成绩，判断所属分数段
 90~100:A
 80~89:B
 70~79:C
 60~69:D
 0~59:E
 */

#include <stdio.h>

int main(void)
{
	int score, n;

	scanf("%d", &score);
	if (score < 0 || score > 100) {
		printf("成绩无效\n");
		return 1;
	}

	n = score / 10;

#if 0
	if (n == 9 || n == 10) {
		printf("A\n");
	} else if (n == 8) {
		printf("B\n");
	} else if (n == 7) {
		printf("C\n");
	} else if (n == 6) {
		printf("D\n");
	} else {
		printf("E\n");
	}
#endif
	switch (n) {
		case 10:
		case 9:
			printf("A\n");
			break;
		case 8:
			printf("B\n");
			break;
		case 7:
			printf("C\n");
			break;
		case 6:
			printf("D\n");
			break;
		default:
			printf("E\n");
			break;
	}

	return 0;
}


