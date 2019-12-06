#include<stdio.h>
#include<stdlib.h>
/*
	写一个函数打印arr数组的内容，不使用数组下标，使用指针。
*/
int main(){
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//在这里完成代码
	int* p = arr;
	for (int len = 0; len < sizeof(arr)/sizeof(arr[0]); len++,p++){
		printf("%d ", *p);
	}
	system("pause");
	return 0;
}