#include<stdio.h>
#include<stdlib.h>
/*
	�۰����:
	д����������������������в�����Ҫ�����֣�
*/
/*
	�����ֵ�����飬���鳤�ȣ���������Ҫ�ҵ�������
	����ֵ���ҵ��˷����±꣬�Ҳ�������-1.
*/
int BinarySearch(int arr[],int len,int n){
	int left = 0;
	int right = len - 1;
	int mid = (left + right) / 2;
	while (left <= right){
		if (arr[mid] < arr[n]){//���ұ���
			left = mid + 1;
			mid = (left + right) / 2;
		}
		if (arr[mid] > arr[n]){//�������
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