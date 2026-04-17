#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef int Hpdatatype;
//顺序表，下标访问
typedef struct Heap {
	Hpdatatype* a;
	int size;
	int capacity;
}Hp;
//初始化
void Init(Hp* hp);
//销毁
void Destory(Hp* hp);
void Swap(Hpdatatype* a, Hpdatatype* b);
//向上调整建堆
void Adjustup(Hpdatatype* a, int child);
//插入
void Push(Hp* hp, Hpdatatype e);
//向下调整
// void Adjustdown(Hpdatatype* a, int father, int size);
//删除
void Pop(Hp* hp);
//判空
bool Empty(Hp hp);
//堆头
Hpdatatype Top(Hp hp);

