//queue
#include <iostream>
#include <queue>


using namespace std;
  
typedef pair<int,int> PII; 
queue<PII>q;
int main()
{
	for(int i=1;i<=10;i++)
	{
		q.push({i,i*i});
	}
	while(q.size())
	{
		PII t=q.front();
		cout<<t.first<<' '<<t.second<<endl;
		q.pop();
	}
	
}

////队列模拟实现
//#include <iostream>
//using namespace std;
//const int N=1e5+10;
//int q[N],h,t;//h为第一个元素的前一个坐标 
////入队
// void push(int x){
// 	q[++t]=x;
// }
// //出队
// void pop()
// {
// 	h++;
//  } 
//  //判空
//  bool empty()
//  {
//  	return h==t;
//   } 
//   //返回头元素
//   int front()
//   {
//   	return q[h+1];
//	} 
//	//返回队尾元素
//	int back()
//	{
//		return q[t];
//	 } 
//	 //返回大小
//	 int size()
//	 {
//	 	return t-h;
//	  } 
//int main()
//{
//	//测试
//	for(int i=1;i<=10;i++)
//	{
//		push(i);
//		
//	 } 
//	 for(int i=1;i<=10;i++)
//	 {
//	 	cout<<front()<<' '<<back()<<endl;
//	 	pop();
//	 }
//	return 0;
// } 
