/*
数据类型:
	基本类型：
		整型
			short(2) int(4) long(8) (long long)(8)
		字符类型
			char 存储单个字符
		实型
			单精度型 float(4)
			双精度类型 double(8) long double(16)
	构造类型
		枚举
		结构体
		共用体
	指针类型
		存储地址类型
	空类型
		void 
 
 */
#include <stdio.h>

int main(void)
{
	// 存储数值---》定义相应类型的变量
	int num;// signed默认 unsigned

	num = 1;

	/*
	 格式占位符:
	 	%d int
		%hd short
		%ld long
		%c char
		%p 地址
		%o 八进制
		%x 十六进制
		%10d 10输出数值所占宽度
	 */
	printf("num = %d\n", num);
	/*
	 转义字符
	 \n
	 \b
	 \r
	 \t
	 */
	printf("hello\bwo\trld\rhi\n");

	printf("%ld\n", sizeof(short));
	printf("%ld\n", sizeof(int));
	printf("%ld\n", sizeof(long));
	printf("%ld\n", sizeof(long long));

	printf("%ld\n", sizeof(float));
	printf("%ld\n", sizeof(double));
	printf("%ld\n", sizeof(long double));

	return 0;
}

