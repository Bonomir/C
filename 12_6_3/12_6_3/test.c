#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
/*����һ��������������������Ʊ�ʾ��1�ĸ�����*/
int count_one_bits(unsigned int value)
{
	int count = 0;//������
	int flag = 1;
	// ���1Ϊ0 �Ļ�����˵��1�Ѿ��Ƴ����ұߵı߽硣
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
	printf("%d��λ��Ϊ%d\n",n,count_one_bits(n));
	system("pause");
	return 0;
}