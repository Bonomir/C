#include<stdio.h>
#include<stdlib.h>
/*
	折半查找:
	写代码可以在整型有序数组中查找想要的数字，
*/
/*
	传入的值：数组，数组长度，在数字中要找到的数字
	返回值：找到了返回下标，找不到返回-1.
*/
int BinarySearch(int arr[],int len,int n){
	int left = 0;
	int right = len - 1;
	int mid = (left + right) / 2;
	while (left <= right){
		if (arr[mid] < arr[n]){//在右边找
			left = mid + 1;
			mid = (left + right) / 2;
		}
		if (arr[mid] > arr[n]){//在左边找
			right = mid - 1;
			mid = (left + right) / 2;
		}
		if (arr[mid] == n){
			return mid;
		}
	}
	return -1;
}
int main(){
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int len = sizeof(arr) / sizeof(int);
	printf("%d\n", BinarySearch(arr, len, 2));
	system("pause");
	return 0;
}