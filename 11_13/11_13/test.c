#include<stdio.h>

int main(){
	//�����������飬����һ����
	int arr1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int arr2[] = { 11, 12, 13, 14, 15, 16, 17, 18, 19 };
	//�������ݽ���
	for (int i = 0; i < sizeof(arr1) / sizeof(int); i ++){
		int temp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = temp;
	}
	//��ӡ��arr1������
	for (int i = 0; i < sizeof(arr1) / sizeof(int); i++){
		printf("%d ", arr1[i]);
	}
	printf("\n");
	//��ӡ��arr2������
	for (int i = 0; i < sizeof(arr1) / sizeof(int); i++){
		printf("%d ", arr2[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}