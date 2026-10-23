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
    int n;cin >> n;
    string s;
    cin >>s;
    int ans = -1;
    if(s[n-1]!=')')
    {
        cout << ans;
        return;
    }
    int flag = 0;
    for(int i = n-2;i>=0;i--)
    {
        if(s[i] == '('&&!flag)
        {
            flag =1;
            ans = i+1;
        }
        else if(s[i]==')'){
            flag=1;
        }
    }
    cout << ans;
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
