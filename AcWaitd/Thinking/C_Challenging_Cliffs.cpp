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
    int n;cin >> n;
    rep(i,1,n)cin >> a[i];
    sort(a+1,a+1+n);
    int t = INT_MAX;
    int k = 0;
    rep(i,2,n)
    {
        if(a[i] - a[i-1] <= t)//相等优先取后面
        {
            k = i;
            t = a[i] - a[i-1];
        }
    }
    cout << a[k-1]<<' ';
    rep(i,k+1,n)//保证尽可能上升
    {
        cout << a[i]<<' ';
    }
    rep(i,1,k-2)
    {
        if(i!=k-1&&i!=k)
        {
            cout << a[i]<<' ';
        }
    }
    cout << a[k]<<'\n';
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
