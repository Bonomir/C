#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
	将参数字符串中的字符反向排列。
*/
char* reverse1(char *str);
int main(){
	// 定义一个字符串
	char str[] = "abcd";
	// 调用自定义反向排序函数
	printf("String=%s\n", reverse1(str));
	system("pause");
	return 0;
}

char* reverse1(char *str) {
	char *p = str;
	int n = 0;
	// *p++先取出p所指
	while (*p++ != '\0')	{
		n++;
	}
	if (n>1)	{
		char temp = str[0];
		str[0] = str[n - 1];
		str[n - 1] = '\0';
		reverse1(str + 1);
		str[n - 1] = temp;
	}
	return str;
}