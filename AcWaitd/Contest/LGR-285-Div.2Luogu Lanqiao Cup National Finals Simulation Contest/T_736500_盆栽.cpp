#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
ll f[N];
ll a[N];
void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        ll x;cin>>x;
        a[i]=x;
        f[i]=f[i-1]+x;
    }
    while(m--)
    {
        ll k;cin>>k;
        // for(int i=1;i<=n;i++)
        // {
        //     cout<<(a[i]^k)<<' ';
        // }
        ll mn=INF,mx=-INF;
        for(int i=2;i<n;i++)
        {
            ll t=f[i+1]-f[i-2];
            ll tmp=(a[i-1]^k)+(a[i]^k)+(a[i+1]^k);//三盆
            mn=min(mn,t-tmp);
            mx=max(mx,t-tmp);
            ll t2=f[i]-f[i-2];//两盆，缺最后两盆
            ll tmp2=(a[i]^k)+(a[i-1]^k);
            mn=min(mn,t2-tmp2);
            mx=max(mx,t2-tmp2);
        }
          ll tmp3=+(a[n-1]^k)+(a[n]^k);
            mn=min(mn,f[n]-f[n-2]-tmp3);
            mx=max(mx,f[n]-f[n-2]-tmp3);
        cout<<min(f[n]-mx,f[n])<<' '<<max(f[n]-mn,f[n])<<endl;//可以选择不操作
    }
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
