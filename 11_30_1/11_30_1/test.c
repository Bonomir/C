#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_ROW 3
#define MAX_COL 3
/*
	目的：实现一个三子棋游戏
	游戏规则：
		类似于五子棋，现在有一个3*3的棋盘，谁先连成一条线，就能够获胜
	步骤：
	模块一；定义一个菜单项目
	模块二：游戏功能
			子模块：
			一：初始化棋盘
			二：玩家落字    打印结果（棋盘）
			三：电脑下棋	打印结果（棋盘）
			四：判断输赢 （输赢或和棋）
	
*/
int menu(){
	printf("****************************\n");
	printf("    欢迎来到五子棋游戏0\n");
	printf("    1 开始游戏\n");
	printf("    0 退出游戏\n");
	printf("****************************\n");
	int choice = 0;
	printf("请输入你的选择：");
	scanf("%d",&choice);
	return choice;
}
// 初始化函数，初始化棋盘
void Init(char chessBoard[MAX_ROW][MAX_COL]){
	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_ROW; col++){
			chessBoard[row][col] = ' ';//初始化为空字符
		}
	}
}
// 玩家落子
void playerMove(char chessBoard[MAX_ROW][MAX_COL]){
	// 玩家落子通过输入坐标 将空字符改为  'X'来达到落子的效果
	int row = 0;
	int col = 0;
	while (1){
		printf("请输入您要落子的行列坐标，格式为[0 0]:");
		scanf("%d %d", &row, &col);
		// 判断输入是否合法和要落子的地方是否合法，若合法，则落子，不合法则重新输入
		// 行列合法，落子地方合法
		if (row < 0 && row >= MAX_ROW 
			|| col < 0 && col >= MAX_COL 
			|| chessBoard[row][col] != ' '){
			continue;
		}
		chessBoard[row][col] = 'X';
		break;
	}
}
// 电脑落子 ； 随机下
void computerMove(char chessBoard[MAX_ROW][MAX_COL]){
	srand((unsigned int)time(NULL));
	char row = 0;
	char col = 0;
	// 由于行列得出的结果必然在棋盘上，因此只需要判断随机得到的坐标上是否已经
	//落过子与否，若没有则电脑落子在该处，否则，重新生成坐标
	while (1){
		row = rand() % MAX_ROW;
		col = rand() % MAX_COL;
		if (chessBoard[row][col] != ' '){
			continue;
		}
		chessBoard[row][col] = 'O';
		break;
	}
}
void Print(char chessBoard[MAX_ROW][MAX_COL]){
	// 打印之前先清屏
	system("cls");
	printf("+—+—+—+\n");
	for (int row = 0; row < MAX_ROW; row++){
		printf("|");
		for (int col =0; col < MAX_COL; col++){
			printf("%c |",chessBoard[row][col]);
		}
		printf("\n");	
		printf("+—+—+—+\n");
	}
}
// 输赢判断
char Check(char chessBoard[MAX_ROW][MAX_COL]){
	// 玩家赢的情况
	for (int row = 0; row < MAX_ROW; row++){
		if (chessBoard[row][0] == 'X'
			&&chessBoard[row][0] == chessBoard[row][1] 
			&& chessBoard[row][0] == chessBoard[row][2]){
			return 'X';
		}
	}
	for (int col = 0; col < MAX_COL; col++){
		if (chessBoard[0][col] == 'X'
			&&chessBoard[0][col] == chessBoard[1][col] 
			&& chessBoard[0][col] == chessBoard[2][col]){
			return 'X';
		}
	}
	if ((chessBoard[1][1] == 'X'
		&& chessBoard[0][0] == chessBoard[1][1]
		&& chessBoard[0][0] == chessBoard[2][2])
		|| (chessBoard[1][1] == 'X'
		&& chessBoard[0][2] == chessBoard[1][1]
		&& chessBoard[1][1] == chessBoard[2][0])){
		return 'X';
	}
	// 电脑赢的情况
	for (int row = 0; row < MAX_ROW; row++){
		if (chessBoard[row][0] == 'O'
			&&chessBoard[row][0] == chessBoard[row][1]
			&& chessBoard[row][0] == chessBoard[row][2]){
			return 'O';
		}
	}
	for (int col = 0; col < MAX_COL; col++){
		if (chessBoard[0][col] == 'O'
			&&chessBoard[0][col] == chessBoard[1][col]
			&& chessBoard[0][col] == chessBoard[2][col]){
			return 'O';
		}
	}
	if ((chessBoard[1][1] == 'O'
		&& chessBoard[0][0] == chessBoard[1][1]
		&& chessBoard[0][0] == chessBoard[2][2])
		|| (chessBoard[1][1] == 'O'
		&& chessBoard[0][2] == chessBoard[1][1]
		&& chessBoard[1][1] == chessBoard[2][0])){
		return 'O';
	}
	int pieceNumber = 0;
	// 平局的情况
	for (int row = 0; row < MAX_COL; row++){
		for (int col = 0; col < MAX_COL; col++){
			if (chessBoard[row][col] == ' '){
				break;
			}
			else if (chessBoard[row][col] != ' '){
				pieceNumber ++;
				if (9 == pieceNumber){
					return 'P';
				}
			}
		}
	}
	return 'C';// 若没有次三种情况的话，返回字符c，表示，继续运行
}

void Winner(char winner){
	if (winner == 'X'){
		printf("恭喜你，你赢了！\n");
	}
	else if (winner == 'O'){
		printf("你真菜，垃圾电脑都下不过！\n");
	}
	else if (winner == 'P'){
		printf("这你才下个和棋！真菜！\n");
	}
}
void Game(char chessBoard[MAX_ROW][MAX_COL]){
	// 棋盘初始化
	Init(chessBoard);
	Print(chessBoard);
	char winner;
	while (1){
		//玩家落子
		playerMove(chessBoard);
		// 打印棋盘
		Print(chessBoard);
		winner = Check(chessBoard);
		Winner(winner);
		// 电脑落子
		computerMove(chessBoard);
		printf("电脑落子：");
		Print(chessBoard);
		//	判断输赢
		winner = Check(chessBoard);
		if (winner == 'C'){
			continue;
		}
		Winner(winner);
		return;
	}
}
int main(){
	int choice = 0;
	// 初始化菜单
	choice = menu();
	// 定义棋盘
	char chessBoard[MAX_ROW][MAX_COL];
	if (choice == 1){
		Game(chessBoard);
	}
	else{
		printf("goodbye!");
	}
	system("pause");
	return 0;
}

