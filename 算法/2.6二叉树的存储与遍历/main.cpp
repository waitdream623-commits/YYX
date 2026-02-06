#include<iostream>
#include<queue>//bfs广度优先搜索使用

using namespace std;
const int N=1e6+10;
int l[N],r[N];//使用链式存储二叉树
//先序
void dfs1(int x)
{
	cout<<x<<' ';
	if(l[x])dfs1(l[x]);
	if(r[x])dfs1(r[x]); 
	
 } 
 //中序
 void dfs2(int x)
 {
 	
 	if(l[x])dfs2(l[x]);
 	cout<<x<<' ';
 	if(r[x])dfs2(r[x]);
  } 
  //后序
void dfs3(int x)
{
	if(l[x])dfs3(l[x]);
	if(r[x])dfs3(r[x]);
	cout<<x<<' ';
	
 } 
 //广度
 void bfs()
 {
 	queue<int>q;
 	q.push(1);//根节点为1 
 	while(q.size())
	 {
	 	auto t=q.front();q.pop();
	 	cout<<t<<' ';
	 	if(l[t])q.push(l[t]);//存在就加入队列 
	 	if(r[t])q.push(r[t]);
	  } 
 	
  } 

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>l[i]>>r[i];
		
	}
	//深度优先搜索
	//1，先序搜索
	dfs1(1);
	cout<<endl;
	//2，中序搜索
	dfs2(1);
	cout<<endl;
	//3,后序搜索
	dfs3(1);
	cout<<endl;
	//广度优先搜索
	bfs(); 
	
	return 0;
 } 
