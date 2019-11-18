#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//求Sn=a+aa+aaa+aaaa+aaaaa的前5项之和
/*
	用来求第i项的值
	输入的值为：数字a和第i项
	返回的值：第i项的结果
*/
int func(int a,int i){
	//返回的结果
	int result = 0;
	for (int cnt = 0; cnt < i; cnt++){
		result += a * (int)pow(10,cnt);
	}
	return result;
}
int main(){
	//数学式子中的a
	int a = 0;
	//结果
	int sn = 0;
	printf("请输入a的值：\n");
	scanf("%d", &a);
	for (int i = 1; i <= 5; i ++){
		printf("a(%d) = %d\n", i, func(a, i));
		sn += func(a, i);
		printf("Sn=%d\n", sn);
	}
	//printf("%d",sn);
	system("pause");
	return 0;
}