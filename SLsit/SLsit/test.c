#define _CRT_SECURE_NO_WARNINGS
#include"SList.h"
int main()
{
	SLTNode* list = NULL;
	SLTPushBack(&list, 1);
	SLTPushBack(&list, 2);
	SLTPushBack(&list, 3);
	SLTPushBack(&list, 4);
	SLTNode*find= SLTFind(list, 2);
	SLTEraseAfter(find);
			SLTPrint(list);
			SLTDestroy(&list);
			SLTPrint(list);

}