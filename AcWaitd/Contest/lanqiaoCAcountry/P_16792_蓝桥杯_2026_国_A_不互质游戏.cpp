#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
#define lc p<<1
#define rc p<<1|1
const int N = 1e6 + 10;
int n;
bool st[N];
int p[N], cnt;
int phi[N];
void get_phi()
{
phi[1] = 1;
for(int i = 2; i <= n; i++)
{
if(!st[i])
{
p[++cnt] = i;
phi[i] = i - 1;
}
for(int j = 1; 1ll * i * p[j] <= n; j++)
{
int x = i * p[j]; // 当前要筛的数
st[x] = true;
if(i % p[j] == 0)
{
phi[x] = p[j] * phi[i];
break;
}
else
{
phi[x] = (p[j] - 1) * phi[i];
}
}
}
}
void solve()
{
    int n;cin>>n;
    ll ret=0;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        ret^=(x-1-phi[x]);
    }
    if(ret==0)cout<<"No"<<endl;
    else
    cout<<"Yes"<<endl;
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
