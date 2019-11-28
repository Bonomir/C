#include<stdio.h>
#include<stdlib.h>
/*
	递归和非递归分别实现求n的阶乘
*/
//非递归算法
int fact(int n){
	// 记录阶乘
	int result = 1;
	while (n>0){
		result *= n;
		n--;
	}
	return result;
}
// 递归算法
int recurveFact(int n){
	if (n == 1)
		return 1;
	else return n* recurveFact(n-1);
}
int main(){
	int fac = 3;
	printf("调用非递归：%d的阶乘为%d\n", fac, fact(fac));
	printf("调用递归：%d的阶乘为%d\n",fac,recurveFact(fac));
	system("pause");
	return 0;
}