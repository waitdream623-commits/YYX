#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	char arr1[20] = "abcfdde";
	char arr2[] = "dde";
	strstr(arr1, arr2);
	return 0;
}