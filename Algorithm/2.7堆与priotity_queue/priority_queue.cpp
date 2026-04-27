#include <iostream>
#include <queue>

using namespace std;
int a[]={1,24,45,67,345,23,1,453,56,3};
priority_queue<int,vector<int>,less<int>>heap1;//大根堆存储int ，存储方式为vector
priority_queue<int,vector<int>,greater<int>>heap2;//小根堆 

//存放结构体
struct node{
	int a,b,c;
	//以b为基准创建大根堆，大根堆为小于 
//	bool operator<(const node&x)const//表示b与下一个结构体比较的时候调用小于号时比较返回结果 
//	{
//		return b<x.b;
//	}
	//小根堆
	bool operator<(const node&x)const//第一个const表示不能修改引用值，
									//第二个const表示不能修改调用他的对象 
	{
		return b>x.b;
	 } 
}; 
priority_queue<node> heap6;
void test2()
{
	for(int i=1;i<=5;i++)
	{
		heap6.push({i,i*2,i*i});
	}
	while(heap6.size())
	{
		auto e=heap6.top();heap6.pop();
		cout<<e.a<<" "<<e.b<<' '<<e.c<<' '<<endl;
	}
 } 
void test1()
{
	for(int i=0;i<10;i++)
	{
		heap1.push(a[i]);
		heap2.push(a[i]);
	 } 
	 cout<<"大根堆："<<endl;
	 while(heap1.size())
	 {
	 	cout<<heap1.top()<<" ";
	 	heap1.pop();
	  } 
	  cout<<endl;
	cout<<"小根堆: "<<endl; 
	while(!heap2.empty())
	{
		cout<<heap2.top()<<" ";
		heap2.pop();
	}
}
int main()
{
	test2(); 
//	priority_queue<int>heap;//默认大根堆 
//	for(int i=0;i<10;i++)
//	{
//		heap.push(a[i]);
//	}
//	while(heap.size())
//	{
//		cout<<heap.top()<<' ';
//		heap.pop();
//	}
	
	return 0;
}
