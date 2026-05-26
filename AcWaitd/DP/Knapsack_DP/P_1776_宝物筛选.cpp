#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
int v[N],w[N],m[N];
int newv[N],neww[N];
int cnt;
ll f[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;  // 多测时取消注释
    while (T--) {
        int n,W;cin>>n>>W;
        for(int i=1;i<=n;i++)
        {
            int a,b,y;
            cin>>a>>b>>y;
            //二进制拆分
            for(int j=1;j<=y;j<<=1)
            {
                neww[++cnt]=j*b;
                newv[cnt]=j*a;
                y-=j;
            }
            //剩余不是2的次方
            if(y>0)
            {
                neww[++cnt]=y*b;
                newv[cnt]=y*a;
            }
        }
        //0/1背包，优化版本
        for(int i=1;i<=cnt;i++)
        {
            for(int j=W;j>=neww[i];j--) 
            {
                f[j]=max(f[j],f[j-neww[i]]+newv[i]);
            }
        }
        cout<<f[W];
    }
    return 0;
}
