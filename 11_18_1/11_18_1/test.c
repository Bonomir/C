#include<stdio.h>
#include<stdlib.h>
/*
	此三角形分为上下两个三角形
	先打印上部三角形
	再打印下部三角形
*/
int main(){
	//用来记录上三角打印完之后j的大小，即一行有多少个“*”
	int cnt = 0;
	//外层循环控制循环轮数，即打印行数
	for (int i = 1; i < 13; i++){
		//内层循环控制每一行打印的‘*’多少
		if (i < 7){
			//打印上三角
			for (int j = 1; j <= 2 * i - 1; j++){
				printf("*");
				cnt = j;
			}
			putchar('\n');
		}
		else{
			for (int j = cnt-2; j > 0; j--){
				printf("*");
			}
			putchar('\n');
			cnt -= 2;
		}
		

	}	
	putchar('\n');
	system("pause");
	return 0;
}