//P1077 [NOIP 2012 普及组] 摆花
//空间优化 
#include <iostream>

using namespace std;
const int mod=1e6+7;
const int N=110;
long long f[N];
int a[N];
int main()
{
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	
	f[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>0;j--)
		{
			for(int k=1;k<=min(j,a[i]);k++)
			f[j]=(f[j]+f[j-k])%mod;
		}
	}
	cout<<f[m]%mod;
	return 0;
 } 

//#include <iostream>
//
//using namespace std;
//const int mod=1e6+7;
//const int N=110;
//long long f[N][N];
//int a[N];
//int main()
//{
//	int n,m;cin>>n>>m;
//	for(int i=1;i<=n;i++)cin>>a[i];
//	
//	f[0][0]=1;
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=0;j<=m;j++)
//		{
//			for(int k=0;k<=min(j,a[i]);k++)
//			f[i][j]=(f[i][j]+f[i-1][j-k])%mod;
//		}
//	}
//	cout<<f[n][m]%mod;
//	return 0;
// } 

////多重背包
//#include <iostream>
//
//using namespace std;
//const int N=110;
//int c[N],w[N],v[N];
//int f[N][N];
//int n,m; 
//int main()
//{
//	cin>>n>>m;
//	for(int i=1;i<=n;i++)cin>>c[i]>>w[i]>>v[i];
//	
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		{
//			for(int jj=0;jj<=c[i];jj++)
//			{
//				if(j>=jj*w[i]) 
//				f[i][j]=max(f[i][j],f[i-1][j-jj*w[i]]+jj*v[i]);
//			}
//		}
//	}
//	cout<<f[n][m]<<endl; 
//	return 0; 
// } 
