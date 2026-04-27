//链地址法
#include<iostream>

using namespace std;
const int N=23;

int h[N];
int e[N];int ne[N];
int id;
//哈希函数
int f(int x)
{
	return (x%N+N)%N;
 } 
 //插入（类似链式前向星）头插
 void insert(int x)
 {
 	int idx=f(x);//找到该链接在哪个哨兵位后面 
 	id++;
 	e[id]=x;
 	
 	ne[id]=h[idx];
 	h[idx]=id;
  } 
  //查找
  bool find(int x)
  {
  	int idx=f(x);
  	for(int i=h[idx];i;i=ne[i])
  	{
  		if(e[i]==x)
  		return true;
	  }
	  return false;
   } 
   int main()
   {
   	int n;cin>>n;
   	while(n--)
   	{
   		int op,x;
		cin>>op>>x;
		if(op==1)
		{
			insert(x);
			
		}
		else
		{
			cout<<find(x)<<endl; 
		}
	   }
   	return 0;
   }




////线性探测法
//
//#include<iostream>
//#include<cstring>
//using namespace std;
//const int M=23,INF=0x3f3f3f3f;
//int h[M];//哈希表
////初始哈希表 
//void init()
//{
//	memset(h,INF,sizeof(h));
//}
////哈希函数
//int f(int x)
//{
//	int idx=(x%M+M)%M;
//	//处理哈希冲突
//	while(h[idx]!=INF&&h[idx]!=x)//结束后idx找到未存储位置或者已经存储过的位置
//	{
//		idx++; 
//		if(idx==M)idx=0;//走到头了； 
//	 } 
//	 
//	return idx;
// } 
////插入
//void insert(int x)
//{
//	int idx=f(x);//找到对应下标
//	h[idx]=x;
// } 
// //查找
// bool find(int x)
// {
// 	int idx=f(x);
// 	return h[idx]==x;//idx要么是未存储要么是已经存储x 
//  } 
//int main()
//{
//	init();
//	int n;cin>>n;
//	while(n--)
//	{
//		int op,x;
//		cin>>op>>x;
//		if(op==1)
//		{
//			insert(x);
//			
//		}
//		else
//		{
//			cout<<find(x)<<endl; 
//		}
//	 } 
//	return 0;
//}
