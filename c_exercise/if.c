#include <stdio.h>

int main(void)
{
	// 读入一个成绩，判断所属于的分数段
	/*
		90~100  优秀
		80~89	良好
		70~79	一般
		60~69	及格
		0~59	不及格
	*/	
	// 定义变量用于存储用户输入的成绩
	int score;

	// 读取用户输入的成绩
	printf("请输入你的成绩:");
	scanf("%d", &score);

	// 判断所属分数段
	if (90 <= score && score <= 100) {
		printf("优秀\n");
	} else if (score >= 80 && score <= 89) {
		printf("良好\n");
	} else if (score >= 70 && score <= 79) {
		printf("还行\n");
	} else if (score >= 60 && score < 70) {
		printf("及格\n");
	} else if (score >= 0 && score <= 59){
		printf("不及格\n");	
	} else {
		printf("无效\n");
	}

	return 0;
}

