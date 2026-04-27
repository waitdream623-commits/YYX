//P2758 编辑距离
#include <iostream>
#include <string>
using namespace std;
string s,t;
const int N=5010;
int f[N][N];
int main()
{
	cin>>s>>t;
	int n=s.size(),m=t.size();
	//初始化
	for(int i=1;i<=n;i++)f[i][0]=i;
	for(int i=1;i<=m;i++)f[0][i]=i; 
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(s[i-1]==t[j-1])f[i][j]=f[i-1][j-1];
			else
			{
				f[i][j]=min(min(f[i-1][j],f[i][j-1]),f[i-1][j-1])+1;
			}
		}
	}
	cout<<f[n][m];
	return 0;
}


////牛可乐和最长公共子序列
//#include <iostream>
//#include <string>
//using namespace std;
//string s,t;
//const int N=5010;
//int f[N][N];
//int main()
//{
//	while(cin>>s>>t)
//	{
//		int n=s.size(),m=t.size();
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=m;j++)
//			{
//				//判断符号== 
//				if(s[i-1]==t[j-1])f[i][j]=f[i-1][j-1]+1;
//				else
//				{
//					f[i][j]=max(f[i][j-1],f[i-1][j]);
//				}
//			}
//		}
//		//多组测试用例，记得换行 
//	cout<<f[n][m]<<endl;	
//	}
//	
//	return 0;
//}
////P1091 [NOIP 2004 提高组] 合唱队形
////二分加贪心
//
//#include<iostream>
//
//
//using namespace std;
//const int N=110;
//int a[N];
//int f[N],f1[N],len1;
//int g[N],g1[N],len2;
//int main()
//{
//	int n;cin>>n;
//	for(int i=1;i<=n;i++)cin>>a[i];
//	//左边
//	for(int i=1;i<=n;i++)
//	{
//		if(len1==0||f[len1]<a[i])f[++len1]=a[i],f1[i]=len1;
//		else
//		{
//			int l=1,r=len1;
//			while(l<r)
//			{
//				int mid=(l+r)/2;
//				if(f[mid]>=a[i])r=mid;
//				else
//				l=mid+1;
//			}
//			f[l]=a[i];
//			f1[i]=l;
//		}
//	 } 
//	//右边
//	for(int i=n;i>0;i--)
//	{
//		if(len2==0||g[len2]<a[i])g[++len2]=a[i],g1[i]=len2;
//		else
//		{
//			int l=1,r=len2;
//			while(l<r)
//			{
//			
//				int mid=(l+r)/2;
//				if(g[mid]>=a[i])r=mid;
//				else
//				l=mid+1;	
//			}
//			g[l]=a[i];
//			g1[i]=l;
//		}
//	 } 
//	 int ret=0;
//	 for(int i=1;i<=n;i++)
//	 {
//	 	ret=max(g1[i]+f1[i]-1,ret);
//	 }
//	 cout<<n-ret;
//	return 0;
// } 
