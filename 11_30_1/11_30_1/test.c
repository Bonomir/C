#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_ROW 3
#define MAX_COL 3
/*
	Ŀ�ģ�ʵ��һ����������Ϸ
	��Ϸ����
		�����������壬������һ��3*3�����̣�˭������һ���ߣ����ܹ���ʤ
	���裺
	ģ��һ������һ���˵���Ŀ
	ģ�������Ϸ����
			��ģ�飺
			һ����ʼ������
			�����������    ��ӡ��������̣�
			������������	��ӡ��������̣�
			�ģ��ж���Ӯ ����Ӯ����壩
	
*/
int menu(){
	printf("****************************\n");
	printf("    ��ӭ������������Ϸ0\n");
	printf("    1 ��ʼ��Ϸ\n");
	printf("    0 �˳���Ϸ\n");
	printf("****************************\n");
	int choice = 0;
	printf("���������ѡ��");
	scanf("%d",&choice);
	return choice;
}
// ��ʼ����������ʼ������
void Init(char chessBoard[MAX_ROW][MAX_COL]){
	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_ROW; col++){
			chessBoard[row][col] = ' ';//��ʼ��Ϊ���ַ�
		}
	}
}
// �������
void playerMove(char chessBoard[MAX_ROW][MAX_COL]){
	// �������ͨ���������� �����ַ���Ϊ  'X'���ﵽ���ӵ�Ч��
	int row = 0;
	int col = 0;
	while (1){
		printf("��������Ҫ���ӵ��������꣬��ʽΪ[0 0]:");
		scanf("%d %d", &row, &col);
		// �ж������Ƿ�Ϸ���Ҫ���ӵĵط��Ƿ�Ϸ������Ϸ��������ӣ����Ϸ�����������
		// ���кϷ������ӵط��Ϸ�
		if (row < 0 && row >= MAX_ROW 
			|| col < 0 && col >= MAX_COL 
			|| chessBoard[row][col] != ' '){
			continue;
		}
		chessBoard[row][col] = 'X';
		break;
	}
}
// �������� �� �����
void computerMove(char chessBoard[MAX_ROW][MAX_COL]){
	srand((unsigned int)time(NULL));
	char row = 0;
	char col = 0;
	// �������еó��Ľ����Ȼ�������ϣ����ֻ��Ҫ�ж�����õ����������Ƿ��Ѿ�
	//����������û������������ڸô�������������������
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
	// ��ӡ֮ǰ������
	system("cls");
	printf("+��+��+��+\n");
	for (int row = 0; row < MAX_ROW; row++){
		printf("|");
		for (int col =0; col < MAX_COL; col++){
			printf("%c |",chessBoard[row][col]);
		}
		printf("\n");	
		printf("+��+��+��+\n");
	}
}
// ��Ӯ�ж�
char Check(char chessBoard[MAX_ROW][MAX_COL]){
	// ���Ӯ�����
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
	// ����Ӯ�����
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
	// ƽ�ֵ����
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
	return 'C';// ��û�д���������Ļ��������ַ�c����ʾ����������
}

void Winner(char winner){
	if (winner == 'X'){
		printf("��ϲ�㣬��Ӯ�ˣ�\n");
	}
	else if (winner == 'O'){
		printf("����ˣ��������Զ��²�����\n");
	}
	else if (winner == 'P'){
		printf("������¸����壡��ˣ�\n");
	}
}
void Game(char chessBoard[MAX_ROW][MAX_COL]){
	// ���̳�ʼ��
	Init(chessBoard);
	Print(chessBoard);
	char winner;
	while (1){
		//�������
		playerMove(chessBoard);
		// ��ӡ����
		Print(chessBoard);
		winner = Check(chessBoard);
		Winner(winner);
		// ��������
		computerMove(chessBoard);
		printf("�������ӣ�");
		Print(chessBoard);
		//	�ж���Ӯ
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
	// ��ʼ���˵�
	choice = menu();
	// ��������
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

