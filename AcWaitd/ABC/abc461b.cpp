#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
#define lc p<<1
#define rc p<<1|1
const int N = 1e6 + 10;
int a[110],b[110];
map<int,int>mp;
void solve()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        mp[x]=i;//第i位拥有x
    }
    int f=0;
    for(int i=1;i<=n;i++)
    {
        int t;//第i个斧拥有者
        cin>>t;
        if(mp[i]!=t)
        {
            f=1;
        }
    }
    if(f)
    {
        cout<<"No";

    }
    else
    cout<<"Yes";
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
