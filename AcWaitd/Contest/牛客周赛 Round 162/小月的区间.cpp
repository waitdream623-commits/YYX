#include <bits/stdc++.h>
using namespace std;
#ifndef DEBUG
struct __X {
  __X& operator<<(const auto& str) {return *this;}
  void sp(const string& str = "") {}
} dout;
#define debug(x)
#endif
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
#define rep(i,m,n) for(int i=m;i<=n;++i)
#define lc p<<1
#define rc p<<1|1
const int N = 1e6 + 10;
int lg[N];
int f[N][30];
int g[N][30];
int cacumax(int l, int r)
{
        //找到适合区间长度
        int len=r-l+1;
        //int k = log2(len);//浮点写法，不推荐，直接用 lg 表
        int k=lg[len];
        int ret=max(f[l][k],f[r-(1<<k)+1][k]);
        return ret;
}
int cacumin(int l, int r)
{
        //找到适合区间长度
        int len=r-l+1;
        //int k = log2(len);//浮点写法，不推荐，直接用 lg 表
        int k=lg[len];
        int ret=min(g[l][k],g[r-(1<<k)+1][k]);
        return ret;
}
void wait()
{
    
    int n;cin>>n;
    lg[0]=-1;
    for(int i=1;i<=n;i++){
        
        cin>>f[i][0];
        g[i][0]=f[i][0];
        lg[i]=lg[i>>1]+1;//预处理log实现查询O(1);
    
    }
    //预处理
    for(int j=1;j<=lg[n];j++)//最长 n；j 上界 = floor(log2(n))，用 lg 表避开浮点 log2
    {
        for(int i=1;i+(1<<j)-1<=n;i++)//i 为起点，块长 2^j，块尾 i+2^j-1 不能超过 n
        {
            f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);//分成两部分
            g[i][j]=min(g[i][j-1],g[i+(1<<(j-1))][j-1]);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        // for(int j=n;j>=i;j--)
        // {
        //     int l=0;
        //     if(i==1)l=0;
        //     else
        //     l=cacumax(1,i-1);
        //     int midmin=cacumin(i,j);
        //     int midmax=cacumax(i,j);
        //     int r=0;
        //     if(j==n)r=1e9;
        //     else
        //      r=cacumin(j+1,n);
        //     if(l<midmax&&r>midmin)
        //     ans++;
        // }
        //二分
         int l=0;
        if(i==1)l=0;
        else
        l=cacumax(1,i-1);
        int left=i,right=n;
        while(left<right)
        {
            int mid=(left+right)>>1;
            int midmin=cacumin(i,mid);
        int midmax=cacumax(i,mid);
        int r=1e9;
        if(mid!=n)r=cacumin(mid+1,n);
        if(l<midmax&&r>midmin)
        right=mid;
        else
        left=mid+1;

        }
        //left可能不匹配

        int midmin=cacumin(i,left);
        int midmax=cacumax(i,left);
        int r=1e9;
       if(left!=n)
        r=cacumin(left+1,n);
        if(l<midmax&&r>midmin)
        ans+=n-left+1;
    }
       
   cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;  // 多测时取消注释
    while (T--) {
        wait();
    }
    return 0;
}
