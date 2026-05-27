#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
int a[N];
int f[110][110];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;  // 多测时取消注释
    while (T--) {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }

        f[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=0; j<=m;j++)
            {
                f[i][j]=f[i-1][j];
                //第三层，枚举i种摆放个数
                for(int k=1;k<=a[i];k++)
                {
                    if(j>=k)
                    {
                        f[i][j]=(f[i][j]+f[i-1][j-k])%1000007;
                    }
                }
            }
        }
        cout<<f[n][m];
    }
    return 0;
}
