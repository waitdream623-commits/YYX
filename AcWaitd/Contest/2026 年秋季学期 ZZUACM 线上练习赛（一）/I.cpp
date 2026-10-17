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
int t[N];
int n;
void add(int x,int v)
{
    for(int i = x;i<=n;i+=lowbit(i))
    {
        t[i]++;
    }
}
int query(int x)
{
    ll ans = 0;
    for(int i=x;i;i-=lowbit(i))
    {
        ans+=t[i];
    }
    return ans;
}
void wait()
{
    int  m;cin >> n >> m;
    rep(i,1,n)
    {
        int x;cin >>x;
        if(x==1)
        {
            add(i,1);
        }
    }
    rep(i,1,m)
    {
        int l, r;
        cin >> l >> r;
        cout << query(r)-query(l-1)<<"\n";
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
