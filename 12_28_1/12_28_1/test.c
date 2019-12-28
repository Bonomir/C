#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// 反转算法，对输入的字符串整体反转
void reverse(char* start, char* end){
	while (start < end){
		char temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}
int main(){
	char input[100];
	//不能使用scanf,scanf遇到空格，一次接收就结束了
	gets(input);
	//反转整个句子
	reverse(input, input + strlen(input) - 1);
	//反转句子中的单词
	char* start = input;
	while (*start){
		char* end = start;
		while (*end != ' '&&*end){
			end++;
		}
		reverse(start, end - 1);
		if (*end)
			start = end + 1;
		else{
			start = end;
		}
	}
	printf("%s", input);
	system("pause");
	return 0;
}
