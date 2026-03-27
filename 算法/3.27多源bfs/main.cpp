//P1902 刺杀大使
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int N=1020;
int a[N][N];
int n,m;
bool st[N][N];
typedef pair<int,int>PII;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0}; 
bool cheack(int mid)
{
	memset(st,0,sizeof st);//重置，标记数组 
	
	queue<PII>q;
	for(int i=1;i<=m;i++)
	{
		q.push({1,i});
		st[1][i]=1;
	}
	while(q.size())
	{
		auto t=q.front();q.pop();
		int i=t.first,j=t.second;
		if(i==n)return 1;//到达出口，找到 
		for(int k=0;k<4;k++)
		{
			int x=i+dx[k],y=j+dy[k];
			if(x<=n&&x>0&&y>0&&y<=m&&!st[x][y])
			{
				if(a[x][y]>mid)continue; 
				q.push({x,y});
				st[x][y]=1;
			}
		
		}
	 } 
	 return false; 
}
int main()
{
	//二分结果
	 
	cin>>n>>m;
	int l=0,r=0; 
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			r=max(r,a[i][j]);
		}
	}
	while(l<r)
	{
		int mid=(l+r)/2;
		if(cheack(mid))//最大伤害是mid能不能通过 
		r=mid;
		else l=mid+1;//不能通过，说明mid在右端； 
		 
	}
	cout<<l;
	return 0;
}


////矩阵距离
//#include <iostream>
//#include <queue>
//#include <cstring>
//using namespace std;
//int n,m;
//char a[1100][1100];
//int disc[1100][1100];
//typedef pair<int,int>PII;
//int dx[]={0,0,1,-1};
//int dy[]={1,-1,0,0};
//void bfs()
//{
//	memset(disc,-1,sizeof disc);
//	queue<PII>q;
//	//多源bfs，超级源点，最先修改disc即为最近起始到此处 
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		if(a[i][j]=='1')
//		q.push({i,j}),disc[i][j]=0;
//	}
//	while(q.size())
//	{
//		auto t=q.front();q.pop();
//		int i=t.first,j=t.second;
//		for(int k=0;k<4;k++)
//		{
//			int x=i+dx[k],y=j+dy[k];
//			if(x>0&&x<=n&&y>0&&y<=m&&disc[x][y]==-1)
//			{
//				disc[x][y]=disc[i][j]+1;
//				q.push({x,y});
//			}
//		 } 
//	}
//}
//int main()
//{
//	cin>>n>>m;
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		cin>>a[i][j];
//	}
//	bfs();
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		cout<<disc[i][j]<<' ';
//		cout<<endl;
//	}
//	return 0;
// } 
