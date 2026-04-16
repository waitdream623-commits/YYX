#define _CRT_SECURE_NO_WARNINGS
#include"heap.h"
void heaptest()
{
	Hp hp;
	Init(&hp);
	int a[] = { 3,4,6,1,3,8,4,6,2,8 };
	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		Push(&hp, a[i]);
	}
	while (!Empty(hp))
	{
		Hpdatatype e = Top(hp);
		Pop(&hp);
		printf("%d ", e);
	}
	printf("\n");
	Destory(&hp);
}

int main()
{
	heaptest();
	return 0;
}