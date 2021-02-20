/*
 字符数组
 c语言中没有存储字符串类型, 存储字符变量可以使用字符数组类型
 char str[] = "hello"; // 字符串'\0'作为终止字符
 */
#include <stdio.h>

int main(void)
{
	char str[20] = "hello world";
	char str2[] = {'h', 'e', 'l', 'l', 'o', '\0'};
	char str3[] = {"hello"};
	char str4[5] = {'h', 'e', 'l', 'l', 'o'}; // 字符串
	// char str5[5] = "hello"; // 错
	int i;

	for (i = 0; str[i] != '\0'; i++)
		putchar(str[i]); // printf("%c", str[i]);
	printf("\n");

	return 0;
}

