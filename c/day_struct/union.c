#include <stdio.h>

// 共用体---->联合体

union test_un {
	int a;
	char b;
};

int main(void)
{
	union test_un t;	

	// 小端存储：低字节存低地址，高字节存高地址
	// 大端存储：低字节存高地址，高字节存低地址
	t.a = 0x12345678;

	printf("%#x\n", t.b);

	return 0;
}

