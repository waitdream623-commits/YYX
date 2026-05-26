#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
int w[N],v[N];
ll f[10010];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;  // 多测时取消注释
    while (T--) {
        int n,m;cin>>m>>n;
        int maxgroup=0;
vector<vector<int>>a(n+1);

        for(int i=1;i<=n;i++)
        {
            int k;
            cin>>w[i]>>v[i]>>k;
            maxgroup=max(maxgroup,k);
            a[k].push_back(i);
        }
        int k=0;
        for(int i=0;i<=maxgroup;i++)//可能从0开始
        {
            if(a[i].size()!=0)
            k++;
        }
        //优化
          for(int i=1;i<=k;i++)
        {
            if(a[i].empty())continue;
            for(int j=m;j>=0;j--)
            {
                for(auto&e:a[i])
                {
                    
                    if(j>=w[e])
                    {
                        f[j]=max(f[j],f[j-w[e]]+v[e]);
                    }
                }
            }
        }
        // for(int i=1;i<=k;i++)
        // {
        //     for(int j=0;j<=m;j++)
        //     {
        //         f[i][j]=f[i-1][j];//必须在外层，内层每次被替换
        //         for(auto&e:a[i])
        //         {
                    
        //             if(j>=w[e])
        //             {
        //                 f[i][j]=max(f[i][j],f[i-1][j-w[e]]+v[e]);
        //             }
        //         }
        //     }
        // }
        cout<<f[m];
    }
    return 0;
}
