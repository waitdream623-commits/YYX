#include <bits/stdc++.h>
using namespace std;
#ifndef DEBUG
struct __X {
  __X& operator<<(const auto& str) {return *this;}
  void sp(const string& str = "") {}
} dout;
#define debug(x)
#endif
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
#define lc p<<1
#define rc p<<1|1
const int N = 1e6 + 10;
int f[N],g[N],su[N][25];
int t[N];
int h[N];//统计01出现次数
void wait()
{
    int n,m;cin>>n>>m;
    g[0]=0,f[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>t[i];
        g[i]=g[i-1];f[i]=f[i-1];
        if(t[i]==0)
        {
            f[i]++;
        }
        else
        {
            g[i]++;

        }
        su[i][0]=f[i]-g[i];
    }
    //预处理su，st表
    for(int j=1;j<=log2(n);j++)
    {
        for(int i=1;i+(1<<j)-1<=n;i++)
        {
            su[i][j]=max(su[i][j-1],su[i+(1<<(j-1))][j-1]);
        }
    }
    //dp处理查询2
    for(int i=1;i<=n;i++)
    {
        if(t[i]==1&&t[i-1]==0)h[i]=h[i-1]+1;
        else
        h[i]=h[i-1];
    }
    while(m--)
    {
        int op,l,r;cin>>op>>l>>r;
        if(op==1)
        {
            int k=log2(r-l+1);
            int mx=max(su[l][k],su[r-(1<<k)+1][k]);//st表
            cout<<max(f[r]-f[l-1],max(g[r]-g[l-1],g[r]-f[l-1]+mx))<<'\n';
        }
        else
        {
            if(h[r]==h[l])cout<<1<<'\n';
            else
            cout<<2<<"\n";
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;  // 多测时取消注释
    while (T--) {
        wait();
    }
    return 0;
}
