#include<stdio.h>
#include<stdlib.h>
typedef unsigned int uint;
/*
	дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮�ͣ�
	���磬����DigitSum(1729)����Ӧ�÷���1+7+2+9�����ĺ���19
*/
uint DigitSum(uint n){
	if (n < 10)
		return n;
	else return n % 10 + DigitSum(n / 10);
}
int main(){
	printf("%d\n",DigitSum(1729));
	system("pause");
	return 0;
}