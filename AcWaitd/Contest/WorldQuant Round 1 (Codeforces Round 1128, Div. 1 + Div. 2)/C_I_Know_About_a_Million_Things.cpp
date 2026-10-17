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
    int e = 0,x = 0;
    rep(i,1,n)
    {
        int t; cin >> t;
        if(t%2)x++;
        else
        e++;
    }
    e +=x/2;
    x%=2;
    //2奇数可变偶数，
    if(e==1)
    {
        if((e+x)%2==0)
        {
            cout<<"Larpity\n";
            return;
        }
        
    }
    
     cout<<"Moggity\n";
            return;
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
