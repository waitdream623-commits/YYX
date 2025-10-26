#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int if_leap_year(int b)
{
	if ((b % 4 == 0 && b%100 != 0) || b % 400 == 0)
	{
		printf("%d是润年\n", b);
	}
	else
	{
		printf("%d不是润年\n", b);
	}

}
int main()
{
	int a = 0;
	do
	{
		printf("请输入需要判断年（输入886退出程序）\n");
		scanf("%d", &a);
		if_leap_year(a);
	} while (a != 886);
	
	return 0;
}