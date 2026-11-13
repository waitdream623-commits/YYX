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
const int N = 1e6 + 10,MOD =998244353;
void wait()
{
    int n ,L,R;
    cin >> n >> L >> R;
    string s ;cin >> s;
    auto dfs = [&](auto&&dfs,int i,char x,int cnt)->ll
    {
        if(i == n)
        return 1;
        //去除已经知道的
        i++;
        ll ans =0;
        while(i<n)
        {
            if(s[i]==x)
            {
                cnt++;
                if(cnt>R)
                {
                    return 0;
                }
            }
            else if(s[i]=='?')
            {
                if(cnt<L)
                {
                    s[i] = x;
                }
                else if(cnt==R)
                {
                    if(x=='0')
                    {
                        s[i] = '1';
                        cnt=1;
                    }
                    else
                    {
                        s[i] = '0';
                        cnt=1;
                    }
                }
                else//都可以
                {
                    int l =1,r =1;
                    if(x=='0')
                    l =cnt+1;
                    if(x=='1')
                    {
                        r =cnt+1;
                    }
                    ans += dfs(dfs,i+1,'0',l)+dfs(dfs,i+1,'1',r);
                    ans %=MOD;
                    break;

                }
            }
            else
            {
                char x =s[i];
                cnt =1;
            }
            i++;
            
        }
        return 1;
    };
    if(s[0]=='?')
    {
        cout << dfs(dfs,0,'0',1)+dfs(dfs,0,'1',1)<<'\n';
    }
    else
    cout << dfs(dfs,0,s[0],1)<<'\n';
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
