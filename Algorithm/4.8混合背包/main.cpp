//P1833 樱花
#include <iostream>

using namespace std;
const int N=1e4+10;
int t[N],v[N],cnt[N];
int f[N][1100];
int main()
{
	int a,b,c,d;char cc,ccc;
	cin>>a>>cc>>b>>c>>ccc>>d;
    // int start = a * 60 + b;
    // int end   = c * 60 + d;
    // int m = (end > start) ? (end - start) : (24*60 - start + end);

	int m;
    
	if(c>=a)//取等
	{
		m=c*60+d-a*60-b;
	}
	else
	m=24*60-a*60-b+c*60+d; 
	int n;cin>>n;
	//读入
	for(int i=1;i<=n;i++)
	{
		cin>>t[i]>>v[i]>>cnt[i];
	 } 
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			f[i][j]=f[i-1][j];
			if(cnt[i]==0)//完全背包 
			{
				if(j>=t[i])
				f[i][j]=max(f[i][j],f[i][j-t[i]]+v[i]);
			}
			else
			{
				for(int k=1;k<=cnt[i]&&j>=k*t[i];k++)
				{
					f[i][j]=max(f[i][j],f[i-1][j-k*t[i]]+k*v[i]);
				}
			}
		}
	}
	cout<<f[n][m];
	return 0;
 } 
