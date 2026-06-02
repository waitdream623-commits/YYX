#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=1100,p=1e9+7;
int f[110][110][110];//因为酒最后一定会喝完，k不会太大
//表示到达第i个酒馆，第j个花，含有k斗酒
//状态转移f[i+1][j][k*2]+=f[i][j][k],f[i][j+1][k-1]+=f[i][j][k];(k-1>0)
//初始化f[0][0][2]=1; 
int main()
{
	int n,m;cin>>n>>m;
	f[0][0][2]=1;
	
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<m-1;j++)
		{
			for(int k=0;k<=m;k++)
		{
			if(f[i][j][k])
			{
			if(k*2<=m)
			f[i+1][j][k*2]=(f[i+1][j][k*2]+f[i][j][k])%p;
			if(k-1>=0)
			f[i][j+1][k-1]=(f[i][j][k]+f[i][j+1][k-1])%p;
			}
		}
		}
	}
	cout<<f[n][m-1][1];//最后一次遇到的是花 
	return 0;
}




