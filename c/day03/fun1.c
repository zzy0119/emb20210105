#include <stdio.h>

/*
	函数：功能实现封装到小的接口模块内 
	定义：
		返回值类型 函数名(参数列表)
		{
			函数体;
		}
	声明:
		使用已经定义好的函数借口之前需要声明
		返回值类型 函数名(参数列表类型);
	调用:
		函数名(传递的值);
 */

// 声明
int isPerfectNumber(int num);
int main(void)
{
	int ret;
	// 调用
	for (int i = 1; i < 100; i++) {
		ret = isPerfectNumber(i);
		if (ret) {
			printf("%d是一个完数\n", i);		
		}
	}
	
	return 0;
}

/*
 定义
 函数名isPerfectNumber
 参数num:待判断的数值
 返回值:是1 否0
 */
int isPerfectNumber(int num)
{
	int s = 0;

	for (int i = 1; i < num; i++)
		if (num % i == 0)
			s += i;
	if (s == num)
		return 1;
	else
		return 0;
}



