//CF590C Three States
#include<iostream>
#include <deque>
#include <cstring>
using namespace std;
//多源bfs+01bfs；
const int N=1100;
char a[N][N];
int disc[4][N][N];
int n,m;
//方向向量
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
 
void bfs(int num)
{
	memset(disc[num],-1,sizeof disc[num]);
	deque<pair<int,int>>q;
	//多源，每个城市到每个格子最短
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]-'0'==num)
			q.push_back({i,j}),disc[num][i][j]=0;
		}
	 } 
	 while(q.size())
	 {
	 	auto t=q.front();q.pop_front();
	 	int i=t.first,j=t.second;
	 	for(int k=0;k<4;k++)
	 	{
	 		int x=i+dx[k],y=j+dy[k];
	 		if(x<=n&&x>0&&y>0&&y<=m&&a[x][y]!='#')
	 		{
	 			int w=a[x][y]=='.'?1:0;
	 			if(disc[num][x][y]==-1)
	 			{
	 				if(w)
					 q.push_back({x,y});
					else
					q.push_front({x,y});
					
					disc[num][x][y]=disc[num][i][j]+w; 
				 }
				 //松弛操作
				 else if(disc[num][i][j]+w<disc[num][x][y])
				 {
				 	//已经存在 不用push 
				 	disc[num][x][y]=disc[num][i][j]+w;
				  } 
			 }
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
		}
	}
	bfs(1);bfs(2);bfs(3);
	int ret=0x3f3f3f3f;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int d=disc[1][i][j],b=disc[2][i][j],c=disc[3][i][j];
		//无法通过 
			if(d==-1||b==-1||c==-1)continue;
			if(a[i][j]=='.')ret=min(ret,d+b+c-2);
			else ret=min(ret,d+b+c);
			
		}
	}
	if(ret==0x3f3f3f3f)cout<<-1<<endl;
	else cout<<ret<<endl;
	return 0;
 } 


////P4554 小明的游戏
//
//#include <iostream>
//#include <deque>
//#include <cstring>
//
//using namespace std;
//int n,m;
//const int N=510;
//char a[N][N];
//int c,b,x,y;
//int disc[N][N];
////方向向量
//int dx[]={0,0,1,-1};
//int dy[]={1,-1,0,0}; 
//void bfs()
//{
//	memset(disc,-1,sizeof disc);
//	deque<pair<int,int>>q;
//	q.push_back({c,b});
//	disc[c][b]=0; 
//	while(q.size())
//	{
//		auto t=q.front();q.pop_front();
//		int i=t.first,j=t.second;
//		//此时成为队头
//		 if(i==x&&j==y)return; 
//		for(int k=0;k<4;k++)
//		{
//			int s=i+dx[k],d=j+dy[k];
//			if(s>=0&&s<n&&d>=0&&d<m)
//			{
//				int w=0;//权重 
//					if(a[i][j]==a[s][d])
//				{
//					w=0;
//				}
//				else
//				 {
//				 	w=1;
//				 }
//				 if(disc[s][d]==-1)
//				 {
//				 	disc[s][d]=disc[i][j]+w;
//				 	if(w)q.push_back({s,d});//看成源点 
//				 	else q.push_front({s,d});
//				  } 
//				//松弛操作 ， 更优秀 
//				else if(disc[i][j]+w<disc[s][d])
//				{
//					disc[s][d]=disc[i][j]+w;
//				 } 
////			 if(s==x&&d==y)return;可能不是最优 
//			}
//		}
//	}
//}
//int main()
//{
//	while(cin>>n>>m&&n&&m)
//	{
//		//坐标从o，o开始 
//		for(int i=0;i<n;i++)
//		{
//			for(int j=0;j<m;j++)
//			{
//				cin>>a[i][j];
//			}
//		}
//		cin>>c>>b>>x>>y;
//		bfs();
//		cout<<disc[x][y]<<endl;
//	}	
//	
//	return 0;
//}
