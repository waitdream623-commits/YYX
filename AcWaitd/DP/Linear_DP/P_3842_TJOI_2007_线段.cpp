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
const int N = 1e6 + 10;
int f[N][2];//f[i][0]表示到达左端最短步数，f[i][1]表示到达右端最短
int a[N][2];
void wait()
{
    int n;cin>>n;
    rep(i,1,n)
    {
        cin>>a[i][0]>>a[i][1];
    }
    f[1][0]=a[1][1]-1+a[1][1]-a[1][0];
    f[1][1]=a[1][1]-1;
    rep(i,2,n)
    {
        //对f[i][0]应该直接先走到右端点，再往左
        //f[i][0]=min(f[i-1][0]+abs(a[i-1][0]-a[i][0])+a[i][1]-a[i][0]+a[i][1]-a[i][0]+1,f[i-1][1]+abs(a[i-1][1]-a[i][1])+a[i][1]-a[i][0]+1);//下降还有一步
        //f[i][1]=min(f[i-1][0]+abs(a[i-1][0]-a[i][0])+a[i][1]-a[i][0]+1,f[i-1][1]+abs(a[i-1][1]-a[i][1])+a[i][1]-a[i][0]+a[i][1]-a[i][0]+1);
        f[i][0]=min(f[i-1][0]+abs(a[i-1][0]-a[i][1])+a[i][1]-a[i][0]+1,f[i-1][1]+abs(a[i-1][1]-a[i][1])+a[i][1]-a[i][0]+1);
        f[i][1]=min(f[i-1][0]+abs(a[i-1][0]-a[i][0])+a[i][1]-a[i][0]+1,f[i-1][1]+abs(a[i][0]-a[i-1][1])+a[i][1]-a[i][0]+1);
    }
    cout<<min(f[n][0] + (n - a[n][0]), f[n][1] + (n - a[n][1]));
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
