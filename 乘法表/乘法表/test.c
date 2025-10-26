#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int row = 0;
	int col = 0;
	printf("请输入需要口诀表范围（竖与横)\n");
	scanf("%d%d", &row, &col);
	for (int i = 1; i <= col; i++)
	{
		for (int j = 1; j <= row; j++)
		{
			int c = i * j;
			printf("%2d*%d=%-5d", i, j,c);
		}
		printf("\n");
	}
	return 0;
}
