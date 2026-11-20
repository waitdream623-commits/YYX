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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    ll z = 0;
    rep(i,0,n-1)
    {
        if(s[i]=='0')z++;
    }
    ll o =n - z;

    ll m =max(0LL,min(z,o)- k);
    ll x = n - m;

    cout <<1+m*(m + 1)/2+x*(x + 1)/2<< '\n';
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
