#include<stdio.h>
#include<stdlib.h>
//���ڲ����ַ��Ƿ������ض����ַ��������ĸ�ַ��������ַ��ȵ�
#include<ctype.h>
//ǿ�ƴ�д &~32
//ǿ��Сд ��
//��Сдת�� ���
int main(){
	char ch = getchar();
	// �Ƿ�Ϊ��ĸ
	if (iswalpha(ch)){
		//�Ƿ�ΪСд
		if (islower(ch))
			putchar(ch^32);
		if (isupper(ch))
			putchar(ch ^ 32);
	}
	// �Ƿ�Ϊ����
	if (isdigit(ch));
	system("pause");
	return 0;
}