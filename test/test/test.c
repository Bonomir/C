#include<stdio.h>
#include<stdlib.h>
//用于测试字符是否属于特定的字符类别，如字母字符、控制字符等等
#include<ctype.h>
//强制大写 &~32
//强制小写 或
//大小写转换 异或
int main(){
	char ch = getchar();
	// 是否为字母
	if (iswalpha(ch)){
		//是否为小写
		if (islower(ch))
			putchar(ch^32);
		if (isupper(ch))
			putchar(ch ^ 32);
	}
	// 是否为数字
	if (isdigit(ch));
	system("pause");
	return 0;
}