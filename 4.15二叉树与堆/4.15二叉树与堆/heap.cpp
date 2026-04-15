#define _CRT_SECURE_NO_WARNINGS
#include"heap.h"

void Init(Hp* hp)
{
	hp->capacity = hp->size = 0;
}
void destory(Hp* hp)
{
	assert(hp);
	free(hp);
	hp->capacity = hp->size = 0;
}
void Swap(Hpdatatype* a, Hpdatatype* b)
{
	Hpdatatype tmp = *a;
	*a = *b;
	*b = tmp;
}
void Adjustup(Hpdatatype* a, int child)
{
	int father = (child - 1) / 2;
	while(child > 0)
	{
		//大根堆
		if (a[child] > a[father])
		{
			Swap(&a[child], &a[father]);
			child = father;
			father = (child - 1) / 2;
		}
		else
			break;

	}
}
void push(Hp* hp, Hpdatatype e)
{
	assert(hp);
	//判断空间
	if (hp->capacity == hp->size)
		hp->a = (Hpdatatype*)realloc(hp->a, sizeof(hp->capacity == 0 ? 4 : sizeof(Hpdatatype) * hp->capacity * 2);
	
	hp->a[hp->size] = e;
	//向上调整
	Adjustup(hp->a, hp->size);
	hp->size++;
}