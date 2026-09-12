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
#define lc p<<1
#define rc p<<1|1
const int N = 1e6 + 10;
int lg[N];
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

void wait()
{
    int n,m;cin>>n>>m;
    vector<vector<int>>f(n+1,vector<int>(25));
    lg[0]=-1;//后续lg[1]=0;
    for(int i=1;i<=n;i++){
        
        cin>>f[i][0];
        lg[i]=lg[i>>1]+1;
    
    }
    //预处理
    for(int j=1;j<=log2(n);j++)//最长n
    {
        for(int i=1;i+(1<<j)-1<=n;i++)//i结束位置为最后一个点，长度为(1<<j);
        {
            f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);//分成两部分
        }
    }
    while(m--)
    {
        int l,r;cin>>l>>r;
        //找到适合区间长度
        int len=r-l+1;
        //int k=log2(len);//优化预处理
        int k=lg[len];
        int ret=max(f[l][k],f[r-(1<<k)+1][k]);
        cout<<ret<<"\n";//不用endl，大幅度降低时间
    }
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
