#define _CRT_SECURE_NO_WARNINGS
#include"heap.h"
#include<time.h>
void heapsort(Hpdatatype* a, int s)
{
	//先建堆
	//向上建堆O(N*logN)
	/*for (int i = 0; i < s; i++)
	{
		Adjustup(a, i);
	}*/
	//向下调整建堆O(N)
	int end = (s - 1) / 2;
	for (int i = end; i >= 0; i--)
	{
		Adjustdown(a, i, s);//s表示个数，应传入最后一个的下一个
	}

	//升序大根堆

	for (int i = s - 1; i > 0; i--)
	{
		//将最大的移到最后
		Swap(&a[i], &a[0]);
		Adjustdown(a, 0, i);//传入最后一项下标，不包含最后一项

	}
}
void heaptest()
{
	Hp hp;
	Init(&hp);
	//测试入堆和出堆
	
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
	
	//堆排序

	/*int a[] = {6,344,234,77,1,354,567,78,23,55};
	int s = sizeof(a) / sizeof(int);
	heapsort(a, s);
	for (int i = 0; i < s; i++)
	{
		printf("%d ", a[i]);
		
	}
	printf("\n");*/
	Destory(&hp);
}
void heaptest2()
{
	Hp hp;
	Init(&hp);
	//topk问题
	int a[10] = { 44,657,34,123,6547,768,456,232,1234,65476 };
	for (int i = 0; i < 10; i++)
	{
		Push(&hp, a[i]);
	}
	int k = 4;
	while (k--)
	{
		printf("%d ", Top(hp));
		Pop(&hp);

	}
	
	
}
void creat()
{
	int n = 100000;
	srand(time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen error");
		return;
	}
	for (int i = 0; i < n; i++)
	{
		int x = (rand() + i) % 100000;
		fprintf(fin, "%d\n", x);

	}
	fclose(fin);
}
void heaptest3()
{
	int k;
	printf("求前K个大的数，请输入K\n");
	scanf("%d", &k);
	//先建造k个数据的堆
	int* Kmax = (int*)malloc(sizeof(int) * k);
	if (Kmax == NULL)
	{
		perror("malloc error");
		return;
	}
	const char* file = "data.txt";
	FILE* fout = fopen(file, "r");
	if (fout == NULL)
	{
		perror("fopen error");
		return;
	}
	// 读取文件中前k个数
	for (int i = 0; i < k; i++)
	{
		fscanf(fout, "%d", &Kmax[i]);
	}
	//向下调整建小堆
	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		Adjustdown(Kmax, i, k);
	}
	//读取剩下n-k个数，fscanf读取完成返回-1；
	int x;
	while (fscanf(fout, "%d", &x) > 0)
	{
		//维护堆
		if (x > Kmax[0])
		{
			Swap(&x, &Kmax[0]);
			//向下调整
			Adjustdown(Kmax, 0, k);
		}
	}
	//此时堆排，使用的为小根堆，应该为降序
	heapsort(Kmax, k);
	for (int i = 0; i < k; i++)
	{
		printf("%d ", Kmax[i]);
	}
	printf("\n");
}
int main()
{
	//creat();
	heaptest3();
	//heaptest2();
	//heaptest();
	return 0;
}