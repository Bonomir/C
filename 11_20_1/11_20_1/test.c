#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
/*
	数组初始化函数
	传入参数：数组，数组长度
	注意：定义在函数外边的数组，只能初始化，不能运算，运算要在函数中进行
*/
void init(int arr[],int len){
	for (int i = 0; i < len; i ++){
		scanf("%d", &arr[i]);
	}
}
/*
	数组的清空,可能是要每个元素都为0吧
	传入数组，数组长度
*/
void empty(int arr[],int len){
	for (int i = 0; i < len; i++){
		arr[i] = 0;
	}
}
/*
	数组反转
	传入数组，数组长度
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