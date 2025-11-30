#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int i = 1;
	int sum = 0;
	for (i; i < 101; i++)
	{
		
			sum += 1 / i;
			i++;
			sum -= 1 / i;

	}
	printf("ºÍÎª%d",sum);
	return 0;
}