#include<stdio.h>
#include<stdlib.h>
/*
	дһ��������ӡarr��������ݣ���ʹ�������±꣬ʹ��ָ�롣
*/
int main(){
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//��������ɴ���
	int* p = arr;
	for (int len = 0; len < sizeof(arr)/sizeof(arr[0]); len++,p++){
		printf("%d ", *p);
	}
	system("pause");
	return 0;
}