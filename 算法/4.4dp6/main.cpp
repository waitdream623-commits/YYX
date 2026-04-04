//P2946 [USACO09MAR] Cow Frisbee Team S
#include <iostream>

using namespace std;
int f[2010][1010];
int a[2010];
const int N=1e8; 
int main()
{
	int n,F;cin>>n>>F;
	for(int i=1;i<=n;i++)cin>>a[i];
	f[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<F;j++)
		{
			//
			f[i][j]=(f[i-1][j]+f[i-1][((j-a[i]%F)%F+F)%F])%N;//补正 
			
		}
	}
	cout<<f[n][0]-1;//减去f[0][0]; 
	return 0;
}


////P1164 小 A 点菜
////将表填满，找合法f[i][m] 
//#include <iostream>
//#include <cstring>
//using namespace std;
//const int N=1100;
//int a[N];
//int f[N][N];//方案总数 j为钱
//
//int main()
//{
//	int n,m;cin>>n>>m;
//	for(int i=1;i<=n;i++)cin>>a[i];
//	//初始化
//	
//	f[0][0]=1;
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=0;j<=m;j++)//从0开始填
//		{
//			//不选i的方案数 
//			f[i][j]=f[i-1][j];
//			//选i 
//			if(j>=a[i])f[i][j]=f[i][j]+f[i-1][j-a[i]];
//		}
//	 } 
//	 
//	 cout<<f[n][m];
//	return 0;
//}

////P1048 [NOIP 2005 普及组] 采药
//#include <iostream>
//
//using namespace std;
//const int N=1100;
//int t[N],v[N];
//int f[N][N];
//int main()
//{
//	int m,n;cin>>m>>n;
//	for(int i=1;i<=n;i++)cin>>t[i]>>v[i];
//	
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		{
//			f[i][j]=f[i-1][j];
//			if(j>=t[i])f[i][j]=max(f[i][j],f[i-1][j-t[i]]+v[i]);
//			
//		}
//	 } 
//	cout<<f[n][m];
//	return 0;
// } 


////【模板】01背包
////空间优化 
//#include <iostream>
//#include <cstring>
//using namespace std;
//const int N=1e3+10;
//int w[N],v[N];//w为重量，v为价值 
//int f[N];//f[i][j]表示1到i件物品，空间为j 时的价值 
// 
//int main()
//{
//	int n,m;cin>>n>>m;
//	for(int i=1;i<=n;i++)cin>>w[i]>>v[i];
//	
//	//问题一
//	//初始化，当i为0即无物品，价值为0；
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=m;j>=w[i];j--)
//		{
//			f[j]=f[j];
//			f[j]=max(f[j],f[j-w[i]]+v[i]);
//		}
//		}	
//	cout<<f[m]<<endl;
//	//问题二  答案在f[n][m],位置合法就输出，否则无法放入 
//	//初始化，当空间为 0，f[0][0]为0，其他位置为非法
//	int inf=0x3f3f3f3f;
//	memset(f,-inf,sizeof f);
//	f[0]=0;
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=m;j>=w[i];j--)
//		{
//			f[j]=f[j];
//			f[j]=max(f[j],f[j-w[i]]+v[i]);
//		}
//	}
//	if(f[m]>=0)
//	cout<<f[m]<<endl;
//	else
//	cout<<0<<endl; 
//	return 0;
//}
//#include <iostream>
//#include <cstring>
//using namespace std;
//const int N=1e3+10;
//int w[N],v[N];//w为重量，v为价值 
//int f[N][N];//f[i][j]表示1到i件物品，空间为j 时的价值 
// 
//int main()
//{
//	int n,m;cin>>n>>m;
//	for(int i=1;i<=n;i++)cin>>w[i]>>v[i];
//	
//	//问题一
//	//初始化，当i为0即无物品，价值为0；
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		{
//			f[i][j]=f[i-1][j];
//			if(j>=w[i])f[i][j]=max(f[i][j],f[i-1][j-w[i]]+v[i]);
//		}
//		}	
//	cout<<f[n][m]<<endl;
//	//问题二  答案在f[n][m],位置合法就输出，否则无法放入 
//	//初始化，当空间为 0，f[0][0]为0，其他位置为非法
//	int inf=0x3f3f3f3f;
//	memset(f[0],-inf,sizeof f[0]);
//  f[0][0]=0;
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		{
//			f[i][j]=f[i-1][j];
//			if(j>=w[i])f[i][j]=max(f[i][j],f[i-1][j-w[i]]+v[i]);
//		}
//	}
//	if(f[n][m]>0)
//	cout<<f[n][m]<<endl;
//	else
//	cout<<0<<endl; 
//	return 0;
//}
