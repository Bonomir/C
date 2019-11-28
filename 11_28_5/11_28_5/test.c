#include<stdio.h>
#include<stdlib.h>
/*
	自定义strlen，求字符串的长度（非递归）
*/
int Strlen(char* str){
	int len = 0;
	while (*str != '\0'){
		str++;
		len++;
	}
	return len;
}
int main(){
	char str[] = "adfdfa";
	printf("%d\n",Strlen(str));
	system("pause");
	return 0;
}