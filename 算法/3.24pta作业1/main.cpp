//2-5 最长连续递增子序列
#include <iostream>
using namespace std;

const int N=1e5+10; 

int a[N];
int n;
int main()
{
	cin>>n;
	
	int rl=1,rr=1;
	int ret=0;
	int l=1,r=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>a[i-1])r++;
		else 
		{
			//计算长度 
			int tmp=r-l+1;
			 
			if(ret<tmp)
			{
				ret=tmp;
				rl=l;
				rr=r;
			}
			l=i;
			r=i;
		}
	}
	if(ret==0)rr=n;
	int flag=1;
	for(int i=rl;i<=rr;i++)
	{
		if(flag)
		{
			cout<<a[i];
			flag=0;
		}
		
	else
	{
		cout<<" "<<a[i];
	 } 
	}
	return 0;
 } 
//#define LIST_INIT_SIZE 10
//#include <stdio.h>
//#include <stdlib.h>
//#include <malloc.h>
//typedef struct{
//    int *elem;//存储空间的基地址
//    int length;//当前长度
//    int listsize;//当前分配的存储容量，以sizeof(ElemType)为单位
//}SqList;
//
//void Reverse(SqList &L);
//
//int main()
//{
//  SqList L;
//  int m;
//  L.elem=(int*)malloc((LIST_INIT_SIZE)*sizeof(int));
//  if(!L.elem) exit(-2);
//  L.length=0;
//  L.listsize=LIST_INIT_SIZE;
//  m=scanf("%d",&L.length);
//  for(int i=0;i<L.length;i++)  
//     m=scanf("%d",&L.elem[i]);
//  Reverse(L);
//  return 0;
//}
//
///* 请在这里填写答案 */
//void Reverse(SqList &L)
//{
//    int l=L.length;
//    for(int i=0;i<l/2;i++)
//        {
//           int tmp= L.elem[i];
//            L.elem[i]=L.elem[l-i-1];
//            L.elem[l-i-1]=tmp;
//        }
//  打印 
//}
