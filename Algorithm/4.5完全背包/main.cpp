//P5662 [CSP-J 2019] 纪念品
#include <iostream>
#include <cstring>
using namespace std;
int t,n,m;
const int N=1e4+10;
int f[N];
int a[110][110];
 
int main()
{
	cin>>t>>n>>m;
	for(int i=1;i<=t;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			}	
	}
	for(int i=1;i<t;i++)//每天 
	{
		//完全背包 
		memset(f,0,sizeof f);
		for(int ii=1;ii<=n;ii++)//每个纪念币 
		{
			for(int j=a[i][ii];j<=m;j++)//枚举最大前 
			{
				f[j]=max(f[j],f[j-a[i][ii]]+a[i+1][ii]-a[i][ii]);
			}
		}
		m+=f[m]; 
	}
	cout<<m;
	return 0;
 } 



////P2918 [USACO08NOV] Buying Hay S
////P2918 [USACO08NOV] Buying Hay S
//#include <iostream>
//#include <cstring> 
//using namespace std;
//int f[100000];
//int p[5010],c[5010];
//int main()
//{
//	int n,m;cin>>n>>m;
//	for(int i=1;i<=n;i++)cin>>p[i]>>c[i];
//	int ret=0x3f3f3f3f;
//	memset(f,0x3f3f3f,sizeof f);
//	f[0]=0;
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=p[i];j<=m;j++)
//		f[j]=min(f[j],f[max(0,j-p[i])]+c[i]);
//	}
//
//
//	
//	cout<<f[m];
//	return 0;
// } 
 
//#include <iostream>
//#include <cstring> 
//using namespace std;
//int f[100000];
//int p[5010],c[5010];
//int main()
//{
//	int n,m;cin>>n>>m;
//	for(int i=1;i<=n;i++)cin>>p[i]>>c[i];
//	int ret=0x3f3f3f3f;
//	memset(f,0x3f3f3f,sizeof f);
//	f[0]=0;
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=p[i];j<=m+50000;j++)
//		f[j]=min(f[j],f[j-p[i]]+c[i]);
//	}
//
//
//	for(int i=m;i<=m+50000;i++)
//	{
//		ret=min(f[i],ret);
//	}
//	cout<<ret;
//	return 0;
// } 

////P1616 疯狂的采药
//#include <iostream>
//using namespace std;
//const int N=1e7+10;
//long long f[N];//数据量
//int t[100010],v[100010];
//int main()
//{
//	int n,m;cin>>m>>n;
//	for(int i=1;i<=n;i++)cin>>t[i]>>v[i];
//	
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=t[i];j<=m;j++)
//		f[j]=max(f[j],f[j-t[i]]+v[i]);
//	}
//	cout<<f[m];
//	return 0;
// } 
////【模板】完全背包
////空间优化 
//#include <iostream>
//#include <cstring>
//using namespace std;
//int f[1100];//前i个物体，体积为j的最大值 
//int v[1100],w[1100];
// 
//int main()
//{
//	int n,m;cin>>n>>m;
//	for(int i=1;i<=n;i++)
//	{
//		cin>>v[i]>>w[i];	
//		}
//	//第一问
//	//初始化
//	
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=v[i];j<=m;j++)
//		{
//		
//			f[j]=max(f[j],f[j-v[i]]+w[i]);
//		}
//	 } 
//	cout<<f[m]<<endl;
//	//第二问，装满 
//	memset(f,-0x3f3f,sizeof f);
//	f[0]=0; 
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=v[i];j<=m;j++)
//		{
//			
//			f[j]=max(f[j],f[j-v[i]]+w[i]);
//		}
//	 } 
//	 if(f[m]>0)
//	 cout<<f[m]<<endl;
//	 else 
//	 cout<<0<<endl;
//	 
//	return 0;
// } 
//#include <iostream>
//#include <cstring>
//using namespace std;
//int f[1100][1100];//前i个物体，体积为j的最大值 
//int v[1100],w[1100];
// 
//int main()
//{
//	int n,m;cin>>n>>m;
//	for(int i=1;i<=n;i++)
//	{
//		cin>>v[i]>>w[i];	
//		}
//	//第一问
//	//初始化
//	
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		{
//			f[i][j]=f[i-1][j];
//			if(j>=v[i])
//			f[i][j]=max(f[i-1][j],f[i][j-v[i]]+w[i]);
//		}
//	 } 
//	cout<<f[n][m]<<endl;
//	//第二问，装满 
//	memset(f,-0x3f3f,sizeof f);
//	f[0][0]=0; 
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=0;j<=m;j++)//从零开始 
//		{
//			f[i][j]=f[i-1][j];
//			if(j>=v[i])
//			f[i][j]=max(f[i-1][j],f[i][j-v[i]]+w[i]);
//		}
//	 } 
//	 if(f[n][m]>0)
//	 cout<<f[n][m]<<endl;
//	 else 
//	 cout<<0<<endl;
//	 
//	return 0;
// } 
