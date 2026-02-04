#include <iostream>

using namespace std;
 
//静态单链表模拟实现，带头单链表
const int N=1e5;
int e[N],ne[N],h,id;//e存储数据,ne存储下一个数据下标，h头位置，id指向与遍历
int mp[N];
//头插
void push_front(int x)
{
	id++;
	e[id]=x;
	mp[x]=id;
	//先链接下一位，再将ne[h]修改 
	ne[id]=ne[h];
	ne[h]=id;
 } 
 //遍历链表与打印
 void print()
 {
// 		int i=ne[h];
// 	while(id--)
// 	{
// 		cout<<e[i]<<' ';
// 		i=ne[i];
// 	
//	 }
	for(int i=ne[h];i;i=ne[i])//i=0的时候停止 
	{
		cout<<e[i]<<' ';
	}
	cout<<endl;
  } 
  //按值查找位置
  int find(int x)
  {
//  	for(int i=ne[h];i;i=ne[i])
//  	{
//  		if(e[i]==x)
//  		return i;
//	  }
//	  return 0;
//利用标记数组mp
	return mp[x]; 
   } 
//在任意位置之后插入数据（存储位置）
void insert(int p,int x)
{
	id++;
	e[id]=x;
	mp[x]=id;
	ne[id]=ne[p];
	ne[p]=id;
 } 
//删除任意位置之后的一个元素（不能选最后一个位置） 
void erase(int p)
{
	if(ne[p])//p的下一个不为空
	{
		mp[e[ne[p]]]=0;//清空p的下一个值的标记位置
		ne[p]=ne[ne[p]]; 
	 } 
}
int main()
{
	for(int i=1;i<=5;i++)
	{
		push_front(i);
		print();
	}
	insert(2,100);
	print();
	erase(2);//删除 
	print();
	return 0;
 } 
