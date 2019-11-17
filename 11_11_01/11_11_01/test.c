#include<stdio.h>
#include<stdlib.h>
/*
	1.给定两个整形变量的值，将两个值的内容进行交换。
	2.不允许创建临时变量，交换两个数的内容（附加题）
	3.求10 个整数中最大值。
	4.将三个数按从大到小输出。
	5.求两个数的最大公约数。
*/
void change(int *a, int *b){
	/*
		使用传地址的方式，交换a和b的值
	*/
	int temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
}
void swap(int *a,int *b){
	/*
		将a+b的值赋值给a，
		再通过a减去b得到交换后的b，
		再用得到的a减去交换后的b得到交换后的a
	*/
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

int max_array(int arr[],int num){
	/*
		传入参数：数组，数组长度
		输出值：数组中的最大值
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
		 该算法采用冒泡排序
		 输入参数： 整形 a,b,c
		 返回值 排序后的数组
		 第一步：将输入的三个值转换为数组
		 第二步：对数组采用冒泡法排序
		 第三步：返回排序后的数组
	*/
	int arr[3] = {0};
	arr[0] = a;
	arr[1] = b;
	arr[2] = c;
	// 冒泡法外层循环控制轮式数，循环次数为n-1
	for (int i = 1; i < 3; i++){
		// 内层循环，循环次数为n - i，i为外层循环当前的次数
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
	//辗转相除法
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