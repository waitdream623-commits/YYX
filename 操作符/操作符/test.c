#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//int main()
//{
//	int a = 10;
//	int b = a >> 1;
//	printf("%d %d", a, b);
//
//
//	return 0;
//}
//
#include <stdio.h>
int main()
{
	int num1 = -3;
	int num2 = 5;
	printf("%d\n", num1 & num2); //5
	printf("%d\n", num1 | num2); //-3
	printf("%d\n", num1 ^ num2); //-8
	printf("%d\n", ~0);   //-1
	return 0;
}