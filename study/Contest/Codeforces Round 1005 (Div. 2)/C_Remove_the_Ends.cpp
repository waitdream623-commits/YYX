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
int a[N];
void wait()
{
    int n;cin >> n;
    rep(i,1,n)
    {
        cin  >> a[i];
    }
    map<PII,ll>f;
    auto dfs = [&](auto&&dfs,int l ,int r)->ll
    {
        if(l>r)
        {
            return 0;
        }
        ll ans = 0;
        if(f[{l,r}])return f[{l,r}];
        for(int i = l;i<=r;i++)
        {
            if(a[i]>=0)
            {
                ans = max(ans,abs(a[i])+dfs(dfs,i+1,r));
            }
            else
            {
                ans = max(ans,abs(a[i])+dfs(dfs,l,i-1));

            }
        }
        return f[{l,r}] = ans;
    };
    // //区间dp
    // map<PII,ll>f;
    // for(int len = 1;len<=n;len++)
    // {
    //     for(int i = 1;i+len-1<=n;i++)
    //     {
    //         int j = i+len-1;
    //         for(int k = i;k<=j;k++)
    //         {
    //             //越长越可能大，万一值很小
    //             if(a[k]<0)
    //             {
    //                 f[{i,j}]=max(f[{i,j}],-a[k]+f[{i,k-1}]);
    //             }
    //             else
    //                 f[{i,j}]=max(f[{i,j}],a[k]+f[{k+1,j}]);

    //         }
    //     }
    // }
    // cout << f[{1,n}]<<'\n';

    // int l = 1 ,r =n;
    // ll ans = 0;
    // while(l<=r)
    // {
    //     while(a[l]>=0)
    //     {
    //         ans+=a[l++];
    //     }
    //     while(a[r]<0)
    //     {
    //         ans+=-a[r--];
    //     }
    //     //此时选择
    //     ans += dfs(dfs,l,r);
    //     break;

    // }
    // cout << ans<<'\n';
    // cout << dfs(dfs,1,n)<<'\n';
    vector<ll>pre(n+1,0),sub(n+2,0);
    rep(i,1,n)
    {
        pre[i] = pre[i-1];
        if(a[i]>=0)
        pre[i]+=a[i];
    }
    for(int i = n;i > 0;i--)
    {
        sub[i] = sub[i+1];
        if(a[i]<0)
        sub[i] -=a[i];
    }
    ll ans = 0;
    rep(i,1,n)
    {
        ans = max(ans, sub[i]+pre[i]);
    }
    cout << ans<<'\n';
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
