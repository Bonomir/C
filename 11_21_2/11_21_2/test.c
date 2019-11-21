#include<stdio.h>
#include<stdlib.h>
/*编写函数不允许创建临时变量，求字符串的长度*/
int Strlen(char* str){
	if (*str == '\0')
		return 0;
	else
		return 1 + Strlen(str+1);
}
int main(){
	char* p = "absce";
	int len = Strlen(p);
	printf("%d\n",len);
	system("pause");
	return 0;
}