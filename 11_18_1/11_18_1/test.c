#include<stdio.h>
#include<stdlib.h>
/*
	�������η�Ϊ��������������
	�ȴ�ӡ�ϲ�������
	�ٴ�ӡ�²�������
*/
int main(){
	//������¼�����Ǵ�ӡ��֮��j�Ĵ�С����һ���ж��ٸ���*��
	int cnt = 0;
	//���ѭ������ѭ������������ӡ����
	for (int i = 1; i < 13; i++){
		//�ڲ�ѭ������ÿһ�д�ӡ�ġ�*������
		if (i < 7){
			//��ӡ������
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