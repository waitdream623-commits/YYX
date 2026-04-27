//P1996 约瑟夫问题
#include<iostream>
using namespace std;
const int N=110;
int h,id,e[N],ne[N],pre[N];
int main()
{
	int n,m;
	cin>>n>>m;
	id=-1;
	//初始化
	for(int i=0;i<=n;i++)
	{
		e[i]=i;
		ne[i]=i+1;
		pre[i]=i-1;
		//计数 
		id++;
	 } 
	 //最后一个指向第一个//需要构成循环链表 
	ne[n]=1; 
	pre[1]=n;
	
	 int x=m-1;
	 int i=ne[h];
	 while(id!=1)
	 {
	 	int t=x;
	 	while(t--)
	 	{
	 		i=ne[i];
		 }
		 cout<<e[i]<<' ';//1的前一个为未存值位置需要特殊讨论（需要保证链表循环） 
		 ne[pre[i]]=ne[i];
		 pre[ne[i]]=pre[i];
		 	i=ne[i];
	 		id--; 
	 }
	  cout<<e[i];//输出最后一个 
	
	return 0;
 } 

////P1160 队列安排
////有左右之分，需要找到前一个使用双链表 
//#include<iostream>
//using namespace std;
//const int N=1e5+10;
//int e[N],pre[N],ne[N],h,id,mp[N];
//
//int main()
//{
//	//初始化
//	id++;
//	e[id]=1;
//	mp[1]=id;
//	ne[h]=id;
//	pre[id]=h;
//	int n;
//	cin>>n;
//	n--;
//	int p;
//	while(n--)
//	{
//	 
//		int s,op;
//		cin>>s>>op;
//		p=mp[s];//找到s位置，将第i位同学放他右边 
//		if(op)//右边
//		{
//			id++;
//			e[id]=id;
//			mp[id]=id;
//			
//			ne[id]=ne[p];
//			pre[id]=p;
//			
//			pre[ne[p]]=id;
//			ne[p]=id; 
//		 } 
//		 else//左边
//		 {
//		 	id++;
//		 	e[id]=id;
//		 	mp[id]=id;
//		 	
//		 	ne[id]=p;
//		 	pre[id]=pre[p];
//		 	
//		 	ne[pre[p]]=id;
//		 	pre[p]=id;
//		  } 
//	 } 
//	 //删除m位
//	 int m;
//	 cin>>m;
//	 while(m--)
//	 {
//	 	int s;
//	 
//	 	cin>>s;
//	 	if(mp[s])//s为空忽略 
//	 	{
//	 	p=mp[s];
//	 	ne[pre[p]]=ne[p];
//	 	pre[ne[p]]=pre[p];
//	 	mp[s]=0;
//	 	
//		 }
//	  } 
//	  //打印最后数据
//	  for(int i=ne[h];i;i=ne[i]) 
//	  {
//	  	cout<<e[i]<<' ';
//	  }
//	return 0;
// }  

////B3631 单向链表
////数字不相同可以使用标记数组快速查找位置 
//#include<iostream>
//using namespace std;
//const int N=1e6+10;
//int e[N],ne[N],mp[N];
//int  h,id,p;
////指定位置后插入
//void insert(int x,int y)
//{
//	 p=mp[x];//找到x位置，把y插入x后
//	id++;
//	e[id]=y;
//	mp[y]=id;
//	ne[id]=ne[p];
//	ne[p]=id; 
// } 
// //删除x后面的元素
// void erase(int x)
// {
// 	 p=mp[x];
// 	mp[e[ne[p]]]=0;//删除标记 
// 	ne[p]=ne[ne[p]];
// 	
// }
//  
//int main()
//{
//	//初始化 
//	id++;//注意id第一次初始化 
//	e[1]=1;
//	mp[1]=1;
//	ne[h]=1;
//	int q;
//	cin>>q;
//	while(q--)
//{
//		int op,x,y;
//		cin>>op;
//	 switch(op)
//	 {
//	 	case 1:
//	 		cin>>x>>y;
//	 		insert(x,y);
//			 break; 
//		case 2:
//			cin>>x;
//			 p=mp[x];
//			cout<<e[ne[p]]<<endl;
//			break;
//		case 3:
//			cin>>x;
//			erase(x);
//			break;
//			
//	 }
//	
//}
//	return 0;
// } 
////B3630 排队顺序
//#include<iostream>
//const int N=1e6+10;
//int ne[N]; 
//using namespace std;
//
//int main()
//{
//	int n;
//	cin>>n;
//	for(int i=1;i<=n;i++)
//	{
//		cin>>ne[i];
//	}
//	//打印顺序
//	int head;
//	cin>>head;
//	for(int i=head;i;i=ne[i])//最后一位存储位置位0即结束 
//	{
//		cout<<i<<' ';
//	 } 
// } 
