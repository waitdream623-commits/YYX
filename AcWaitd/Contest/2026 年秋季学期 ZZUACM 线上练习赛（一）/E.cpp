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
    int n,k;
    cin >> n>>k;
    rep(i,1,n)cin >> a[i];
    int l = k,r= k;
    for(int i = 1;i<=n;i++)
    {
        l = r,r=k;
        if(i==1)
        {
            r-=a[i];
        }
        else if(i==n)
        {
            l-=a[i];
        }
        else
        {
            //优先使用左边的
            if(a[i]>=l)
            {
                a[i]-=l;
                l = 0;
                r-=a[i];
            }
            else
            {
                l-=a[i];
            }
        }
        if(r<0||l<0)//最后一个只使用l
        {
            cout << "NO\n";
            return;
        }
    }
   
        cout << "YES\n";
    
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
