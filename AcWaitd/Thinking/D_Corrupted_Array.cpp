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
ll a[N];
void wait()
{
    int n;cin >> n;
    rep(i,1,n+2)
    {
        cin >> a[i];
    }
    sort(a+1,a+1+n+2);
    ll sum = 0;
    rep(i,1,n)
    {
        sum +=a[i];
    }
    if(a[n+1] == sum ||a[n+2]==sum )//x在最后
    {
        rep(i,1,n)cout << a[i]<<' ';
        cout << '\n';
    }
    else//在前面，包含进n+1
    {
        sum +=a[n+1];
        ll f = sum-a[n+2];//需要去掉
        bool fg = 0;
        rep(i,1,n+1)
        {
            if(a[i] == f)
            {
                fg = 1;//找到了
                f = i;//必须退出，否则修改后可能被再次多删
                break;
            }
        }
        if(fg)
        {
             rep(i,1,n+1)
        {
            if(i == f)continue;
            cout << a[i]<<' ';
        }
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
