#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
/*
	��������Ϸ��Ϸ
*/
int menu(){
	printf("===========================\n");
	printf("      1����ʼ��Ϸ\n");
	printf("      0���˳���Ϸ\n");
	printf("===========================\n");
	int choice = 0;
	printf("���������ѡ��:\n");
	scanf("%d", &choice);
	return choice;
}
void guessNumber(){
	printf("��������Ĳ²⣺\n");
	int number;
	int result = rand() % 100 + 1;
	while (1){
		scanf("%d", &number);
		if (number < result){
			printf("��С��\n");
		}
		else if (number > result){
			printf("�´���\n");
		}
		else{
			printf("�¶���\n");
			return;
		}
	}
}

int main(){
	int choice = 0;
	//���ؽ����ѡ��
	choice = menu();
	if (choice == 1){
		guessNumber();
	}
	else{
		exit(0);
	}
	system("pause");
	return 0;
}