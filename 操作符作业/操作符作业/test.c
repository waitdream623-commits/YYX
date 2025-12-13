#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//// 单身狗
//int main()
//{
//	int arr[10] = { 1,1,2,3,3,4,4,5,5 };
//		//找出只有一个的数
//		//a^a=0
//	int x = 0;
//	for (int i = 0; i < 10; i++)
//	{
//		x^= arr[i];
//	}
//	printf("%d", x);
//	return 0;
//}
//不创造临时变量，交换两值
//int main()
//{
//	int a = 3;
//	int b = 5;
//	a = a + b;
//	b = a - b;
//	a = a - b;
//	printf("a等于%d，b等于%d\n",a,b);
//	a ^= b;
//	b ^= a;
//	a ^= b;
//	printf("a等于%d，b等于%d\n", a, b);
//
//	return 0;
//}
//打印整数二进制的奇数位和偶数位
//获取一个整数二进制序列中所有的偶数位和奇数位，分别打印出二进制序
//	int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	//打印偶数位
//	printf("打印偶数位\n");
//
//	int x = 2;
//	for (int i = 0; i < 32; i++)
//	{
//
//		if ((x & a) != 0)
//			printf("%d", 1);
//		else
//		{
//			printf("%d", 0);
//		}
//
//		x <<= 2;
//	}
//	printf("\n");
//
//	//打印奇数位
//	printf("打印奇数位\n");
//
//	 x = 1;
//	for (int i = 0; i < 32; i++)
//	{
//
//		if ((x & a) != 0)
//			printf("%d", 1);
//		else
//		{
//			printf("%d", 0);
//		}
//		x <<= 2;
//	}
//	printf("\n");
//
//}
//打印整数二进制的奇数位和偶数位
//获取一个整数二进制序列中所有的偶数位和奇数位，分别打印出二进制序
int main()
{

		int a = 0;
		scanf("%d", &a);
	//打印偶数
	for (int i = 31; i >= 1; i-=2)
	{
		printf("%d", (a>>i) & 1);
	}
	printf("\n");
	for (int i = 30; i >= 0; i -= 2)
	{
		printf("%d", (a >> i) & 1);
	}

}