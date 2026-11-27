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
#define lowbit(x) (x&-x)
const int N = 1e6 + 10;
int a[N],dif[N],st[N][20];
int lg[N];
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
void wait()
{
    int n,q;
    cin >> n >>q;
    rep(i,1,n)
    {
        cin >>a[i];
        dif[i] = a[i]-a[i-1];
    }
     vector<vector<int>>f(n+1,vector<int>(25));
    lg[0]=-1;//后续lg[1]=0;
    for(int i=1;i<=n;i++){
        
        f[i][0]=abs(dif[i]);
        lg[i]=lg[i>>1]+1;
    
    }
    //预处理
    for(int j=1;j<=log2(n);j++)//最长n
    {
        for(int i=1;i+(1<<j)-1<=n;i++)//i结束位置为最后一个点，长度为(1<<j);
        {
            f[i][j]=gcd(f[i][j-1],f[i+(1<<(j-1))][j-1]);//分成两部分
        }
    }
    while(q--)
    {
        int l,r;cin>>l>>r;
        l++;
        if(l>r)
        {
              cout << 0<<' ';
            continue;
        }
        if(l==r)
        {
            cout << f[l][0]<<' ';
            continue;
        }

        //找到适合区间长度
        int len=r-l+1;
        //int k=log2(len);//优化预处理
        int k=lg[len];
        int ret=gcd(f[l][k],f[r-(1<<k)+1][k]);
        cout<<ret<<" ";//不用endl，大幅度降低时间
    }
    cout << '\n';
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;  // 多测时取消注释
    while (T--) {
        wait();
    }
    return 0;
}
