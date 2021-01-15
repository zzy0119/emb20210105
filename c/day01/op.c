#include <stdio.h>

int main(void)
{
	char a = 10; // 初始化
	char b = 5;
	char c;

	a++; // a = a+1
	printf("%d\n", a);
	--a;
	printf("%d\n", a);

	c = a+++b; // ++变量后，先参与运算再自增
	printf("a:%d, b:%d, c:%d\n", a, b, c);

	// a 11  b 5
	c = ++a+b; // ++变量前，先自增再参与运算
	printf("a:%d, b:%d, c:%d\n", a, b, c);

	// 位运算
	a = 13;
	b = 25;

	c = a & b; // 01101 & 11001 ---> 1001
	printf("c:%d\n", c);

	c = a | b; // 01101 | 11001 ---> 11101
	printf("c:%d\n", c);

	a = 1;
	c = ~a; // 0000000 ... 1101
	printf("c:%d\n", c);

	// << >>
	a = 15; // 0000 1111
	b = a >> 1; // 低位移出，高位补符号位(正0 负1)
	c = a << 1; // 高位移出，低位补0	0001 1110
	printf("b:%d, c:%d\n", b, c);

	a = -15; // 1111 0001
	b = a >> 1; // 1111 1000 ---> 1000 1000
	c = a << 1; // 1110 0010 ---> 1001 1110
	printf("b:%d, c:%d\n", b, c);

	// ^
	a = 10, b = 20;
	c = a ^ b; // 相同位0 不同为1
	printf("c:%d\n", c); // 0000 1010 ^ 0001 0100-->0001 1110

	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	printf("a:%d, b:%d\n", a, b);

	// 关系运算符 == != >= <= > < 
	
	// 逻辑运算符 && || !
	a = 2;
	b = 1;
	a = a > 3 && (b = 8);
	printf("a:%d, b:%d\n", a, b);

	a = 2;
	b = 1;
	a = a < 3 || (b = 8);
	printf("a:%d, b:%d\n", a, b);

	// 赋值运算符 = += -= /= *=
	a = 2, b = 1;
	a += b; // a = a + b;
	printf("a:%d\n", a);

	// 条件运算符 ? :
	b = a < 2 ? 10 : 20;
	printf("b:%d\n", b);

	// 逗号运算符
	a = 2, b = 1;
	c = (a++, b++, a+b);
	printf("a:%d, b:%d, c:%d\n", a, b, c);

	return 0;
}

