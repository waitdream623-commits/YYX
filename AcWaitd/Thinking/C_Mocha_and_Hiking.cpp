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
void wait()
{
    int n;cin >>n;
    int f =0 ;
    rep(i,1,n)
    {
        cin >> a[i];
        if(i!=1&&a[i]!=a[i-1]&&a[i]==1)//必须0/1
        f=i;
    }
    if(a[n] == 0)
    {
        rep(i,1,n+1)cout << i << ' ';
        cout << '\n';
    }
    else if(a[1] == 1)//可以放在开头
    {
        cout << n+1 << ' ';
        rep(i,1,n)cout << i << ' ';
        cout << '\n';
    }
    else
    {

        if(f)//中途加入n+1
        {
            rep(i,1,n)
            {
                cout << i << ' ';
                if(i==f-1)//是进入n+1
                cout << n+1<<' ';
            }
        cout << '\n';
        }
        else
        cout << -1;
        cout << '\n';
    }
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
