#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
/*
	猜数字游戏游戏
*/
int menu(){
	printf("===========================\n");
	printf("      1，开始游戏\n");
	printf("      0，退出游戏\n");
	printf("===========================\n");
	int choice = 0;
	printf("请输入你的选择:\n");
	scanf("%d", &choice);
	return choice;
}
void guessNumber(){
	printf("请输入你的猜测：\n");
	int number;
	int result = rand() % 100 + 1;
	while (1){
		scanf("%d", &number);
		if (number < result){
			printf("猜小了\n");
		}
		else if (number > result){
			printf("猜大了\n");
		}
		else{
			printf("猜对了\n");
			return;
		}
	}
}

int main(){
	int choice = 0;
	//加载界面和选择
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