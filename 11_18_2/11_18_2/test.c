#include<stdio.h>
#include<stdlib.h>
/*
	���100��999֮������С�ˮ�ɻ������������
*/
//������ֵ�����
int cube(int n){
	return n*n*n;
}

int main(){
	for (int i = 123; i < 1000; i++){
		int hunderds = i / 100;//��λ
		int ten = i / 10 % 10;//ʮλ
		int unit = i % 10;//��λ
		if (cube(hunderds) + cube(ten) + cube(unit) == i)
			printf("%d\t", i);
	}

	system("pause");
	return 0;
}