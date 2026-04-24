#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
static void menu()
{
	printf("********************\n");
	printf("*****1.start *******\n");
	printf("*****0.exit  *******\n");
	printf("********************\n");

}
int main()
{
	int input = 0;
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("开始游戏\n");
			/*game();*/
			break;
		case 0:
			break;
		default:
			printf("请从1/0中选择\n");
			break;
		}
	} while (input);
	return 0;
}