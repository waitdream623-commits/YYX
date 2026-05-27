#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
int a[N],b[N];
int f[210][210];//表示1~i个物品，在j与k的情况下最多满足人数
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;  // 多测时取消注释
    while (T--) {
        int n,m,t;
        cin>>n>>m>>t;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i]>>b[i];

        }
        f[0][0]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=m;j>=a[i];j--)
            {
                for(int k=t;k>=b[i];k--)
                {
                    f[j][k]=max(f[j][k],f[j-a[i]][k-b[i]]+1);
                    //优化一维，变为倒序
                //     f[i][j][k]=f[i-1][j][k];
                //    if(k>=b[i]&&j>=a[i])
                //    {
                //     f[i][j][k]=max(f[i][j][k],f[i-1][j-a[i]][k-b[i]]+1);
                //    }
                }
            }
        }
        cout<<f[m][t];
    }
    return 0;
}
