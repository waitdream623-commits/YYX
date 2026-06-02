#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
#define lc p<<1
#define rc p<<1|1
const int N = 1e6 + 10;
//阶段为第i个工件，描述为是否翻转。f[i][{0,1}];
//属性为长度；
//转移f[i-1][{0,1}],f[i][{0,1}];
void solve()
{
    int n;cin>>n;
    auto a=vector<string>(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    auto dp=vector<vector<int>>(n+1,{(2,0)});

    dp[1][0]=2;
    dp[1][1]=2;
    for(int i=2;i<=n;i++)
    {
        int x=a[i-1][0],xe=a[i-1][1],y=a[i][0],ye=a[i][1];
        dp[i][0]=min(dp[i-1][0]+2-(xe==y),dp[i-1][1]+2-(x==y));
        dp[i][1]=min(dp[i-1][0]+2-(ye==xe),dp[i-1][1]+2-(x==ye));
    }
    cout<<min(dp[n][0],dp[n][1]);
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
