#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
#define lc p<<1
#define rc p<<1|1
const int N = 1e6 + 10;
//以序列字母划分阶段，该个字母可选与不选
//f[i],表示以0~i区间最大价值,如果不选，与i-1相同，选则找i-2；//选i-2,尽可能多选
void solve()
{
    string s;cin>>s;
    int n=s.size();
    auto dp=vector<int>(n,0);
    for(int i=0;i<n;i++)
    {
        if(i==0||i==1)dp[i]=max(dp[0],s[i]-'a'+1);//此处初始化注意
        if(i>=2)
        dp[i]=max(dp[i-1],dp[i-2]+s[i]-'a'+1);
    }
    cout<<dp[n-1];

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
