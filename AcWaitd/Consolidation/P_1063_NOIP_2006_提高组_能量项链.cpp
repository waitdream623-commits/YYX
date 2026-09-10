#include <bits/stdc++.h>
#include <math.h>
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
#define lc p<<1
#define rc p<<1|1
const int N = 1e6 + 10;
int a[N];
int f[210][210];//循环开两倍
void solve()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        a[i]=a[n+i]=x;//处理环，倍增
    }
    for(int len = 3; len<=n+1;len++)
    {
        for(int i=1;i+len-1<=2*n;i++)
        {
            int j=i+len-1;
            for(int k=i+1;k<j;k++)
            {
                f[i][j]=max(f[i][k]+f[k][j]+a[i]*a[k]*a[j],f[i][j]);
            }

        }
    }
    int ret=0;
    for(int i=1;i<=n;i++)
    ret=max(f[i][i+n],ret);
    cout<<ret;

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;  // 多测时取消注释
    while (T--) {
        solve();
    }
    return 0;
}
