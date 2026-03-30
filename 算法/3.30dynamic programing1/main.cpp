//P1057 [NOIP 2008 普及组] 传球游戏
#include <iostream>

using namespace std;
const int N=40;
int f[N][N];//f[i][j]表示第i次传递，到达j位置种类；
 
int main()
{	
	int n,m;cin>>n>>m;
	//初始化
	f[0][1]=1;
	for(int i=1;i<=m;i++)
	{
		f[i][1]=f[i-1][2]+f[i-1][n];
		for(int j=2;j<n;j++)
		{
			f[i][j]=f[i-1][j-1]+f[i-1][j+1];
		}
		f[i][n]=f[i-1][n-1]+f[i-1][1];
	} 
	cout<<f[m][1];
	return 0;
 } 



////P1115 最大子段和
////dp解决
//#include <iostream>
//#include <algorithm> 
//using namespace std;
//const int N=2e5+10;
//int a[N];
//long long f[N];//dp数组 
//int main()
//{
//	int n;cin>>n;
//	for(int i=1;i<=n;i++)cin>>a[i];
//	//找出每个位置的最大值
//	
//	//初始化
//	f[0]=0;
//	for(int i=1;i<=n;i++)
//	{
//		//状态转移方程 
//		if(f[i-1]<=0)f[i]=a[i];
//		else f[i]=f[i-1]+a[i];
//	 } 
//	sort(f+1,f+1+n);
//	cout<<f[n];
//	return 0;
// } 



////P1192 台阶问题
//#include <iostream>
//
//using namespace std;
//const int N=1E5+10,mod=1e5+3;
//int f[N];
//
//int main()
//{
//	int n,k;cin>>n>>k;
//	//初始化；
//	f[0]=1;
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=k&&(i-j)>-1;j++)
//		{
//			f[i]=(f[i]+f[i-j])%mod;
//		}
//	 } 
//	cout<<f[n];
//	return 0;
//}


////P1216 [IOI 1994 / USACO1.5] 数字三角形 Number Triangles
//#include <iostream>
//#include <algorithm>
//using namespace std;
//const int N = 1100;
//int a[N][N];
//int f[N];//dp数组，表示从开头到i的最大值 
//int main()
//{
//	int n;cin>>n;
//	for(int i=1;i <= n;i++)
//	{
//		for(int j = 1;j<= i;j++)
//		{
//			cin>>a[i][j];
//		}
//	 } 
//	//初始化，
//	for(int i=1;i<=n;i++)
//	{
//		//逆序处理，空间优化 
//		for(int j=i;j>=1;j--)
//		{
//            //状态转移方程
//			f[j]=max(f[j],f[j-1])+a[i][j]; 
//		}
//	 } 
//	 sort(f+1,f+1+n);
//	 cout<<f[n];
//	return 0;
//}


////P10250 [GESP样题 六级] 下楼梯
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//#include<string>
//#include<cmath>
//#include<vector>
//#include<queue>
//using namespace std;
//typedef pair<int,int>PII;
//const int N=70;
//long long f[N];//防止超出
//int main()
//{
//	int n;cin>>n;
//    //初始化
//	f[0]=1;f[1]=1;f[2]=2;
//	for(int i=3;i<=n;i++)
//	{
//        //状态转移方程
//		f[i]=f[i-1]+f[i-2]+f[i-3];
//		}
//	cout<<f[n];
//	return 0;
//}
