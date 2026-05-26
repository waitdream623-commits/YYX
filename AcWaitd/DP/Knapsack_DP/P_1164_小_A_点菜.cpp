#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
int f[N],a[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;  // 多测时取消注释
    while (T--) {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)cin>>a[i];
        //初始化
        f[0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=m;j>=a[i];j--)
            {
                f[j]+=f[j-a[i]];
            }
        }
        cout<<f[m];
    }
    return 0;
}
