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
    string a, b;cin >> a >> b;
    if(a.size()!=b.size())
    {
        cout << 0 << '\n';
        return;
    }
    int l=0,r =0 ;
    int ans =0;
    while(l<a.size())
    {
        if(a[l]==b[l])
        {
            ans+=2;
            l++;
        }
        else if(abs(b[l]-a[l])==1)
        {
           ans++;
           l++;
        }
        else
        break;
    }
     cout << ans << '\n';

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
