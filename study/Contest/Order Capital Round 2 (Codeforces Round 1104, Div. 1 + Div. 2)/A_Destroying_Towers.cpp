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
int mn[N];
void solve()
{
    int n;
    cin>>n;
    mn[0]=INF;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        mn[i]=min(mn[i-1],x);
    }
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=mn[i];
    }
    cout<<sum<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;  // 多测时取消注释
    while (T--) {
        solve();
    }
    return 0;
}
