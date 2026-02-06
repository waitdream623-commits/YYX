//P3884 [JLOI2009] 二叉树问题
//不是二叉树结构，利用vector存储
#include<iostream>
#include<vector>
#include<queue>//求宽度 
using namespace std;
const int N=110;
vector<int>edge[N];
int fa[N];//fa[i]存储i的父节点 ,向上遍历
int dist[N];//dist[i]表示i距离x的距离 
//求深度 
int dfs(int x)
{
	int ret =0; 
	for(auto e:edge[x])//遍历子树找最高，当为叶子节点时无内容无法进行遍历，返回1； 
	{
		ret=max(dfs(e),ret); 
	 } 
	 return ret+1;
	
}
//求宽度
void bfs()
{
	queue<int>q;
	q.push(1); 
	int ret=0;
	while(q.size())
	{
		//一层的全部入队，后全部出队，加入子，统计每次队大小的最大值
		int s=q.size();
		ret=max(s,ret);
		 while(s--) //进队的全部出去，并加入子树 
		 {
		 	int t=q.front();q.pop();
		 	for(auto e:edge[t])
		 	{
		 		q.push(e);
			 }
		 }
	 } 
	 cout<<ret<<endl;
 } 
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		//a为b的父节点 
		edge[a].push_back(b);
		fa[b]=a; 
	}
	//深度
	cout<<dfs(1)<<endl; 
	//宽度
	bfs();
	//求距离
	int x,y;//向根边为向上走（乘以2），向叶边为向下走 
	cin>>x>>y; 
	//向上走并标记到x距离
	while(fa[x])//x向上走，当为1的时候无父，为空结束 
	{
		dist[fa[x]]=dist[x]+1;
		x=fa[x]; 
		
	 } 
	 //y向上走
	 int ret=0;
	 while(fa[y]&&dist[y]==0) 
	 {
	 	ret++;
	 	y=fa[y];
	 }
	 cout<<dist[y]*2+ret<<endl;
	return 0;
 } 


////P1827 [USACO3.4] 美国血统 American Heritage
//#include<iostream>
//#include<string>
//using namespace std;
//string a,b;
////将树拆分，前序第一个为根节点，分为左右两个节点
//void dfs(int l1,int r1,int l2,int r2)//l1 r1为该树中序，l2，r2为前序 
//{
//	//递归出口为叶子节点，左右为空即区间不合法
//	while(l1>r1) return;
//	//输出后序遍历，先处理左再右边最后输出根
//	//找到中序中的根节点
//	int p=l1;
//	while(a[p]!=b[l2])p++;
//	//左子树
//	dfs(l1,p-1,l2+1,l2+p-l1);
//	//右子树
//	dfs(p+1,r1,l2+p-l1+1,r2);
//	//输出根
//	cout<<b[l2]; 
// } 
//
//
//int main()
//{
//	cin>>a>>b;
//	dfs(0,a.size()-1,0,b.size()-1);
//	return 0;
// } 
//


////P1030 [NOIP 2001 普及组] 求先序排列
//#include<iostream>
//#include<string>
//
//using namespace std;
//string a,b;
//void dfs(int l1,int r1,int l2,int r2)
//{
//	//函数出口:当区间不合法，p会向l1逼近即r1<l1结束 r2会向l2逼近
//	//越过对方，说明此时左子树为空，或者右子树为空，即该递归返回 
//	//while(l2>r2) return; 
//	while(r1<l1) return;
//	cout<<b[r2];//后序排列最后一个为根节点
//	//根据根节点在中序排列中分为左子树与右子树
//	//左子树
//	int p=l1;
//	while(a[p]!=b[r2])p++;//p位于根节点 
//	dfs(l1,p-1,l2,l2+p-l1-1);
//	//右子树
//	dfs(p+1,r1,l2+p-l1,r2-1); 
//}
//int main()
//{
//	cin>>a>>b;
//	dfs(0,a.size()-1,0,b.size()-1);
//	
//	return 0;
//}


////P4913 【深基16.例3】二叉树深度
//#include<iostream>
//#include<algorithm>
//using namespace std;
//const int N=1e6+10;
//int l[N],r[N];
//int deep(int root)
//{
//	if(!root)return 0;//叶子节点的孩子为零，高度为1
//	return 1+max(deep(l[root]),deep(r[root]) );
//}
//int main()
//{
//	int n;cin>>n;
//	//存树
//	for(int i=1;i<=n;i++)
//	{
//		cin>>l[i]>>r[i];
//	 } 
//	 //深度=1+max（左子树高度，右子树高度）
//	cout<<deep(1); 
//	 //特殊二叉树可运用性质i/2找到父 
////	 int cnt=0;
////	 while(n)
////	 {
////	 	n/=2;
////	 	cnt++;
////	 }
////	 cout<<cnt;
//	return 0;
//}


////B3642 二叉树的遍历
//#include<iostream>
//
//using namespace std;
//const int N=1e6+10;
//int l[N],r[N];
//void dfs1(int x)
//{
//	if(x==0)return;
//	cout<<x<<' ';
//	dfs1(l[x]);dfs1(r[x]);
//}
//void dfs2(int x)
//{
//	if(x==0)return;
//	dfs2(l[x]);
//	cout<<x<<' ';
//	dfs2(r[x]);
//}
//void dfs3(int x)
//{
//	if(x==0)return;
//	dfs3(l[x]);
//	dfs3(r[x]);
//	cout<<x<<' '; 
//}
//int main()
//{
//	int n;
//	cin>>n;
//	for(int i=1;i<=n;i++)
//	{
//		cin>>l[i]>>r[i];
//	}
//	//前序
//	dfs1(1);
//	cout<<endl;
//	//中序
//	dfs2(1);
//	cout<<endl;
//	//后序
//	dfs3(1);
//	cout<<endl; 
//	
//	return 0;
// } 


//P1305 新二叉树
//#include<iostream>
//#include<string>
//using namespace std;
//
//string l,r;
//char root;
//void dfs(char root)
//{
//	if(root=='*')return;
//	cout<<root;
////	if(l[root]!='*')
//	dfs(l[root]);
////	if(r[root]!='*')
//	dfs(r[root]);
//}
//int main()
//{
//	int n;
//	cin>>n;
//	cin>>root;//存储根节点，用对应字母的ASCII值找到左右孩子 
//	cin>>l[root]>>r[root];
//	for(int i=2;i<=n;i++)
//	{
//		char a;cin>>a;//必定是已经存储子树的根节点 
//		cin>>l[a]>>r[a];
//	}
//	dfs(root);
//}
