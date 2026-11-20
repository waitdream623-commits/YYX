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
    int a,b,n;
    cin >> a >> b >> n;
    if(b!=0)
    {
       b%=n;
       if(b==0)
       {
        a%=n;
        if(a==0)
        {
            cout << 0<<'\n';
        }
        else
        {
            cout << 1<<'\n';
        }
       }
      else
       {
        int d = n-b;
       if(a/2>=d)
       {
        a-=d*2;
        a%=n;
        if(a)
        {
            cout << 1<<'\n';
        }
        else
        {
            cout << 0 << '\n';
        }
       }
       else
       {
        if(a>=d)//依旧可以补充11
        {
            cout << 1 << '\n';
        }
        else

        cout << 2 << '\n';
       }
    }
    }
    else
    {
        a%=n;
        if(a==0)
        {
            cout << 0<<'\n';
        }
        else
        {
            cout << 1<<'\n';
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
