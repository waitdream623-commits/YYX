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
    rep(i,1,n)
    {
        cin >> a[i];
    }
    vector<array<int,2>>memo(n+1,{-1,-1});
    auto dfs = [&](auto&&dfs,int i,int p)->int
    {
        if(i>n)
        {
            return 0;
        }
        if(memo[i][p]!=-1)
        {
            return memo[i][p];
        }
        if(p%2==0)//0为friend，1为me
        {
            int p1=0,p2=0;
            if(a[i]==1)
            {
                p1 = 1;
            }
            p1 += dfs(dfs,i+1,(p+1)%2);
            if(a[i+1]==1)
            {
                 if(a[i]==1)
                 {
                    p2=2;
                 }
                 else
                 p2=1;
            }
            else
            {
                p2 = a[i]==1?1:0;
            }

            p2 += dfs(dfs,i+2,(p+1)%2);
            return memo[i][p]=min(p1,p2);
        }
        else
        {
            return memo[i][p]=min(dfs(dfs,i+1,(p+1)%2),dfs(dfs,i+2,(p+1)%2));
        }

    };
    cout << dfs(dfs,1,0)<<'\n';
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
