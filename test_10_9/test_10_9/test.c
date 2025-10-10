#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char name[40];
	printf("The name of your family:");
	scanf("%s", name);
	printf("The % s family just maybe $ % .2f dollars richer£¡", name, 123.45 );

	return 0;
}

