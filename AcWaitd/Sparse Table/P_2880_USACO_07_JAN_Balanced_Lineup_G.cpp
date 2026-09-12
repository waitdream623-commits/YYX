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
#define lc p<<1
#define rc p<<1|1
const int N = 1e6 + 10;
int f[N][25][2];
void wait()
{
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)//0存储最大，1存储最小
    {
        cin>>f[i][0][0];
        f[i][0][1]=f[i][0][0];
    }
    for(int j=1;j<=log2(n);j++)
    {
        for(int i=1;i+(1<<j)-1<=n;i++)
        {
            f[i][j][0]=max(f[i][j-1][0],f[i+(1<<(j-1))][j-1][0]);
            f[i][j][1]=min(f[i][j-1][1],f[i+(1<<(j-1))][j-1][1]);
            
        }
    }
    while(m--)
    {
        int l,r;
        cin>>l>>r;
        int k=log2(r-l+1);
        cout<<max(f[l][k][0],f[r-(1<<k)+1][k][0])-min(f[l][k][1],f[r-(1<<k)+1][k][1])<<"\n";
    }
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
