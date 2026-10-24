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
int cnt[N];
void wait()
{
    int n ,k;
    cin >> n >> k;
    int mx = 0;
    memset(cnt,0,sizeof cnt);
    rep(i,1,n)
    {
        int x; cin >> x;
        cnt[x] ++ ;
        mx = max(x,mx);
    }
    
    if(cnt[0]<k)
    {
        cout << 0<<'\n';
        return ;
    }
    int ans = 1;
    int pres = cnt[0]-k;
    rep(i,1,mx)
    {
        if(cnt[i]&&pres+cnt[i]>=k)
        {
            if(pres>=k-1)
            {
                pres-=k-1;
                pres +=cnt[i]-1;
            }
            else
            {
                pres=pres+cnt[i]-k;
            }
            ans++;
        }
        else
        {
            break;
        }
    }
    cout << ans << '\n';
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
