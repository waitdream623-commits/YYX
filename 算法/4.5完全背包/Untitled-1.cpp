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

