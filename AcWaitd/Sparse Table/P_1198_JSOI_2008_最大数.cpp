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
ll f[N][25];
void wait()
{
    int m,d;
    cin>>m>>d;
    int tmp=0;//记录上一次查询结果
    int end=0;//数组位置
    while(m--)
    {
        char op; cin>>op;
        if(op=='A')
        {
            ll x;cin>>x;
            x=(x+tmp)%d;
            f[++end][0]=x;
            for(int j=1;j<=log2(end);j++)
            {
           
            //每次更新，只需要更新一个，end-(1<<j)+1位置涉及最后一个点
            f[end-(1<<j)+1][j]=max(f[end-(1<<j)+1][j-1],f[end-(1<<j)+1+(1<<(j-1))][j-1]);
                
            }
            
        }
        else
        {
            int L;cin>>L;
            int r=end,l=end-L+1;
            if(r<1)r=1;
            int k=log2(L);
            tmp=max(f[l][k],f[r-(1<<k)+1][k]);
            cout<<tmp<<"\n";
        }
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
