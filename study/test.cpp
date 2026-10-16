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
int b[N];
int T = 1;

void wait()
{
    int n , m;
    cin >> n >> m;
    rep(i,1,m)
        cin >> a[i];
      rep(i,1,m)
        cin >> b[i];
    
    vector<vector<int>>f(m+1,vector<int>(n+1,0));
    for(int i = 1 ; i<=m;i++)
        {
            rep(j,1,n)
                {
                f[i][j] = f[i-1][j];
                if(j>=a[i])
                {
                    f[i][j] = max(f[i-1][j],f[i-1][j-a[i]]+b[i]);
                }
                }
        }
        cout << f[m][n] << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;  // 多测时取消注释
    while (T--) {
        wait();
    }
    return 0;
}
