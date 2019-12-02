#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
// 地雷个数
#define MINE_COUNT 10
#define ROW 9 //行数
#define COL 9 //列数
int Menu(){
	printf("=================\n");
	printf("  1 开始游戏\n");
	printf("  0 结束游戏\n");
	printf("=================\n");
	int choice = 0;
	printf("请输入你的选择：\n");
	scanf("%d",&choice);
	return choice;
}
// 实际地雷布局图
char mine_map[ROW][COL];
// 向玩家展示的地图
char show_map[ROW][COL];
void Init(char mine_map[ROW][COL], char show_map[ROW][COL]){
	// mime_map,中'0'表示不是地雷，'1'表示地雷
	for (int row = 0; row < ROW; row++){
		for (int col = 0; col < COL; col++){
			mine_map[row][col] = '0';
		}
	}
	// show_map中，使用'*'表示没有打开的方块，打开的分别各自的状态表示
	for (int row = 0; row < ROW; row++){
		for (int col = 0; col < COL; col++){
			show_map[row][col] = '*';
		}
	}

	// 随机布置地雷
	srand((unsigned int)time(NULL));
	int mine_count = MINE_COUNT;
	while (mine_count > 0){
		int row = rand() % 10;// 得到数字0-9
		int col = rand() % 10;
		if (mine_map[row][col] == '0'){
			mine_map[row][col] = '1'; 
			mine_count--;
		}
	}
}
void printMap(char map[ROW][COL]){
	for (int row = 0; row < ROW; row++){
		for (int col = 0; col < COL; col++){
			printf("%c",map[row][col]);
		}
		printf("\n");
	}
}
// 统计坐标row,col位置的元素周围有几个雷，并且把结果更新到show_map
void UpdateShowMap(char show_map[ROW][COL],char mine_map[ROW][COL],int row,int col){
	int mine_count = 0;//周围地雷个数
	mine_count = (mine_map[row - 1][col - 1] - '0') + 
		(mine_map[row - 1][col] - '0') +
		(mine_map[row - 1][col + 1] - '0') +
		(mine_map[row][col - 1] - '0') +
		(mine_map[row][col + 1] - '0') +
		(mine_map[row + 1][col - 1] - '0') +
		(mine_map[row + 1][col] - '0') +
		(mine_map[row + 1][col + 1] - '0');
	show_map[row][col] = '0' + mine_count;//结果要转化为字符型
	
}
void Game(){
	// 棋盘初始化
	Init(mine_map,show_map);
	// 打印show_map
	printMap(show_map);
	int not_mine_count = 0;
	while (1){
		int row = 0;
		int col = 0;
		// 用户输入坐标
		printf("请输入要翻开的方块坐标(row,col):");
		scanf("%d %d",&row,&col);
		// 用户输入合法性检查
		if (row < 0 || row >= ROW || col < 0 || col >= COL){
			printf("坐标有误，请重新输入！");
			continue;
		}
		// 判断玩家是否踩雷，是，游戏结束，并打印结果
		if (mine_map[row][col] == '1'){
			printf("游戏结束");
			printMap(mine_map);
			break;
		}
		not_mine_count++;
		// 若没有踩雷，判断是否取胜
		if (not_mine_count == ROW*COL - MINE_COUNT){
			printf("你赢了！");
			printMap(mine_map);
			break;
		}
		// 游戏没有胜利，统计当前位置有几个雷，打印show_map;
		UpdateShowMap(show_map, mine_map, row, col); 
		printMap(show_map);
	}
}
int main(){
	int choice = Menu();
	if (choice == 1){
		Game();
	}
	else if (choice == 0){
		printf("goodbye！");
	}
	else{
		printf("error input");
	}
	system("pause");
	return 0;
}