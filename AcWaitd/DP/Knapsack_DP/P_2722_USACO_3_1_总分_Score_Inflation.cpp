#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
int t[N],s[N],f[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;  // 多测时取消注释
    while (T--) {
        int m,n;
        cin>>m>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>s[i]>>t[i];

        }
        for(int i=1;i<=n;i++)
        {
            for(int j=t[i];j<=m;j++)//完全背包空间优化从做到右，因为需要用到本层
            {
                f[j]=max(f[j],f[j-t[i]]+s[i]);
            }
        }
        cout<<f[m];
    }
    return 0;
}
