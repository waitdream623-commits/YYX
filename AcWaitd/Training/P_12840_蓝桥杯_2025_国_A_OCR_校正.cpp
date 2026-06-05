#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
#define lc p<<1
#define rc p<<1|1
const int N = 1e6 + 10,p=1e9+7;
//当操作1放在左右，此时有2^2021,最后会剩一个，
//操作1在中间，分为左右两段，需要枚举先操作左段还是右段
//2^(a+b-2)*求和c{2022,a};->2^4042,当a==0||b==0,只计算了2^2020,还差2^2021;强行凑二项式定理
ll qpow(ll a,ll b,ll p)
{
    ll ret=1;
    while(b)
    {
        if(b&1)ret=(ret*a)%p;
        b>>=1;
        a=a*a%p;
    }
    return ret;
}
void solve()
{
    cout<<(qpow(2,4042,1e9+7)+qpow(2,2021,1e9+7))%p;
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
