#include<stdio.h>
#include<stdlib.h>
/*
	�Զ���strlen�����ַ����ĳ��ȣ��ǵݹ飩
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