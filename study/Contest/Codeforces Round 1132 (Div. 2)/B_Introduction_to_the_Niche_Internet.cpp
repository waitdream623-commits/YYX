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
int b[N],c[N];
void wait()
{
    int n, k;
    cin >> n >> k;
    rep(i,1,n)cin >> a[i];
    sort(a+1,a+1+n);
    if (k == n) {              // 全升序，n 个都 pleasant
    cout << "YES\n";
    rep(i,1,n) cout << a[i] << ' ';
    cout << '\n';
    return;
}
    // int p = lower_bound(a+1,a+1+n,a[n-k+1])-a;
    // if(p!=n-k+1)
    // {
    //     cout << "NO\n";
    //     return;
    // }
    ll sum = 0;
    for(int i = n-k+1;i<=n;i++)
    {
        
        sum +=a[i];
    }
    if(1LL*a[n-k]*k<sum)
    {
            cout << "YES\n";

         for(int i = n-k+1;i<=n;i++)
    {
        cout << a[i]<<' ';
    }
        for(int i = n-k;i>0;i--)cout << a[i]<<' ';
        cout << '\n';
    }
    else
     cout << "NO\n";
    
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
