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
#define endl '\n'
const int N = 1e6 + 10;
void wait()
{
    int n;cin >> n;
    string s ; cin >> s;
    string t ;
    bool fzreo=0,f1=0;
    int ans = 0;
    for(int i = n-1;i>=0;i--)
    {
        if(s[i] == '1')
        {
            f1=1;
        }
     
        if(s[i]=='0'&&f1)
        {
            ans ++;
            if(fzreo)
            {
                ans++;
                //将零移回去
            }
            f1=0;
        }
        if(s[i] == '0')
        {
            fzreo = 1;
        }
    }
    if(f1)//最开头是零
    {
         ans ++;
            if(fzreo)
            {
                ans++;
                //将零移回去
            }
            f1=0;
    }
    cout << ans << endl;
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
