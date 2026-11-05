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
void solve()
{
    ll a,b;
    cin>>a>>b;
   if (b == 1) cout << "NO\n";
else {
    cout << "YES\n";
    cout << a << " " << a * (2 * b - 1) << " " << a * 2 * b << "\n";//x与y不能相同
}
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
