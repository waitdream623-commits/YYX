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
int g[1100][2010];
void wait()
{
    int k ;cin >> k;
    g[1][k] = 1;
    for(int i = 2;i<=k;i++)
    {
        for(int j=k-i+1;j-k+i<=i*2-1;j++)
        {
            g[i][j] = g[i-1][j-1]^g[i-1][j+1];
        }
    }
    for(int i = 1;i<=k;i++)
    {
        rep(j,1,2*k-1)
        {
            if(g[i][j])
            cout << "#";
            else
        cout << " ";
        }
        cout <<"\n";
        
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;  // 多测时取消注释
    while (T--) {
        wait();
    }
    return 0;
}
