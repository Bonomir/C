#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
/*输入一个整数，输出该数二进制表示中1的个数。*/
int count_one_bits(unsigned int value)
{
	int count = 0;//计数器
	int flag = 1;
	// 如果1为0 的话，就说明1已经移出最右边的边界。
	while (flag != 0){
		if (flag & value){
			count++;
		}
		flag <<= 1;
	}
	return count;
}

int main(){
	int n;
	scanf("%d",&n);
	printf("%d的位数为%d\n",n,count_one_bits(n));
	system("pause");
	return 0;
}