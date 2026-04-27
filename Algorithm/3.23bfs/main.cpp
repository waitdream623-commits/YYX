//P1443 马的遍历
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int disc[410][410];
int n,m,x,y;
typedef pair<int,int>PII;
int dx[]={2,1,-1,-2,-2,-1,1,2};
int dy[]={1,2,2,1,-1,-2,-2,-1};
void bfs()
{
	memset(disc,-1,sizeof disc);//不能到达为-1 
	queue<PII>q;
	q.push({x,y});
	disc[x][y]=0;//最初 
	while(q.size())
	{
		auto e=q.front();q.pop();
		int i=e.first,j=e.second;
		for(int k=0;k<8;k++)
		{
			int x=i+dx[k],y=j+dy[k];
			if(disc[x][y]!=-1)continue;//已经到达过
			if(x<1||x>n||y<1||y>m)continue;//越界
			q.push({x,y});
			disc[x][y]=disc[i][j]+1; //从上点到这点 距离加一，即为权值 
		 } 
	}
}
int main()
{
	cin>>n>>m>>x>>y;
	bfs();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		cout<<disc[i][j]<<' ';
		cout<<endl;
	}
	
	return 0;
}
