//「木」迷雾森林
#include <iostream>
#include <cstdio>
using namespace std;
const int N=3100;
int f[N][N];//dp表
int a[N][N];
int n,m;
const int mod=2333; 
template<class T>inline void read(T &res)
{
char c;T flag=1;
while((c=getchar())<'0'||c>'9')if(c=='-')flag=-1;res=c-'0';
while((c=getchar())>='0'&&c<='9')res=res*10+c-'0';res*=flag;
}
int main()
{
	
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		scanf("%d",&a[i][j]);
	//	read(a[i][j]);
	}
	//初始化
	f[n+1][1]=1;
	for(int i=n;i>0;i--)
	{
		 
		for(int j=1;j<=m;j++)
		{
		if(a[i][j]==0)
			f[i][j]=(f[i+1][j]+f[i][j-1])%mod;
		}
	 } 
	cout<<f[1][m];
	return 0;
}


////DP11 矩阵的最小路径和
//#include<iostream>
//#include<cstring>
//using namespace std;
//const int N=510;
//int f[N][N];//dp表 
//int main()
//{
//	int n,m;cin>>n>>m;
//	//初始化
//	memset(f,0x3f3f3f3f,sizeof f);
//	f[0][1]=0; 
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		{
//			int x;cin>>x;
//			f[i][j]=min(f[i-1][j],f[i][j-1])+x;
//		}
//	 } 
//	cout<<f[n][m];
//	return 0;
//}


////P1541 [NOIP 2010 提高组] 乌龟棋
//
//#include <iostream>
//
//using namespace std;
//const int N=50;
//int f[N][N][N][N];//dp数组，P1541，f[a][b][c][d]
//					//使用a张1到达.....的最大值
//int x[450];
//int cnt[N];//统计每张牌数量 
//int main()
//{
//	int n,m;cin>>n>>m;
//	for(int i=1;i<=n;i++)
//	cin>>x[i];
//	for(int i=1;i<=m;i++)
//	{
//		int x;cin>>x;
//		cnt[x]++;
//		
//	 } 
//	//初始
//	f[0][0][0][0]=x[1];
//	for(int a=0;a<=cnt[1];a++)
//		for(int b=0;b<=cnt[2];b++)
//			for(int c=0;c<=cnt[3];c++)
//				for(int d=0;d<=cnt[4];d++)
//				{
//					int i=1+a+2*b+3*c+4*d;//初始位置为1 
//					int& t=f[a][b][c][d];
//					if(a)t=max(t,f[a-1][b][c][d]+x[i]);
//					if(b)t=max(t,f[a][b-1][c][d]+x[i]);
//					if(c)t=max(t,f[a][b][c-1][d]+x[i]);
//					if(d)t=max(t,f[a][b][c][d-1]+x[i]);
//				}
//	cout<<f[cnt[1]][cnt[2]][cnt[3]][cnt[4]];
//	return 0;
// } 

