#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void game();
void menu()
{

	printf("*******************************\n");
	printf("********1.start  0.quit********\n");
	printf("*******************************\n");
}
int main() {
	int input = 0;
	srand((unsigned int)time(NULL));
	
	do
{			
		menu();
		printf("请选择：\n");
		scanf("%d", &input);
	switch (input)
	{
	case 1:
		game();
		break;
	case 0:
		break;
	default:
		printf("输入错误，请重新输入。\n");
	}
}		while (input);
		return 0;
	}
void game()
{
	int guess = 0;
	int r = rand()%100+1;
	printf("请猜数字(1到100)：\n");
	int count = 0;
	while(1)
	{ 
		scanf("%d", &guess);
		count++;
		if (guess < r)
		{
			printf("猜小了\n");
		}
		else if (guess > r)
		{
			printf("猜大了\n");
		}
		else
		{
			printf("奖励飞吻\n");
			printf("你猜了%d次\n",count);
			break;
		}
	}
}