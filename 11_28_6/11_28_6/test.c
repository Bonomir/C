#include<stdio.h>
#include<stdlib.h>
/*
	�ݹ�ͷǵݹ�ֱ�ʵ����n�Ľ׳�
*/
//�ǵݹ��㷨
int fact(int n){
	// ��¼�׳�
	int result = 1;
	while (n>0){
		result *= n;
		n--;
	}
	return result;
}
// �ݹ��㷨
int recurveFact(int n){
	if (n == 1)
		return 1;
	else return n* recurveFact(n-1);
}
int main(){
	int fac = 3;
	printf("���÷ǵݹ飺%d�Ľ׳�Ϊ%d\n", fac, fact(fac));
	printf("���õݹ飺%d�Ľ׳�Ϊ%d\n",fac,recurveFact(fac));
	system("pause");
	return 0;
}