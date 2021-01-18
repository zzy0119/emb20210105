#include <stdio.h>

int main(void)
{
	int score, n;
	int i;

	i = 0;
	while (i < 10) {
		printf("请输入第%d个学生成绩:", i+1);
		scanf("%d", &score);
		if (score < 0 || score > 100) {
			printf("成绩无效\n");
			continue;// 终止本次循环，继续下一次
		}

		n = score / 10;

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
		i ++;
	}

	return 0;
}


