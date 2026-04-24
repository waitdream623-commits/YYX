#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//int main()
//{
//	int nine = 0;
//	int i = 0;
//	//产生１～１００数字
//	for (i = 1; i <= 100; i++)
//	{
//		if (9 == i % 10)
//		{
//			printf("%d ", i);
//			nine++;printf("\n");
//		}
//		
//	}
//	printf("%d \n", nine);
//	return 0;
//}
//int main()
//{
//	int arr[10] = { 0 };
//	while (scanf("%d ", &arr[10]) != EOF)
//	{
//		printf("%d ", arr[10]);
//	 }
//
//
//	return 0;
//}
int main()
{
	
	int st = 0;
	int end = 0;
	int input = 0;
	do
	{
		printf("是否开始操作（输入1开始，0结束)\n");
		scanf("%d", &input);
		printf("请输入生成质数范围：");
		scanf("%d %d", &st, &end);
		int i = st;
		for (i = st; i <= end; i++)
		{
			if (i == 1)
				continue;
			int j = 0;
			for (j = 2; j < i; j++)
			{
				if (i % j == 0)
					break;
			}
			if (j >= i)
				printf("%d ", i);
			
		}printf("\n");
	} while (input);
		return 0;
}