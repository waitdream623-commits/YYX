#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
#define lc p<<1
#define rc p<<1|1
const int N = 1e6 + 10,mod=998244353;
//2与4列单独判断，对1，3，5进行分析
//奇数列相互独立，仅需要考虑一个
//f[i][{0,1}][{0,1}]表示前i个，第一个是否是元音，第i个是否是元音；
//f[i][j][0]=(f[i-1][j][0]+f[i-1][j][1])*21
//f[i][j][1]=f[i-1][j][0]*5;
//再枚举偶数列情况2^4
ll f[N][2][2];
int w[]={21,5};
void solve()
{
    int n=341799;
    for(int i=0;i<2;i++)
        f[1][i][i]=w[i];
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<2;j++)
        for(int k=0;k<2;k++)
        {
            for(int l=0;l<2;l++)
            if(!l||!k)
            (f[i][j][k] += f[i - 1][j][l] * w[k]) %= mod;
        }
    }
    ll ans=0;
    for(int a=0;a<2;a++)
    for(int b=0;b<2;b++)
    for(int c=0;c<2;c++)
    for(int d=0;d<2;d++)
    {
        ll w1=0,w2=0,w3=0;
        for(int x=0;x<2;x++)
        for(int y=0;y<2;y++)
        {
            int cal = f[n][x][y];
  		bool f1 = (!x || !a) && (!y || !b);//不能连续为元音
  		bool f2 = (!x || !c) && (!y || !d);
  		if (f1) (w1 += cal) %= mod;
  		if (f1 && f2) (w2 += cal) %= mod;//第3列
  		if (f2) (w3 += cal) %= mod;
        }
        (ans += w1 * w2 % mod * w3 % mod * w[a] % mod * w[b] % mod * w[c] % mod * w[d] % mod) %= mod;
  }
    cout<<ans;
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
