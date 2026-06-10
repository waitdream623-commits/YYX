#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
#define lc p<<1
#define rc p<<1|1
const int N = 1e6 + 10;
int a[N];
void solve()
{
    int n;cin>>n;
    for(int i=1;i<=n*2;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n*2);
    ll sum=0;
    for(int i=1;i<=n*2;i+=2)
    {
        sum+=a[i];
    }
    cout<<sum;
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
