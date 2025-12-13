#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
//实现数据多样化
typedef int SLDataType;
//定义节点结构
//数据+下一个节点的指针
typedef struct SLsitNode {
	SLDataType data;
	struct SLsitNode* next;
}SLTNode;
//打印
void SLTPrint(SLTNode* phead);
//尾插
void SLTPushBack(SLTNode** pphead, SLDataType x);
//头插
void SLTPushFront(SLTNode** pphead, SLDataType x);
//尾删
void SLTPopBack(SLTNode** pphead);
//头删
void SLTPopFront(SLTNode** pphead);
//查找
SLTNode* SLTFind(SLTNode* phead, SLDataType x);
//指定位置之前插入数据
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLDataType x);
//指定位置之后插入数据
void SLTInsertAfter( SLTNode* pos, SLDataType x);
//指定位置删除
void SLTErase(SLTNode** pphead, SLTNode* pos);
//删除pos之后的所有节点
void SLTEraseAfter( SLTNode* pos);
//  销毁链表
void SLTDestroy(SLTNode** pphead);
