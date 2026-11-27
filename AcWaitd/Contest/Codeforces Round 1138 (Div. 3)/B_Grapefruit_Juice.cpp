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
    int n,k,p;cin >> n >> k >> p;
    vector<int>a(n+1);
    rep(i,1,n)cin >> a[i];

    sort(a.begin()+1,a.end());
    int i =1;
    ll t = 0;
    
        ll sum=0;
        int x = 0;

        while(i<=n)
        {
            sum+=a[i];
            i++;
            x++;
            if(x==k&&sum<=p)
            {
                t+=p;
                x=0;
                sum=0;
            }
            else if(x==k&&sum>p)
            {
                t+=sum;
                sum=0;
                x=0;
                break;
            }
          
        }
        t+=sum;
        while(i<=n)
        {
            t+=a[i];
            i++;
        }
    cout << t<<'\n';
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
