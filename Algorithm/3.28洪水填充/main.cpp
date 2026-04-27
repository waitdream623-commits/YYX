//P1162 填涂颜色
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<queue>

using namespace std;
typedef pair<int,int>PII;
const int N=40;
int n;
bool st[N][N];
int a[N][N];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
void bfs()
{
	queue<PII>q;
	q.push({0,0});
	st[0][0]=1;
	while(q.size())
	{
      
		auto t=q.front();q.pop();
		int i=t.first,j=t.second;
		for(int k=0;k<4;k++)
		{
			//在周围加上一圈0 
			int x=i+dx[k],y=j+dy[k];
			if(x>=0&&x<=n+1&&y>=0&&y<=n+1&&!st[x][y]&&!a[x][y])
			{
				st[x][y]=1;
				q.push({x,y});
			}
		}
	}
}
int main()
{
	while(cin>>n)
	{
          //每次需要重置标记
       memset(st,0,sizeof st);
		for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		cin>>a[i][j]; 
	}
	//将外围0，即没有1包围，标记
	bfs(); 
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(st[i][j]||a[i][j])cout<<a[i][j]<<' ';
			else cout<<2<<' ';
		}
		cout<<endl;
	}
	}
	
	return 0;
}

////P1596 [USACO10OCT] Lake Counting S
//
//#include <iostream>
//
//using namespace std;
//const int N=110;
//char a[N][N];
//int n,m;
//bool st[N][N];
//int dx[]={0,0,1,-1,1,1,-1,-1};
//int dy[]={1,-1,0,0,1,-1,-1,1};
//void dfs(int i,int j)
//{
//	st[i][j]=1; 
//	for(int k=0;k<8;k++)
//	{
//		int x=i+dx[k],y=j+dy[k];
//		if(x>0&&x<=n&&y>0&&y<=m&&!st[x][y]&&a[x][y]=='W')
//		{
//			dfs(x,y);
//		}
//	 } 
//}
//int main()
//{
//	int ret=0;
//	cin>>n>>m;
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		{
//			cin>>a[i][j];
//		}
//	}
//	//遍历每一个w，搜索附近w标记
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		{
//			if(a[i][j]=='W'&&!st[i][j])
//			{
//				dfs(i,j);
//				ret++;
//			}
//		}
//	 } 
//	cout<<ret;
//	return 0;
// } 
