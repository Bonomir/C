#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
	模拟三次密码输入的场景
	最多能输入三次密码，密码正确，提示“登录成功”,
	密码错误，可以重新输入，最多输入三次。三次均错，则提示退出程序。
*/
int main(){
	char password[20] = "12345";
	int i = 3;
	while (i){
		scanf("%s", &password);
		if (strcmp(password, "88888888") == 0){
			printf("登陆成功！\n");
			break;
		}
		i--;
		printf("您还有%d次机会！\n", i);
	}
	system("pause");
	return 0;
}