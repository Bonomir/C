#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
/*
	�����ʼ������
	������������飬���鳤��
	ע�⣺�����ں�����ߵ����飬ֻ�ܳ�ʼ�����������㣬����Ҫ�ں����н���
*/
void init(int arr[],int len){
	for (int i = 0; i < len; i ++){
		scanf("%d", &arr[i]);
	}
}
/*
	��������,������Ҫÿ��Ԫ�ض�Ϊ0��
	�������飬���鳤��
*/
void empty(int arr[],int len){
	for (int i = 0; i < len; i++){
		arr[i] = 0;
	}
}
/*
	���鷴ת
	�������飬���鳤��
*/
void reverse(int arr[], int len){
	int temp;
	for (int i = 0; i < len/2; i++){
		temp = arr[i];
		arr[i] = arr[len-i-1];
		arr[len-i-1] = temp;
	}
}
void putArr(int arr[],int len){
	for (int i = 0; i < len; i++){
		printf("%d ", arr[i]);
	}
}
int main(){
	int array[5] = { 0 };
	int len = sizeof(array) / sizeof(int);
	init(array,len);
	reverse(array, len); 
	putArr(array, len);
	system("pause");
	return 0;
}