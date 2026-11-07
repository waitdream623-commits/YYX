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
    int n , k;cin >> n >>k;
    int x1=0,x2=0,y1=0,y2=0;
    rep(i,1,n)
    {
        int x; cin >> x;
        if(x%2==0)
        {
            x1++;
        }
        else
        {
            y1++;
        }
    }
      rep(i,1,n)
    {
        int x; cin >> x;
        if(x%2==0)
        {
            x2++;
        }
        else
        {
            y2++;
        }
    }
    if(k%2==0)////奇数变偶数
    {
        if(x1<=x2)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    else//只能偶数变奇数
    {
        if(x1>=x2)
         {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
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
