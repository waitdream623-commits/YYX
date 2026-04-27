//P2280 [HNOI2003] 激光炸弹
#include<iostream>

using namespace std;
const int N=1e4;
int a[N][N];
int f[N][N];//存储前缀和 
int main()
{
	int n,m;cin>>n>>m;
	while(n--)
	{
		int x,y,v;cin>>x>>y>>v;
		x++;y++;//从1开始存储 
		a[x][y]+=v;//可能重复位置 
	}
	//前缀和存储
	int s=5001;
	for(int i=1;i<=s;i++)
	{
		for(int j=1;j<=s;j++)
		{
			f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1]+a[i][j];
		}
	 } 
	 //暴力枚举m*m范围，找到最大；
	 int ret=0; 
	 for(int x2=m;x2<=s;x2++)
	 {
	 	for(int y2=m;y2<=s;y2++)
	 	{
	 		int x1=x2-m+1,y1=y2-m+1;
	 		int sum=f[x2][y2]-f[x1-1][y2]-f[x2][y1-1]+f[x1-1][y1-1];
	 		ret=max(sum,ret);
		 }
	  } 
	  cout<<ret;
	return 0;
}

////【模板】二维前缀和
//#include <iostream>
//
//using namespace std;
//const int N=1e3+10;
//long long  a[N][N];
//int main()
//{
//	int n,m,q;cin>>n>>m>>q;
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		{
//			int x;cin>>x;
//			a[i][j]=a[i][j-1]+x+a[i-1][j]-a[i-1][j-1];
//		}
//      
//	}
//	while(q--)
//	{
//		int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
//		long long sum=0;
//		sum=a[x2][y2]-a[x1-1][y2]-a[x2][y1-1]+a[x1-1][y1-1];
//		cout<<sum<<endl;
//	}
//}

////P1115 最大子段和
//#include <iostream>
//
//using namespace std;
//const int N=1e6;
//
//int a[N];
//int main()
//{
//	int n;cin>>n;
//	for(int i=1;i<=n;i++)
//	{
//		int t;cin>>t;
//		a[i]=a[i-1]+t;
//	}
//	int mn=0,mx=a[1];
//	for(int i=1;i<=n;i++)
//	{
//	
//		mx=max(mx,a[i]-mn); 
//		mn=min(mn,a[i]);
//	}
//	cout<<mx;
//	return 0;
//}
////【模板】前缀和
//#include <iostream>
//
//using namespace std;
//const int N=1e5+10;
//long long a[N];
//int main()
//{
//	int n,m;cin>>n>>m;
//	for(int i=1;i<=n;i++)
//	{
//		int t;cin>>t;
//		a[i]=a[i-1]+t;
//	}
//	while(m--)
//	{
//		int l,r;cin>>l>>r;
//		cout<<a[r]-a[l-1]<<endl;
//	}
//	return 0;
//}
