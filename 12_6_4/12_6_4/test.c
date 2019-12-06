#include<stdio.h>
#include<stdlib.h>
/*
	两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？ 
输入例子:
1999 2299
输出例子:7
*/
int main(){
	int i = 0;
	int a = 1999;
	int b = 2299;
	int c = a^b;
	int flag = 1;
	int count = 0;
	while (flag != 0){
		if (c&flag){
			count++;
		}
		flag <<= 1;
	}
	printf("%d\n", count);
	system("pause");
	return 0;
}