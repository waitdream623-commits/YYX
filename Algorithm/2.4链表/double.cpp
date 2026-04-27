#include<iostream>
using namespace std;
const int N=1e5;
int e[N],pre[N],ne[N],mp[N];
int h,id;
//头插
void push_front(int x)
{
	id++;
	e[id]=x;
	mp[x]=id;//标记数组，存储x的位置 
	pre[id]=h;
	ne[id]=ne[h];
	pre[ne[h]]=id;
	ne[h]=id;
 } 
 //遍历数组打印
 void print()
 {
 	for(int i=ne[h];i;i=ne[i])//i转到下一个位置 
 	{
 		cout<<e[i]<<' ';
	 }
	 cout<<endl;
  } 
  //按值查找位置
  int find(int x)
  {
  	return mp[x];

   } 
   //在任意位置之后插入元素
   void insert_back(int p,int x)
   {
   	id++;
   	e[id]=x;
   	mp[x]=id;
   	pre[id]=p;
   	ne[id]=ne[p];
   	pre[ne[p]]=id;
   	ne[p]=id;
	} 
	//在任意位置之前插入元素(p的前指针最后改） 
void insert_front(int p,int x)
{
	id++;
	e[id]=x;
	mp[x]=id;
	pre[id]=pre[p];
	ne[id]=p;
	ne[pre[p]]=id;
	pre[p]=id; 
	 }	
	 //删除任意位置元素
	 void erase(int p)
	 {
	 	mp[e[p]]=0;//标准元素消失 
	 	ne[pre[p]]=ne[p];
	 	pre[ne[p]]=pre[p];
	  } 
int main()
{
	for(int i=1;i<=5;i++)
	{
		push_front(i);
		print();
	}
	insert_back(2,9);
	print();
	insert_front(3,8);
	print();
	erase(3);
	print();
	cout<<find(3);
	return 0;
}
