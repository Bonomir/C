#include<stdio.h>
#include<stdlib.h>
/*
	编写一个函数实现n^k，使用递归实现
*/
int nk(int n, int k){
	if (k == 1)
		return n;
	else return n * nk(n, k - 1);
}
int main(){
	printf("%d\n", nk(3, 2));
	printf("%d\n", nk(3, 3));
	system("pause");
	return 0;
}