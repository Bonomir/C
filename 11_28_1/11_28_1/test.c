#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
/*
	递归和非递归分别实现求第n个斐波那契数。
*/
int fibonacci(int n){
	int a = 1;
	int b = 1;
	int tmp1 = a;
	int tmp2 = b;
	int result = 0;
	if (n == 1 || n == 2)
		return 1;
	for (int i = 3; i <= n; i++){
		result = tmp1 + tmp2;
		tmp1= tmp2;
		tmp2 = result;
	}
	return result;
}
int recurveFibonacci(int n){
	if (n == 1 || n == 2)
		return 1;
	else return recurveFibonacci(n-1)+ recurveFibonacci(n-2);

}
int main(){

	//scanf("请输入一个无符号整数：");
	for (int i = 1; i < 10; i++){
		printf("%d ", recurveFibonacci(i));
	}
	printf("\n");
	
	system("pause");
	return 0;
}