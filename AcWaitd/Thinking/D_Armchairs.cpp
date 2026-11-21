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
    vector<bool>vis(n+1);
    rep(i,1,n)
    {
        cin >> a[i];
        vis[i] = a[i];
    }
    ll ans = 0;
    rep(i,1,n)
    {
        if(a[i]==1&&vis[i])
        {
                int k = i-1;
                while(k>0&&a[k]!=0)k--;
                
                int r  = i+1;
                while(r<=n&&a[r]!=0)r++;
                if(k==0)
                {
                    a[r] = 1;
                    ans +=r-i;
                }
                else if(r==n+1)
                {
                     a[k] =1;
                    ans+=i-k;
                }
                else
                {
                    if(i-k<=r-i)
                    {
                        a[k] =1;
                        ans+=i-k;
                    }
                    else
                    {
                        a[r] = 1;
                    ans +=r-i;
                    }
                }

            
        }
    }
    cout << ans<<'\n';
}
void wait1() {
    int n;
    cin >> n;

    vector<int> people, seats;
    for (int i = 1; i <= n; ++i) {
        int occupied;
        cin >> occupied;
        if (occupied) people.push_back(i);
        else seats.push_back(i);
    }

    int m = people.size();
    vector<int> dp(m + 1, 1'000'000'000);
    dp[0] = 0;

    for (int seat : seats) {
        for (int i = m; i >= 1; --i) {
            dp[i] = min(dp[i], dp[i - 1] + abs(people[i - 1] - seat));
        }
    }

    cout << dp[m] << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;  // 多测时取消注释
    while (T--) {
        wait1();
    }
    return 0;
}
