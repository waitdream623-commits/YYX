//kotori和迷宫
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int N=40;
typedef pair<int,int>PII; 
char a[N][N];
int disc[N][N];//存储距离；
 int n,m,x,y; 
 int dx[]={0,0,1,-1};
 int dy[]={1,-1,0,0};
 int cnt=0,ret=10000;
 void bfs()
 {
 	memset(disc,-1,sizeof disc);
 	queue<PII>q;
 	q.push({x,y});
 	disc[x][y]=0;
 	
 	while(q.size())
 	{
 		auto e=q.front();q.pop();
 		int i=e.first,j=e.second;
 		for(int k=0;k<4;k++)
 		{
 			int x=i+dx[k],y=j+dy[k];
 			if(x<1||x>n||y<1||y>m)continue;
 			if(a[x][y]=='*')continue;
 			if(disc[x][y]!=-1)continue;
 			disc[x][y]=disc[i][j]+1;
 			if(a[x][y]=='e'){
 				cnt++;
 				ret=min(disc[x][y],ret);
 				continue;//不能加入队列 
			 }
			 q.push({x,y});
		 }
	 }
 }
int main()
{
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			if(a[i][j]=='k')
			{
				x=i,y=j;//找到起始位置 
			}
		}
	}
	bfs();
	if(cnt==0)cout<<-1;
	else 
	cout<<cnt<<' '<<ret;
	
	return 0;
}
