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
int sg[N];
void getsg()
{
    sg[1]=0;
    for(int i=2;i<=1000;i++)
    {
        vector<bool>vis(1000,0);
        for(int j=1;j<i;j++)//可能性
        {
            if(i%j==0)
            {
                vis[sg[i-j]]=1;
            }
            
        }
        for(int k=0;k<=1000;k++)
            {
                if(!vis[k])
                {
                    sg[i]=k;
                    break;
                }
            }
    }
}
void wait()
{
    for(int i=1;i<=100;i++)
    cout<<sg[i]<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;  // 多测时取消注释
    while (T--) {
        getsg();
        wait();
    }
    return 0;
}
