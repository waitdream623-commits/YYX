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
int a[N],b[N];
void wait()
{
    int n, k ;
    cin >> n >> k;
    rep(i,1,n)cin >> a[i];
    rep(i,1,n)cin >> b[i];
    // sort(a+1,a+1+n);
    // sort(b+1,b+1+n,greater<int>());
    // vector<bool>vis(n+1,0);
    // ll ans = 0;
    // rep(i,1,n)
    // {
    //     auto pos = lower_bound(b+1,b+1+n,a[i]+k,greater<int>())-b;
    //     if(pos == 0)
    //     {
    //         continue;
    //     }
        
    //     while(pos>0&&vis[pos]&&abs(b[pos+1]-a[i])<=k)
    //     {
    //         pos++;
            
    //     }
    //     if(pos!=0)
    //    { vis[pos]=1;
    //         ans++;}
    // }
    sort(a+1, a+n+1);
    sort(b+1, b+n+1);
    int i = 1, j = 1;
    int ans = 0;
    while(i <= n && j <= n)
    {
        if(a[i]+k < b[j])i++;
        else if(b[j]+k < a[i])j++;
        else
        {
            ans++;
            i++;
            j++;
        }
    }

    cout << ans <<'\n';
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
