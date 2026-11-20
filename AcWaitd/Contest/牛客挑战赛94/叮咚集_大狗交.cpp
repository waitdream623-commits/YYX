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
#define int long long
const int N = 1e6 + 10,MOD=998244353;
void wait()
{
    int n;cin >>n;
    ll ans = 0;
    // int lmin=1e9,rmin=0;
    // int lmax=0,rmax=0;
    vector<PII>a;
    rep(i,1,n)
    {
        int l,r;
        cin >> l >> r;
        a.push_back({l,0});
        a.push_back({r,1});


    }
    sort(a.begin(),a.end());
    vector<ll>st;
    for(auto [x,y]:a)//尽可能配对
    {
        if(y==0)
        {
            st.push_back(x);
        }
        else
        {
           ll len = x - st.back() + 1;
            st.pop_back();
            ans=(ans+len*len)%MOD;
        }
    }
    //可能内部还能继续配对
    // int l = l1,r=r1;
    // rep(i,2,n)
    // {
    //     auto [l1,r1]=a[i];
    //     if(l1<=r)//包含在内部不更新
    //     {
    //         if(r1>r)
    //         {
    //             ans -=(r1-l1+1)*(r1-l1+1);
            
    //         ans+=(r-l1+1)*(r-l1+1);
    //         ans%=MOD;
    //         ans += (r1-l+1)*(r1-l+1);
    //         ans%=MOD;

    //         ans-=(r-l+1)*(r-l+1);
    //         r=r1;
    //         }
    //     }
    //     else
    //     {
    //         l = l1,r=r1;
    //     }
    // }

    cout << ans<<'\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;  // 多测时取消注释
    while (T--) {
        wait();
    }
    return 0;
}
