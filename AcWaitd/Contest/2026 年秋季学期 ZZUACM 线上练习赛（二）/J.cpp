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
#define rep(i,m,n) for(int i=m;i<=n;++i)
#define lc p<<1
#define rc p<<1|1
#define lowbit(x) (x&-x)
const int N = 1e6 + 10;
int a[N],b[N],dif[N];
int fa[N],fb[N];
void wait()
{
    int n, k;cin >> n >> k;
    rep(i,1,n)
    {
        cin >> a[i];
        fa[i] = a[i]+fa[i-1];
    }
    rep(i,1,n)
    {
        cin >> b[i];
        fb[i] = b[i] + fb[i-1];
    }
    rep(i,1,n)
    {
        dif[i] = a[i]-b[i];
    }
    // vector<vector<vector<ll>>>f(n+1,vector<vector<ll>>(k+1,vector<ll>(2,-1)));
    // auto dfs = [&](auto&&dfs,int i,int k,int sg)->ll
    // {
    //     if(i == n+1)
    //     {
    //         return 0;
    //     }
    //     if(f[i][k][sg]!=-1)
    //     {
    //         return f[i][k][sg];
    //     }
    //     ll ans = 0;
    //     ll t = dif[i]*(sg==1?1:-1);

    //     if(t>0&&sg>0)
    //     {
    //         if(k == 0)
    //         {
    //             return fa[n] - fa[i];
    //         }
    //         ans= max(ans,a[i]+dfs(dfs,i+1,k,sg));
    //     }
    //     else if(t>0&&sg<0)
    //     {
    //          if(k == 0)
    //         {
    //             return fb[n] - fb[i];
    //         }
    //         ans= max(ans,b[i]+dfs(dfs,i+1,k,sg));
    //     }
    //     else if(t<0&&k>0)
    //     {
    //         ans = max({ans,dfs(dfs,i+1,k-1,(sg+1)%2)+b[i]*!((sg==1?1:-1)==-1)+a[i]*!((sg==1?1:-1)==1),dfs(dfs,i+1,k,sg)+a[i]*((sg==1?1:-1)==1)+b[i]*((sg==1?1:-1)==-1)});
    //     }
    //     return f[i][k][sg] = ans;

    // };
    
    // cout << dfs(dfs,1,k,1)<<'\n';
    vector<vector<ll>>g(k+1,vector<ll>(2,0));

    for(int i = n; i >= 1; i--)
    {
        for(int j = k; j>=0;j--)
        {
            g[j][1]+=a[i] ;
            g[j][0]+=b[i] ;
            if(j > 0)
            {
                g[j][1]=max(g[j][1],b[i]+g[j-1][0]);
                g[j][0]=max(g[j][0],a[i]+g[j-1][1]);
            }
        }
    }
    cout << g[k][1]<<endl;;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;  // 多测时取消注释
    while (T--) {
        wait();
    }
    return 0;
}
