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
    int n,m,k;cin >> n >> m >> k;
    if(n-m>k||m>(n-1-k+1)*(n-k+1)/2)
    {
        cout << -1 << '\n';
    }
    else
    {

            int cnt=0;
            rep(j,1,n-k)
            rep(i,j+1,n-k+1)
            {
                cnt++;
                cout << j<<' '<<i<<'\n';
                if(cnt==m)
                {
                    return;
                }
            }
        
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
