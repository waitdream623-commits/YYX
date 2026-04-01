////P1004 [NOIP 2000 提高组] 方格取数
//#include <iostream>
//
//using namespace std;
//
//int f[20][20][20][20];//同时处理第一次和第二次，处理相同位置 
//int a[20][20];
//int main()
//{
//	int n;cin>>n;
//	int x,y,m;
//	while(cin>>x>>y>>m,x&&y&&m)
//	{
//		a[x][y]=m;
//	}
//	//初始化
//	
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			for(int c=1;c<=n;c++)
//			{
//				for(int b=1;b<=n;b++)
//				{
//					f[i][j][c][b]=max(max(f[i-1][j][c-1][b],f[i-1][j][c][b-1]),max(f[i][j-1][c-1][b],f[i][j-1][c][b-1]))
//					+a[i][j]+a[c][b]-a[i][j]*(i==c&&j==b);
//				}
//			 } 
//			
//		}
//	 } 
//	 cout<<f[n][n][n][n];
//	return 0;
//	
// } 


////P1002 [NOIP 2002 普及组] 过河卒
//
//#include<iostream>
//#include<cstring>
//using namespace std;
//const int N=30;
//long long f[N][N];//开long long 
//int a[N][N];//标记不可通过点
//int dx[]={1,2,2,1,-1,-2,-2,-1};
//int dy[]={2,1,-1,-2,-2,-1,1,2};
//int main()
//{
//	int n,m,x,y;cin>>n>>m>>x>>y;
//	//标记不可通过位置
//	x++;y++;n++;m++;
//	a[x][y]=1;
//	for(int k=0;k<8;k++)
//	{
//		int i=x+dx[k],j=y+dy[k];
//		if(x>0&&x<=n&&y>0&&y<=m)
//		{
//			a[i][j]=1;
//		}
//	 } 
//	//初始化
//	//memset(f,0x3f3f3f3f,sizeof f);
//	f[0][1]=1;
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		{
//			if(a[i][j]==0)
//			{
//				f[i][j]=f[i][j-1]+f[i-1][j];
//			}
//		}
//	}
//	cout<<f[n][m];
//	return 0;
//}
