#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
#define lc p<<1
#define rc p<<1|1
const int N = 1e6 + 10,p=998244353;
void solve()
{

    int n,m;cin>>n>>m;
    auto a=vector<int>(n+1,0);
    ll ans=1;
    for(int i=1;i<=n;i++)
    {
      int x;cin>>x;
      a[x]++;
      ans=ans*(m-a[x]+1)%p;
      if(a[x]>m)ans=0;
      cout<<ans<<' ';
    }
    cout<<'\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;  // 多测时取消注释
    while (T--) {
        solve();
    }
    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// typedef unsigned long long ull;
// typedef pair<int,int>PII;
// int INF=0x3f3f3f3f;
// const int N = 1000010;
// const int MOD = 998244353;
// ll fact[N], inv_fact[N];

// ll qpow(ll a, ll b, ll p) {
//     ll ret = 1;
//     while (b) {
//         if (b & 1) ret = ret * a % p;
//         a = a * a % p;
//         b >>= 1;
//     }
//     return ret;
// }

// void init(int n) {
//     fact[0] = 1;
//     for (int i = 1; i <= n; i++)
//         fact[i] = fact[i - 1] * i % MOD;
//     inv_fact[n] = qpow(fact[n], MOD - 2, MOD);
//     for (int i = n - 1; i >= 0; i--)//倒着推导
//         inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
// }

// ll get_c(ll n, ll m, ll p) {
//     if (m > n || m < 0) return 0;
//     return fact[n] * inv_fact[m] % p * inv_fact[n - m] % p;
// }
// int a[N];int b[N];
// void solve()
// {
//     int n,k;cin>>n>>k;
//     init(n);
//     for(int i=1;i<=n;i++)cin>>a[i];
//     for(int i=1;i<=n;i++)
//     {
//         ll ret=0;
//         for(int j=1;j<=i;j++)
//         {
//             //计算倍数
//             if(j==1)
//             ret+=get_c(n,k,MOD)*fact[k];
//             else
//             {
//                 int cnt=0;
//                 memcpy(b+1,a+1,sizeof(int)*i);
//                 sort(b+1,b+1+i);
//                 //找递增长度为j
//                 for(int k=1;k<=i-j+1;k++)
//                 {
//                     ll t=0;
//                     for(int z=k+1;z<=i;z++)
//                     {
//                         if(a[z]>a[k])t++;
//                         if(t==j)
//                         {
//                             cnt++;
//                             break;
//                         }
//                     }
//                 }
//                 ret=(ret+get_c(n,))
//             }
//         }
//     }

// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     cin >> T;  // 多测时取消注释
//     while (T--) {
//         solve();
//     }
//     return 0;
// }
