#include <stdio.h>

int main(void)
{
	int k;
	scanf("%d",&k); // 1 2 3 4
	switch(k)
	{
		case 1:printf("%d\n",k++);
		case 2:printf("%d\n",k++);
		case 3:printf("%d\n",k++);
		case 4:printf("%d\n",k++);
			   break;
		default:printf("FULL!\n");
	}
	return 0;
}

