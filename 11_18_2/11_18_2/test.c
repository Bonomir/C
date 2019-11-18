#include<stdio.h>
#include<stdlib.h>
/*
	求出100～999之间的所有“水仙花数”并输出。
*/
//求该数字的立方
int cube(int n){
	return n*n*n;
}

int main(){
	for (int i = 123; i < 1000; i++){
		int hunderds = i / 100;//百位
		int ten = i / 10 % 10;//十位
		int unit = i % 10;//个位
		if (cube(hunderds) + cube(ten) + cube(unit) == i)
			printf("%d\t", i);
	}

	system("pause");
	return 0;
}