#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
	ģ��������������ĳ���
	����������������룬������ȷ����ʾ����¼�ɹ���,
	������󣬿����������룬����������Ρ����ξ�������ʾ�˳�����
*/
int main(){
	char password[20] = "12345";
	int i = 3;
	while (i){
		scanf("%s", &password);
		if (strcmp(password, "88888888") == 0){
			printf("��½�ɹ���\n");
			break;
		}
		i--;
		printf("������%d�λ��ᣡ\n", i);
	}
	system("pause");
	return 0;
}