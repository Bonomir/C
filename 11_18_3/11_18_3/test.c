#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//��Sn=a+aa+aaa+aaaa+aaaaa��ǰ5��֮��
/*
	�������i���ֵ
	�����ֵΪ������a�͵�i��
	���ص�ֵ����i��Ľ��
*/
int func(int a,int i){
	//���صĽ��
	int result = 0;
	for (int cnt = 0; cnt < i; cnt++){
		result += a * (int)pow(10,cnt);
	}
	return result;
}
int main(){
	//��ѧʽ���е�a
	int a = 0;
	//���
	int sn = 0;
	printf("������a��ֵ��\n");
	scanf("%d", &a);
	for (int i = 1; i <= 5; i ++){
		printf("a(%d) = %d\n", i, func(a, i));
		sn += func(a, i);
		printf("Sn=%d\n", sn);
	}
	//printf("%d",sn);
	system("pause");
	return 0;
}