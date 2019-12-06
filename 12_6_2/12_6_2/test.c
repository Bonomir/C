#include <stdio.h>
#include<stdlib.h>
/*
	通过异或运算交换两个变量
*/
int main()
{
	int a = 10;
	int b = 20;
	a = a^b;
	b = a^b;
	a = a^b;
	printf("a=%d a=%d\n",a,b);
	system("pause");
	return 0;
}



