#include<stdio.h>
#include<stdlib.h>
typedef unsigned int uint;
/*
	����һ������ֵ���޷��ţ�������˳���ӡ����ÿһλ
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