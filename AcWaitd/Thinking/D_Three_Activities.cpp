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
PII a[3][N];
void wait()
{
    int n;
    cin >> n;
    rep(i,0,2)
    {
        rep(j,1,n)
        {
            int x ; cin >> x;
          a[i][j] = {x,j};
        }
    }
    sort(a[0]+1,a[0]+1+n,[](auto&a,auto&b){return a>b;});
    sort(a[1]+1,a[1]+1+n,[](auto&a,auto&b){return a>b;});
    sort(a[2]+1,a[2]+1+n,[](auto&a,auto&b){return a>b;});
    int ans = 0;
    rep(i,1,3)//每组选前三个最大
    {
        rep(j,1,3)
        {
            rep(k,1,3)
            {
                if(a[0][i].second!=a[1][j].second&&a[0][i].second!=a[2][k].second&&a[1][j].second!=a[2][k].second)
                {
                    ans = max(ans,a[2][k].first+a[0][i].first+a[1][j].first);
                }
            }
        }
    }
    cout << ans << "\n";
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
