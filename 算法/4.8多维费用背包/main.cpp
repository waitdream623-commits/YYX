//P1910 L 国的战斗之间谍
#include <iostream>

using namespace std;
const int N=1e3+10;
int f[N][N];
int a[N],b[N],c[N];
int main()
{
	int n,m,x;cin>>n>>m>>x;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=b[i];j--)
		{
			for(int k=x;k>=c[i];k--)
			{
				f[j][k]=max(f[j][k],f[j-b[i]][k-c[i]]+a[i]);
			}
		}
	}
	cout<<f[m][x];
	return 0;
 } 

