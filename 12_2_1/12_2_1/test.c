#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
// ���׸���
#define MINE_COUNT 10
#define ROW 9 //����
#define COL 9 //����
int Menu(){
	printf("=================\n");
	printf("  1 ��ʼ��Ϸ\n");
	printf("  0 ������Ϸ\n");
	printf("=================\n");
	int choice = 0;
	printf("���������ѡ��\n");
	scanf("%d",&choice);
	return choice;
}
// ʵ�ʵ��ײ���ͼ
char mine_map[ROW][COL];
// �����չʾ�ĵ�ͼ
char show_map[ROW][COL];
void Init(char mine_map[ROW][COL], char show_map[ROW][COL]){
	// mime_map,��'0'��ʾ���ǵ��ף�'1'��ʾ����
	for (int row = 0; row < ROW; row++){
		for (int col = 0; col < COL; col++){
			mine_map[row][col] = '0';
		}
	}
	// show_map�У�ʹ��'*'��ʾû�д򿪵ķ��飬�򿪵ķֱ���Ե�״̬��ʾ
	for (int row = 0; row < ROW; row++){
		for (int col = 0; col < COL; col++){
			show_map[row][col] = '*';
		}
	}

	// ������õ���
	srand((unsigned int)time(NULL));
	int mine_count = MINE_COUNT;
	while (mine_count > 0){
		int row = rand() % 10;// �õ�����0-9
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
// ͳ������row,colλ�õ�Ԫ����Χ�м����ף����Ұѽ�����µ�show_map
void UpdateShowMap(char show_map[ROW][COL],char mine_map[ROW][COL],int row,int col){
	int mine_count = 0;//��Χ���׸���
	mine_count = (mine_map[row - 1][col - 1] - '0') + 
		(mine_map[row - 1][col] - '0') +
		(mine_map[row - 1][col + 1] - '0') +
		(mine_map[row][col - 1] - '0') +
		(mine_map[row][col + 1] - '0') +
		(mine_map[row + 1][col - 1] - '0') +
		(mine_map[row + 1][col] - '0') +
		(mine_map[row + 1][col + 1] - '0');
	show_map[row][col] = '0' + mine_count;//���Ҫת��Ϊ�ַ���
	
}
void Game(){
	// ���̳�ʼ��
	Init(mine_map,show_map);
	// ��ӡshow_map
	printMap(show_map);
	int not_mine_count = 0;
	while (1){
		int row = 0;
		int col = 0;
		// �û���������
		printf("������Ҫ�����ķ�������(row,col):");
		scanf("%d %d",&row,&col);
		// �û�����Ϸ��Լ��
		if (row < 0 || row >= ROW || col < 0 || col >= COL){
			printf("�����������������룡");
			continue;
		}
		// �ж�����Ƿ���ף��ǣ���Ϸ����������ӡ���
		if (mine_map[row][col] == '1'){
			printf("��Ϸ����");
			printMap(mine_map);
			break;
		}
		not_mine_count++;
		// ��û�в��ף��ж��Ƿ�ȡʤ
		if (not_mine_count == ROW*COL - MINE_COUNT){
			printf("��Ӯ�ˣ�");
			printMap(mine_map);
			break;
		}
		// ��Ϸû��ʤ����ͳ�Ƶ�ǰλ���м����ף���ӡshow_map;
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
		printf("goodbye��");
	}
	else{
		printf("error input");
	}
	system("pause");
	return 0;
}