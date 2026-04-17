#define _CRT_SECURE_NO_WARNINGS
#include"heap.h"

void Init(Hp* hp)
{
	assert(hp);
	hp->a = NULL;
	hp->capacity = hp->size = 0;
}
void Destory(Hp* hp)
{
	assert(hp);
	assert(hp->a);
	free(hp->a);
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
void Push(Hp* hp, Hpdatatype e)
{
	assert(hp);
	
	//判断空间
	if (hp->capacity == hp->size)
	{
		int newcapacity = hp->capacity == 0 ? 4 : sizeof(Hpdatatype) * hp->capacity * 2;
		Hpdatatype* tmp = NULL;
		tmp = (Hpdatatype*)realloc(hp->a, sizeof(Hpdatatype) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc error");
			return;
		}
		else
		{
			hp->a = tmp;
			hp->capacity = newcapacity;
		}
	}
	hp->a[hp->size] = e;
	//向上调整
	Adjustup(hp->a, hp->size);
	hp->size++;
}
//向下调整
void Adjustdown(Hpdatatype* a, int father, int size)
{
	int child = father * 2 + 1;//左孩子
	while (child  < size)//最后一个为删除元素
	{	//大根堆，找到最大的孩子
		if (a+1<size&&a[child + 1] > a[child])child++;
		if (a[father] < a[child])
		{
			Swap(&a[child], &a[father]);
			father = child;
			child = father * 2 + 1;
		}
		else
			break;
	}
	
}
void Pop(Hp* hp)
{
	Swap(&hp->a[0], &hp->a[hp->size - 1]);
	//向下调整
	hp->size--;
	Adjustdown(hp->a, 0, hp->size);
	
}
bool Empty(Hp hp)
{
	return hp.size == 0;
}
Hpdatatype Top(Hp hp)
{
	
	return hp.a[0];
}