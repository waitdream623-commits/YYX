//P1757 通天之分组背包

#include <iostream>
#include <vector>
using namespace std;
const int N=110;
typedef pair<int,int>PII;
vector<PII>g[N];
int f[N][1100];//数组开辟太小
int m,n;
 
int main()
{
	cin>>m>>n;
	int cnt=0;//计组数 
	for(int i=1;i<=n;i++)
	{
		int a,b,c;cin>>a>>b>>c;
		g[c].push_back({a,b});
		cnt=max(cnt,c);
	}
	for(int i=1;i<=cnt;i++)
	{
		for(int j=0;j<=m;j++)
		{
			f[i][j]=f[i-1][j];
			for(auto& e:g[i])
			{
				int a=e.first,b=e.second;
				if(j>=a) 
				f[i][j]=max(f[i-1][j-a]+b,f[i][j]);
			}
		}
	}
	cout<<f[cnt][m];
	return 0;
 } 
