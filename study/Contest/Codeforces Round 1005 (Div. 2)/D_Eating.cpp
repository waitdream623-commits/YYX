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
    int n,q;
    cin >> n >> q;
    rep(i,1,n)cin >> a[i];
    for(int i = n;i>0;i--)
    {
        b[i] = b[i]^b[i+1];
    }
    while(q--)
    {
        int x;cin >> x;
        int l = 1,r =n;
        if(x<a[n])
        {
            cout << 0<<' ';
            continue;
        }
        while(l<r)
        {
            int mid = (l+r)>>1;
            if((b[mid]^x)<a[mid-1])
            {
                l = mid+1;
            }
            else
            {
                r = mid;
            }
        }
        cout << n-l+1<<' ';
    }
    cout << '\n';
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
