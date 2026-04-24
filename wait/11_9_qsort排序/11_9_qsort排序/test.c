#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
//½á¹¹Ìå³ÉÔ±
struct stu
{
	char name[100];
	int age;
};
void test();
////°´ÕÕÃû×ÖÅÅÐò
//int com_stu_by_name(const void* p1, const void* p2)
//{
//	return strcmp(((struct stu*)p1)->name,((struct stu*)p2)->name);
//}
//°´ÕÕÄêÁäÅÅÐòË³Ðò
//int com_stu_by_age(const void* p1, const void* p2)
//{
//	return(((struct stu*)p1)->age- ((struct stu*)p2)->age);
//}
////°´ÕÕÄêÁäÅÅÐòµ¹Ðò
//int com_stu_by_age(const void* p1, const void* p2)
//{
//	return(((struct stu*)p2)->age - ((struct stu*)p1)->age);
//}
//
//
void test()
{
	struct stu arr[3] = { {"lemon",18},{"liling",221},{"yy",19}};
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), com_stu_by_age);
	for (int i = 0; i < sz;i++)
	{
		printf("name:%s£¬age£º%d\n", arr[i].name,arr[i].age);
	}
//	
//}
int com_int(const void* p1, const void* p2);
void type2();
int com_char(const void* p1, const void* p2); 
void test1();
void type1(int sz,int p[])
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ",p[i]);
	}
}
void type2(int sz, char p[])
{
	for (int i = 0; i < sz; i++)
	{
		printf("%c ", p[i]);
	}
}
int main()
{
	//ÅÅÐò¶ÔÏó
	
	test1();

	return 0;
}
//µ¹Ðò
int com_int(const void* p1, const void* p2)
{
	return(*((int*)p2) - (*(int*)p1));
}
int com_char(const void* p1, const void* p2)
{
		return(*((char*)p2) - (*(char*)p1));
}
void test1()
{
	int arr1[10] = { 5,6,7,4,3,8,9,2,1,0 };
	int sz1 = sizeof(arr1) / sizeof(arr1[0]);
	/*	qsort(arr1, sz1, sizeof(arr1[0]), com_int);*/
	char arr2[10] = "ACBDFEHGNM" ;
	int sz2 = sizeof(arr2) / sizeof(arr2[0]);
	qsort(arr2, sz2, sizeof(arr2[0]), com_char);

	/*type1(sz1,arr1);*/
	type2(sz2, arr2);
}
