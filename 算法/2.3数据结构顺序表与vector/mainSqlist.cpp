//模拟实现静态顺序表：创建，增删查改，封装
//从下表1开始存取 
//封装
#include<iostream> 
const int N=1e5+10;//不能太大，否侧错误 
using namespace std;
class Sqlist{
	int arr[N];
	int n;
	//构造函数 
	public: 
	Sqlist()
	{
		n=0;
	}
	void push_back(int x)
	{
		arr[++n]=x;
	}
	void print()
	{
		for(int i=1;i<=n;i++)
		{
			cout<<arr[i]<<' ';
		}
		cout<<endl;
	}
};
int main()
{
	Sqlist s1,s2;
	for(int i=1;i<=5;i++)
	{
		s1.push_back(i);
		s2.push_back(i*2);
	}
	s1.print();
	s2.print();
	return 0;
}
//#include<iostream>
//
//using namespace std;
//const int N=1e6+10;
//int arr[N];
//int n=0;
////打印
//void print()
//{
//	for(int i=1;i<=n;i++)
//	{
//		cout<<arr[i]<<' ';
//	}
//	cout<<endl;
// } 
////尾插
//void push_back(int x)
//{
//	arr[++n]=x;
// } 
// //头插
// void push_front(int x)
// {
// 	for(int i=n;i>0;i--)//将原先数据向后移动一位 
// 	{
// 		arr[i+1]=arr[i];
//	 }
//	 arr[1]=x;
//	 n++;
//  } 
//  //任意位置插入
//  void insert(int p,int x)
//  {
//  	for(int i=n;i>=p;i--)
//  	{
//  		arr[i+1]=arr[i];
//	  }
//	  arr[p]=x;
//	  n++;
//   } 
//   //尾删
//   void pop_back()
//   {
//   	n--; 
//	} 
////头删
//	void pop_front()
//	{
//		for(int i=2;i<=n;i++)
//		{
//			arr[i-1]=arr[i];
//		}
//		n--;
//		
//	 } 
//	 //任意位置删除
//void erase(int p)
//	{
//		for(int i=p+1;i<=n;i++)
//		{
//		 	arr[i-1]=arr[i];
//		}
//			 n--;
//	 } 
////按数值查找位置 ，失败返回-1； 
//int findpose(int x)
//{
//	for(int i=1;i<=n;i++)
//	{
//		if(arr[i]==x)
//		return i;
//	}
//	return -1;
// } 
// //按位置查找数值
// int findvalue(int p)
// {
// 	return arr[p];
//  } 
//  //修改
//  void change(int p,int x)
//  {
//  	arr[p]=x;
//   } 
//   //清空顺序表
//   viod clear()
//   {
//   	n=0;
//	} 
//int main()
//{
//		push_back(3);
//		push_back(2);
//		push_back(1);
//		push_back(6);
//		print(); 
//		push_front(0);
//		print();
//		insert(3,4);
//		print();
//		int p=findpose(3);
//		cout<<p<<endl;
//		int a=findvalue(2);
//		cout<<a<<endl;
//		change(3,9);
//		print();
//	return 0;
// } 
