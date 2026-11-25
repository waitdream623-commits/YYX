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
    string s;cin >> s;
    ll n = s.size();
    ll t ;cin >>t;
    ll l = 1,r = n;
    while(l<r)
    {
        ll mid = (l+r)>>1;
         ll x = 1LL*mid*(n+n-mid+1)/2;
         if(x>=t)
         {
            r = mid;
         }
         else
         l = mid+1;
    }
    //位于第l个，具体字母位置
    t -= 1LL*(l-1)*(n+n-l+2)/2;
    //此时应该去除l-1个
    ll k = l - 1;
    string st;
    st.reserve(n);

    for (char c : s) {
        while (k > 0 && !st.empty() && st.back() > c) {
            st.pop_back();
            --k;
        }
        st.push_back(c);
    }

    // 如果还有删除次数，就从末尾删。
    if (k > 0) {
        st.resize(st.size() - k);
    }

    cout << st[t - 1];
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
