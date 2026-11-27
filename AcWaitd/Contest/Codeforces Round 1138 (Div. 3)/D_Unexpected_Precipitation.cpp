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
int a[N],b[N];
void wait()
{
    int n;cin >> n;
    rep(i,1,n)
    cin >> a[i];
    rep(i,1,n)
    cin >> b[i];

    auto dfs = [&](auto&&dfs,int i,int x)->int
    {
        if(i>n)
        {
            return 0;
        }
        int ans =0 ;
        //选
        if(x==0)
        {
            ans = a[i]-b[i]+dfs(dfs,i+1,x);
        }
        else
        {
            ans =b[i]-a[i]+dfs(dfs,i+1,x);
        }
        //不选
        if(x==0)
        {
            ans = max(ans,dfs(dfs,i+1,(x+1)%2));
        }
        else
        {
            ans = min(ans,dfs(dfs,i+1,(x+1)%2));
        }

        return ans;
    };
     ll f0 = 0, f1 = 0;
     for (int i = n; i >= 1; --i)
    {
        ll d =a[i]-b[i];
        ll cur0 =max(d + f0, f1);
        ll cur1 =min(-d + f1, f0);
        f0 = cur0;
        f1 = cur1;
    }

        
    //  ll ret = dfs(dfs,1,0);
   ll ret = f0;
     if(ret>0)
     {
        cout << "Sunny\n";
     }
     else if(ret==0)
     {
        cout << "Draw\n";
     }
     else
     {
        cout << "Aubrey\n";
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
