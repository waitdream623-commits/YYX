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
int gcd(int a, int b)
{
    return b?gcd(b,a%b):a;
}
int f[N][25];
int lg[N];
void wait()
{
    int n,m;cin>>n>>m;
    lg[0]=-1;
    for(int i=1;i<=n;i++)
    {
        lg[i]=lg[i>>1]+1;
        cin>>f[i][0];
    }
    for(int j=1;j<=log2(n);j++)
    {
        for(int i=1;i+(1<<j)-1<=n;i++)
        {
            f[i][j]=gcd(f[i][j-1],f[i+(1<<(j-1))][j-1]);
        }
    }
    while(m--)
    {
        int l,r;
        cin>>l>>r;
        int k=lg[r-l+1];
        cout<<gcd(f[l][k],f[r-(1<<k)+1][k])<<"\n";

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
