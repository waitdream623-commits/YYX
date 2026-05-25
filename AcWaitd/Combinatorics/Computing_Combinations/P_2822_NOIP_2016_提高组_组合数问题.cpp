#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 2e3 + 10;

int k;
//杨辉三角求组合树
int f[10000][10000];//组合数
ll g[N][N];//前缀余数和，注意多处理一个点,得开ll
void get_c(ll n)
{
    
    for(int i=0;i<=n;i++)
    {
        f[i][0]=1;//填每一行起始位置，j从1开始，防止越界，i=0;不会进入循环
        //不需要判断边界值？，可能k>1
        for(int j=1;j<=i;j++)
        {
            f[i][j]=(f[i-1][j]+f[i-1][j-1])%k;
             
            g[i][j]=g[i-1][j]+g[i][j-1]-g[i-1][j-1]+(f[i][j]==0?1:0);//g[i-1][j]在边界上未填,但是g[i-1][j]=g[i-1][j-1]
           
        }
         
        g[i][i+1]=g[i][i];
        
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;  // 多测时取消注释
    cin>>k;
    get_c(N);
    while (T--) {
        int n,m;
        cin>>n>>m;
        //对于组合数，有效仅为m<=n;所以
        cout<<g[n][min(n,m)]<<endl;
    }
    return 0;
}
