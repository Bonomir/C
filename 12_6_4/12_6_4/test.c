#include<stdio.h>
#include<stdlib.h>
/*
	����int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ�� 
��������:
1999 2299
�������:7
*/
int main(){
	int i = 0;
	int a = 1999;
	int b = 2299;
	int c = a^b;
	int flag = 1;
	int count = 0;
	while (flag != 0){
		if (c&flag){
			count++;
		}
		flag <<= 1;
	}
	printf("%d\n", count);
	system("pause");
	return 0;
}