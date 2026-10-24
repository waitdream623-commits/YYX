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
    int n;cin  >> n;
    bool flag= 0;
    int m = 1e9;
    rep(i,1,n)
    {
        cin >> a[i];
        m = min(m,a[i]);
        if(a[i]==0)
        {
            flag = 1;
        
        }

    }
    if(flag)
    {
        cout << n << '\n';
        return ;
    }
    if(m>=n)//最小值大于等于长度，说明至少删完，优先构造出一个0
    {
        cout << 0 <<'\n';
    }
    else
    {
        cout << n<<'\n';
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
