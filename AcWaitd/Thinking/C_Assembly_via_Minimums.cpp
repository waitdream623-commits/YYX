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
    map<ll,ll>st;
    ll n;cin >> n;
    rep(i,1,(n-1)*n/2)    
    {
        int x; cin >> x;
        st[x]++;//统计词频，知道原数组有多少个
    }
    ll c = 0;
    ll cnt = n-1;//该最小数，会产生多少个b
    int last = 0;
    for(auto [e,x]:st)
    {
        while(x!=0)
        {
            last = e;
            x-=cnt;
            cout << e <<' ';
            cnt --;
        }
       
    }
    //补上最后一个
    cout << last<<' ';
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
