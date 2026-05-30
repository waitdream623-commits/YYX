#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10,p=998244353 ;
ll pow(ll a,ll b,ll p)
{
    ll ret=1;
    while(b)
    {
        if(b&1)ret=(ret*a)%p;
        b>>=1;
        a=(a*a)%p;
    }
    return ret;
}
void solve()
{
    ll ret=pow(4,341799*3+2,p);
    ret=(ret*5)%p;
    ret=(ret*49)%p;
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
