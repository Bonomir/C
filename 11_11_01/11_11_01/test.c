#include<stdio.h>
#include<stdlib.h>
/*
	1.�����������α�����ֵ��������ֵ�����ݽ��н�����
	2.����������ʱ���������������������ݣ������⣩
	3.��10 �����������ֵ��
	4.�����������Ӵ�С�����
	5.�������������Լ����
*/
void change(int *a, int *b){
	/*
		ʹ�ô���ַ�ķ�ʽ������a��b��ֵ
	*/
	int temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
}
void swap(int *a,int *b){
	/*
		��a+b��ֵ��ֵ��a��
		��ͨ��a��ȥb�õ��������b��
		���õõ���a��ȥ�������b�õ��������a
	*/
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

int max_array(int arr[],int num){
	/*
		������������飬���鳤��
		���ֵ�������е����ֵ
	*/
	int max = arr[0];
	for (int i = 1; i < num; i++){
		if (max < arr[i])
			max = arr[i];
	}
	return max;
}

int sort(int a, int b,int c){
	/*
		 ���㷨����ð������
		 ��������� ���� a,b,c
		 ����ֵ ����������
		 ��һ���������������ֵת��Ϊ����
		 �ڶ��������������ð�ݷ�����
		 ����������������������
	*/
	int arr[3] = {0};
	arr[0] = a;
	arr[1] = b;
	arr[2] = c;
	// ð�ݷ����ѭ��������ʽ����ѭ������Ϊn-1
	for (int i = 1; i < 3; i++){
		// �ڲ�ѭ����ѭ������Ϊn - i��iΪ���ѭ����ǰ�Ĵ���
		for (int j = 0; j < 3 - i; j++){
			if (arr[j] < arr[j + 1]){
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			
		}
	}
	for (int i = 0; i < 3; i++)
		printf("%d ",arr[i]);
	printf("\n");
}
int gcd(int a, int b){
	//շת�����
	if (a % b== 0){
		return b;
	}
	else{
		//printf("a=%d,b=%d\n", a, b);
		gcd(b, a % b);
	}
}
int main(){
	int a = 1;
	int b = 2;
	int arr[10] = { 2, 6, 3, 7, 1, 21, 4, 45, 32, 16 };
	//printf("%d\n", max_array(arr, 10));
	//change(&a, &b);
	//swap(&a, &b);
	//printf("a=%d,b=%d\n",a,b);
	int x = 3;
	int y = 1;
	int z = 5;
	//sort(x, y, z);
	int i = 24;
	int j = 9;
	printf("%d\n", gcd(i, j));
	system("pause");
}