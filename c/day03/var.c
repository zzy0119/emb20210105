/*
 c存储空间布局:
 	代码段(.text):二进制指令,只读
	栈(stack):局部变量,自动申请释放
	堆(heap):程序员管理
 	数据段(data):全局变量
	bss段:静态数据

 变量的属性
 	存储位置：变量使用哪一段内存
	作用域:变量的使用范围
	生存周期:创建～销毁
 变量的分类:
 	全局变量：定义在函数体外,整个程序
	局部变量: 定义在函数体内,函数内
	块变量:定义在语句块if for while语句块内, {}
 修饰变量关键字:
 	auto 自动变量,局部和块变量默认auto
	const 保护变量
	static 静态变量,修饰全局变量则显示作用域在本文件,
		   修饰局部变量则改变存储位置到bss(未初始化),或data(已初始),延长声明周期
	register 寄存器
	volatile 易失变量
		int num = 1;
		num == num; // 用户成立
		volatile int num = 1;
		num == num;// 不能确保永远成立
	extern 外部

 */

#include <stdio.h>

extern int glob; // 全局变量, 未初始化值是0---->bss
static int glob2 = 2; // 全局变量, 数据段,static 限制的是作用域在本文件

static void test(void);
int main(void)
{
	auto int var; // 局部变量, 未初始化,值随机--->stack

	const int num = 5;

	num = 100;

	for (int i = 1; i < 10; i++)
		printf("i:%d\n", i); // 块变量, 栈

	test();
	test();
	test();
	test();

	return 0;
}

static void test(void) // 限制作用域在本文件
{
	static int n;

	printf("n:%d\n", n);
	n ++;
}



