#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
	�������ַ����е��ַ��������С�
*/
char* reverse1(char *str);
int main(){
	// ����һ���ַ���
	char str[] = "abcd";
	// �����Զ��巴��������
	printf("String=%s\n", reverse1(str));
	system("pause");
	return 0;
}

char* reverse1(char *str) {
	char *p = str;
	int n = 0;
	// *p++��ȡ��p��ָ
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