//P3397 地毯
#include <iostream>

using namespace std;
const int N=1e3+10;
int f[N][N];

int main()
{
	int n,m;cin>>n>>m;
	while(m--)
	{
		int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
		f[x1][y1]++;
		f[x1][y2+1]--;
		f[x2+1][y1]--;
		f[x2+1][y2+1]++;
	}
	//输出
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			f[i][j]=f[i][j]+f[i-1][j]+f[i][j-1]-f[i-1][j-1];
			cout<<f[i][j]<<' ';
		}
		puts("");
	 } 
	return 0;
}

////【模板】二维差分
//#include <iostream>
//
//using namespace std;
//const int N=1e3+10;
//typedef long long LL;
//
//LL f[N][N];
//int main()
//{
//	int n,m,q;cin>>n>>m>>q;
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		{
//			int x;cin>>x;
//			//差分存储 
//			f[i][j]+=x;
//			f[i][j+1]-=x;
//			f[i+1][j]-=x; 
//			f[i+1][j+1]+=x;
//		}
//	}
//	//操作
//	while(q--)
//	{
//		int x1,y1,x2,y2,k;cin>>x1>>y1>>x2>>y2>>k;
//		f[x1][y1]+=k;
//		f[x1][y2+1]-=k;
//		f[x2+1][y1]-=k; 
//		f[x2+1][y2+1]+=k;
//	 } 
//	 //还原
//	 for(int i=1;i<=n;i++)
//	 {
//	 	for(int j=1;j<=m;j++)
//	 	{
//	 		f[i][j]=f[i][j]+f[i-1][j]+f[i][j-1]-f[i-1][j-1];
//	 		cout<<f[i][j]<<' ';
//		 }
//		 puts("");
//	  } 
//	return 0;
// } 
