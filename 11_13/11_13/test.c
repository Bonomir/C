#include<stdio.h>

int main(){
	//定义两个数组，数组一样大
	int arr1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int arr2[] = { 11, 12, 13, 14, 15, 16, 17, 18, 19 };
	//进行内容交换
	for (int i = 0; i < sizeof(arr1) / sizeof(int); i ++){
		int temp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = temp;
	}
	//打印出arr1的内容
	for (int i = 0; i < sizeof(arr1) / sizeof(int); i++){
		printf("%d ", arr1[i]);
	}
	printf("\n");
	//打印出arr2的内容
	for (int i = 0; i < sizeof(arr1) / sizeof(int); i++){
		printf("%d ", arr2[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}