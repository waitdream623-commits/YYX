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
void wait()
{
    int n;
    cin >> n;
    vector<array<int,2>>a(n+1);
    ll sum=0;
    rep(i,1,n)
    {
        int x;cin >> x;
        a[i] = {x,i};
        sum +=x;
    }
    vector<int>in(n+1,0);
    rep(i,1,n-1)
    {
        int a,b;cin >> a >> b;
        in[a]++;
        in[b]++;
    }
    sort(a.begin(),a.end());
    int r = n;
    rep(i,1,n-1)
    {
        cout << sum<<' ';
        while(in[a[r][1]]==1)r--;
        sum+=a[r][0];
        in[a[r][1]]--;//减少该度，大于1时来一个新颜色会多贡献一次值
    }
    cout << '\n';
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
