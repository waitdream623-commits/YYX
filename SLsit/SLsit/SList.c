#define _CRT_SECURE_NO_WARNINGS
#include"SList.h"
//打印数据
void SLTPrint(SLTNode* phead)
{
	SLTNode* pcur = phead;
	while (pcur)
	{
		printf("%d->", pcur->data);
		pcur = pcur->next;
	}
	printf("NULL\n");
}
//申请空间存储数据
SLTNode* SLTBuyNode(SLDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	//申请失败
	if (newnode==NULL)
	{
		perror("malloc fail!");
			exit(1);
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}
//尾插
void SLTPushBack(SLTNode** pphead, SLDataType x)
{
	//防止传来空地址
	assert(pphead);
	//*pphead 指向第一个节点的指针
	//申请空间
	SLTNode* newnode = SLTBuyNode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		//找尾接上新申请（插入）数据
		SLTNode* ptail = *pphead;
		while (ptail->next)
		{
			ptail = ptail->next;
		}
		ptail->next = newnode;
	}
}
//头插
void SLTPushFront(SLTNode** pphead, SLDataType x)
{
	assert(pphead);
	SLTNode* newnode = SLTBuyNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}
//尾删
void SLTPopBack(SLTNode** pphead)
{
	assert(pphead && *pphead);//防止传来空指针和空链表
	//仅有一个节点
	if ((*pphead)->next==NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{

		SLTNode* pcur = *pphead;
		SLTNode* prev = *pphead;
		while (pcur->next)
		{
			prev = pcur;
			pcur = pcur->next;
		}
		free(pcur);
		pcur = NULL;
		prev->next = NULL;//如果仅有一个节点，非法报错
	}
}
//头删
void SLTPopFront(SLTNode** pphead)
{
	//防止传空指针和空链表
	assert(pphead && *pphead);
	SLTNode* pcur = (*pphead)->next;
	/*SLTNode* pcur = (**pphead).next;*//*仅可使用这两种方法*/

	free(*pphead);
	*pphead = pcur;
	
}
//查找
SLTNode* SLTFind(SLTNode* phead, SLDataType x)
{
	SLTNode* pcur = phead;
	while (pcur)//不能是pcur->next,此时会导致pcur未判断data
	{
		if (pcur->data == x)
		{
			return pcur;
		}
		pcur = pcur->next;
	}
	printf("没找到，无该数据");
	return  NULL;
}
//在指定位置之前插入数据
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLDataType x)
{
	assert(pphead && *pphead && pos);
	//如果是头插
	if (*pphead == pos)
	{
		SLTPushFront(pphead, x);
	}
	else
	{
		SLTNode* newnode = SLTBuyNode(x);
		SLTNode* prew = *pphead;
		while (prew->next != pos)
		{
			prew = prew->next;
		}
		prew->next = newnode;
		newnode->next = pos;

	}
	
}
//指定位置之后插入数据
void SLTInsertAfter(SLTNode* pos, SLDataType x)
{
	assert(pos);
	SLTNode* newnode = SLTBuyNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}
//指定位置删除
void SLTErase(SLTNode** pphead, SLTNode* pos) {
	assert(pphead && *pphead && pos);
	//如果为第一个节点
	if (*pphead == pos)
	{
		SLTPopFront(pphead);
	}
	else
	{
		//找到pos前一个节点
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
			
		}
		prev->next = pos->next;
			free(pos);
			pos = NULL;
	}
	
}
//删除pos之后的节点
void SLTEraseAfter(SLTNode* pos) {
	assert(pos && pos->next);
	SLTNode* del = pos->next;
	pos->next = del->next;
	free(del);
	del = NULL;

}
//销毁链表
void SLTDestroy(SLTNode** pphead)
{
	SLTNode* pcur = *pphead;
	while (pcur) {
		SLTNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	*pphead = NULL;
}
