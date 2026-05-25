#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 5e6 + 10,MOD=998244353;
//不能用方式一和二
//方式一m，二n^2
int nn;
ll qpow(ll a,ll b,ll p)
{
    ll ret=1;
    while(b)
    {
        if(b&1)ret=(ret*a)%p;
        a=(a*a)%p;
        b>>=1;
    }
    return ret;

}
ll f[N],inv_f[N];
void init(int n)
{
    f[0]=1;//初始化第一位
    for(int i=1;i<=n;i++)
    {
        f[i]=i*f[i-1]%MOD;
    }
    inv_f[n]=qpow(f[n],MOD-2,MOD);
    for(int i=n-1;i>=0;i--)//记得到0
    {
        inv_f[i]=(i+1)*inv_f[i+1]%MOD;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T>>nn;  // 多测时取消注释
    ll ret=0;
    init(nn);
    while (T--) {
        int n,m;cin>>n>>m;
        int t=f[n]*inv_f[m]%MOD*inv_f[n-m]%MOD;
        ret^=t;
    }
    cout<<ret;
    return 0;
}
