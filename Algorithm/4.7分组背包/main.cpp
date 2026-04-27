//P5322 [BJOI2019] 排兵布阵

#include <iostream>
#include <algorithm>
using namespace std;
const int N=110,M=1e5;
int f[N][M];
int a[N][N];
int s,n,m;
int main()
{
	//每个城堡分一组 
	cin>>s>>n>>m;
	for(int i=1;i<=s;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[j][i];
			a[j][i]=a[j][i]*2+1;
		}
	 } 
	for(int i=1;i<=n;i++)
	{
		sort(a[i]+1,a[i]+1+s); 
	}
	//分组背包
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			f[i][j]=f[i-1][j];
			for(int k=1;k<=s&&j>=a[i][k];k++)
			{
				f[i][j]=max(f[i][j],f[i-1][j-a[i][k]]+k*i);
			}
		}
	 } 
	 cout<<f[n][m];
	return 0;
 } 
