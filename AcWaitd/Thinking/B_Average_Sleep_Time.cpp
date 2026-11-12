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
    int n,k;cin >> n >> k;
    rep(i,1,n)
    {
        cin >> a[i];
    }
    int l = 1,r=1;
    ll ans = 0,sum = 0;
   for(int i =1;i<=n;i++)
   {
    if(i<=k)sum+=a[i];
    else
    {
        sum+=a[i]-a[i-k];
    }
    if(i>=k)
    ans +=sum;
   }
    printf("%.6f\n",ans*1.0/(n-k+1));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    //cin >> T;  // 多测时取消注释
    while (T--) {
        wait();
    }
    return 0;
}
