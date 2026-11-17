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
int dx[] = {1,0,-1,0,1};
int a[N];
void wait()
{
    int n,m,k;
    cin >> n >> m>>k;
    int c;cin >> c;
    rep(i,1,c)
    {
        cin >> a[i];
    }
    sort(a+1,a+1+n,greater<int>());
    vector<vector<int>>f(n+1,vector<int>(m+1));
    int srcx = (n+1)/2,srcy = (m+1)/2;
    int ne = 0;//蛇状
    rep(i,1,n)
    {
        f[srcx][srcy] = a[i];
        
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
