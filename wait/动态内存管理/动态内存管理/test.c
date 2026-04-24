#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int* p = calloc(10, sizeof(int));
	int i = 0;
	if (p != NULL)
	{
		for (i; i < 10; i++)
		{
			p[i] = 5;
		}
	}
	int* ptr = realloc(p, 60);//如果开辟失败返回空指针
	///*p = realloc(p, 8);*/因此不能用p接收防止原数据丢失
	if (ptr != NULL)
	{
		p = ptr;
		for (i; i < 12; i++)
		{
			p[i] = 5;

		}
		for (int j = 0; j < i; j++)
		{
			printf("%d", p[j]);
		}
		
	}
	free(p);
		p = NULL;
		return 0;
}
//int main()
//{
//	int* p = calloc(10,sizeof(int));
//	int i = 0;
//	if (p != NULL)
//	{
//		for (i; i < 10; i++)
//		{
//			p[i] = 5;
//		}
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}
//int main()
//{
//    int*p = malloc(10 * sizeof(int));
//	int i = 0;
//	if (p != NULL)
//	{
//		for (i; i < 10; i++)
//		{
//			p[i] = 5;
//		}
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}