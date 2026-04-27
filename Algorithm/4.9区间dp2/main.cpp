//P3146 [USACO16OPEN] 248 G
#include <iostream>

using namespace std;
const int N=255;
int f[N][N];//f[i][j],i->j区间内能合成至一个的最大数
int a[N]; 
int main()
{
	int n;cin>>n;
	int ret=0; 
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[i][i]=a[i];//初始化，不能合成 
		ret=max(ret,a[i]);
	}
	for(int len=2;len<=n;len++)
	{
		for(int i=1;i+len-1<=n;i++)
		{
			int j=i+len-1;
			for(int k=1;k<j;k++)
			{
				if(f[i][k]&&f[i][k]==f[k+1][j])//f[i][k]不为零，说明该区间有多个，可以合成
				f[i][j]=max(f[i][j],f[i][k]+1);
				ret=max(ret,f[i][j]); 
			}
		}
	}
	cout<<ret;
	return 0;
}

////P1880 [NOI1995] 石子合并
//#include <iostream>
//#include <cstring>
//using namespace std;
//const int N=110;
//int a[N*2];
//int sum[N*2];//前缀和
//int f[N*2][N*2];
//int g[N*2][N*2]; 
//int main()
//{
//	int n;cin>>n;
//	for(int i=1;i<=n;i++)
//	{
//		cin>>a[i];
//		a[i+n]=a[i];
//		
//	}
//	//前缀和
//	for(int i=1;i<=2*n;i++) 
//	{
//		sum[i]=sum[i-1]+a[i]; 
//	}
//	//最小
//	//初始化
//
//	//枚举起始位置
//	
//
//		memset(f,0x3f3f3f3f,sizeof f);
//		//长度为1时； 
//		for(int i=1;i<=2*n;i++)f[i][i]=0;
//		
//		for(int len=1;len<=n;len++)
//		{
//			for(int i=1;i+len-1<=2*n;i++)
//			{
//				int j=i+len-1;
//				for(int k=i;k<j;k++)
//				{
//					f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+sum[j]-sum[i-1]);
//					g[i][j]=max(g[i][j],g[i][k]+g[k+1][j]+sum[j]-sum[i-1]);
//				}
//			}
//		}
//	  
//	 int mn=0x3f3f3f3f,mx=0;
//	 for(int i=1;i<=n;i++)
//	 {
//	 	mn=min(mn,f[i][i+n-1]);
//		 mx=max(mx,g[i][i+n-1]); 
//	 }
//	 cout<<mn<<endl<<mx;
//	return 0;
//}

////P1775 石子合并（弱化版）
//#include <iostream>
//#include <cstring>
//using namespace std;
//const int N=1e3+10;
//int f[N][N];
//int a[N];
//int sum[N];//前缀和 
//int main()
//{
//	int n;cin>>n;
//	for(int i=1;i<=n;i++)
//	{
//		cin>>a[i];
//		sum[i]=sum[i-1]+a[i];
//		
//	 } 
//	 //初始化
//	 memset(f,0x3f3f3f3f,sizeof f);
//	 for(int i=1;i<=n;i++)f[i][i]=0;//长度为1时不需要合并
//	 for(int len=2;len<=n;len++)
//	 {
//	 	for(int i=1;i+len-1<=n;i++)
//	 	{
//	 		int j=i+len-1;
//	 		for(int k=i;k<j;k++)//枚举断点 
//	 		{
//	 			f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+sum[j]-sum[i-1]); 
//			 }
//		 }
//	  } 
//	cout<<f[1][n]; 
//	return 0;
//}


////P2858 [USACO06FEB] Treats for the Cows G/S
//
//#include <iostream>
//
//using namespace std;
//const int N=2e3+10;
//int f[N][N];
//int a[N];
//int n;
//int main()
//{
//	cin>>n;
//	for(int i=1;i<=n;i++)
//	{
//		cin>>a[i];
//	}
//	for(int len=1;len<=n;len++)
//	{
//		for(int i=1;i+len-1<=n;i++)
//		{
//			int j=i+len-1;
//			int d=n-len+1;
//			f[i][j]=max(f[i+1][j]+d*a[i],f[i][j-1]+d*a[j]);
//			
//		}
//	}
//	cout<<f[1][n]<<endl;
//	return 0;
// } 
