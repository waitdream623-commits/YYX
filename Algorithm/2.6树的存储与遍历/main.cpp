//运用链表存储
#include<iostream>
#include <queue>
using namespace std;

const int N=1e5+10;
bool f[N];
int h[N],e[N*2],ne[N*2],id;//e与ne需要将边两端均存起来，h[i]代表i节点的哨兵位，边两端分别头插到对应哨兵位 
void add(int a,int b)//链表头插 
{
	id++;
	e[id]=b;
	ne[id]=h[a];
	h[a]=id; 
	
 } 
 //dfs
 void dfs(int x)
 {
 	cout<<x<<' ';
 	f[x]=true;
 	for(int i=h[x];i;i=ne[i])//遍历孩子 
 	{
 		int t=e[i];
 		if(!f[t])
 		{
 			dfs(t);
		 }
	 }
 }
 //bfs
 void bfs()
 {
 	queue<int>q;
 	q.push(1);
 	while(q.size())
 	{
 		auto tmp=q.front();q.pop();
 		cout<<tmp<<" ";
 		f[tmp]=true;
 		for(int i=h[tmp];i;i=ne[i])//遍历孩子，加入队列 遍历从哨兵位下一个节点开始 
 		{
 			auto x=e[i];
 			if(!f[x])
 			q.push(x);
		 }
	 }
  } 
int main()
{
	int n;
	cin>>n;//n个节点
	for(int i=1;i<n;i++)
	{
		int a,b;cin>>a>>b;
		add(a,b);add(b,a);//无根节点，两边都存储孩子 
	 } 
	bfs();
 } 


////使用vector数组存储
//#include <iostream>
//#include <vector>
//#include <queue> 
//using namespace std;
//const int N=1e5+10; 
//int n;//节点个数
//vector<int>edge[N]; //每个egde[i]代表i节点中的孩子
//bool f[N];//标记该节点是否访问过（用于遍历），因为是按照无根数组存储，可能导致死遍历
////dfs
//void dfs(int a)//从根节点开始递归
//{
//	cout<<a<<" ";
//	f[a]=true;
//	for(int e:edge[a])
//	{
//		if(!f[e])//为零即为访问过 
//		dfs(e);
//	 } 
// } 
// //bfs运用队列 
// void bfs()
// {
// 	queue<int>q;
// 	q.push(1);//根节点
// 	
//	while(q.size())
//	{
//		int tmp=q.front();q.pop();
//		f[tmp]=true;
//		cout<<tmp<<' ';
//		for(auto e:edge[tmp])//将孩子加入队尾 
//		{
//			if(!f[e])
//			{
//				q.push(e);
//				
//			}
//		}
//	 } 
//  } 
//int main()
//{
//	cin>>n;
//	for(int i=1;i<n;i++)//n-1个边
//	{
//		int a,b;cin>>a>>b;
//		 edge[a].push_back(b);edge[b].push_back(a);
//	 } 
//	 bfs(); 
// } 
