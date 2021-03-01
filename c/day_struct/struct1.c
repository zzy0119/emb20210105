#include <stdio.h>
#include <string.h>

#define NAMESIZE	32	

// 类型struct stu_st
struct stu_st {
	int age;
	char name[NAMESIZE];
	float score;
};

int main(void)
{
	struct stu_st stu;
	struct stu_st stu2 = {20, "emb", 100};
	struct stu_st arr[3];
	struct stu_st *p;

	p = arr;

	printf("%d, %s, %f\n", stu2.age, stu2.name, stu2.score);

	stu.age = 19;
	strcpy(stu.name, "hello");
	stu.score = 10.9;

	printf("%d, %s, %f\n", stu.age, stu.name, stu.score);

	for (int i = 0; i < 3; i++) {
		arr[i].age = 20+i;
		snprintf(arr[i].name, NAMESIZE, "hello%d", i+1);
		arr[i].score = 100-i;
	}

	for (int i = 0; i < 3; i++) {
// 		printf("%d %s %f\n", arr[i].age, arr[i].name, arr[i].score);
		printf("%d %s %f\n", (p+i)->age, (p+i)->name, (p+i)->score);
	}

	return 0;
}

