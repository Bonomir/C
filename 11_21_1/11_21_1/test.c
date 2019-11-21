#include<stdio.h>
#include<stdlib.h>
typedef unsigned int uint;
/*
	接受一个整型值（无符号），按照顺序打印它的每一位
*/
void print(uint n){
	if (n > 9){
		print(n/10);
	}
	printf("%d ", n%10);
}
int main(){
	uint n = 12345;
	print(n);
	getchar();
	system("pause");
	return 0;
}