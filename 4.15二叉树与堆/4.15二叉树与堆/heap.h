#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
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
void destory(Hp* hp);
void Swap(Hpdatatype* a, Hpdatatype* b);
//向上调整建堆
void Adjustup(Hpdatatype* a, int child);
//插入
void push(Hp* hp, Hpdatatype e);
//删除
void pop(Hp* hp);

