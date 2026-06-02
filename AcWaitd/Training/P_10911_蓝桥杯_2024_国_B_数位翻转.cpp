#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=1100;
int calc(int x)
{
	int ret=0;
	while(x)
	{
		ret=ret*2+x%2;
		x/=2; 
	 } 
	 return ret;
}
ll f[N][N][2];
int main()
{
	int n,m;cin>>n>>m;
	vector<int>a(n+1),b(n+1);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=calc(a[i]);
	}
	//定义转移方程
	//f[i][j][{0,1}]表示到第i个数，翻转了j个区间，0表示第i位不翻转，1表示第i位翻转 
	//状态转移 
	//第i位不翻转，max(f[i-1][j][0]+a[i],f[i-1][j][1]+a[i]);
	//第i位翻转，max(f[i-1][j-1][0]+b[i],f[i-1][j][1]+b[i]);注意i-1翻转要选第j位，
															//因为翻转区间不想交
															//只能属于第j个区间
	//初始化，求max->0;
	//对于翻转时，j为0会越界，f[i][0][0]=a[i]+f[i-1][0][0],f[i][0][1]=0(非法)
	//结果，max(f[n][k][0],f[n][k][1]);	
	for(int i=1;i<=n;i++)
	{
		f[i][0][0]=a[i]+f[i-1][0][0];
		for(int j=1;j<=m;j++)
		{
			f[i][j][0]=max(f[i-1][j][0]+a[i],f[i-1][j][1]+a[i]);
			f[i][j][1]=max(f[i-1][j-1][0]+b[i],f[i-1][j][1]+b[i]);
		}
	}
	ll ret=0;
	for(int i=1;i<=m;i++)ret=max(f[n][i][0],f[n][i][1]);
	cout<<ret;								 
	return 0;
}








