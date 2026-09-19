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
int sg[110][110];
bool vis[120];
void get_sg()
{
    for(int i=0;i<=100;i++)
    {
        for(int j=0;j<=100;++j)
        {
            memset(vis,0,sizeof vis);
            if(i>=2)vis[sg[i-2][j+1]]=1;
            if(j>=2)vis[sg[i+1][j-2]]=1;
            int g=0;
            while(vis[g])g++;
            sg[i][j]=g;
        }
    }
  
}
const int SZ=300;
int sgOk[SZ][SZ];
void get_sg_ok() {
    for (int s = 0; s <= 400; ++s)
        for (int i = 0; i <= 200; ++i) {
            int j = s - i;
            if (j < 0 || j > 200) continue;
            memset(vis, 0, sizeof vis);
            if (i >= 2 && j + 1 <= 200) vis[sgOk[i - 2][j + 1]] = 1;
            if (j >= 2 && i + 1 <= 200) vis[sgOk[i + 1][j - 2]] = 1;
            int g = 0;
            while (vis[g]) g++;
            sgOk[i][j] = g;
        }
              for(int i=0;i<=15;i++)
    {  for(int j=0;j<=15;j++)
        cout<<sgOk[i][j];
    cout<<endl;}
}

void wait()
{
    int a,b;
    cin>>a>>b;
    int x=abs(a-b);
    if(x % 6 == 0 || x% 6 == 1 || x% 6 == 5)
    {
        cout<<"Bob\n";
    }
    else
    cout<<"Alice\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
   // cin >> T;  // 多测时取消注释
    while (T--) {
        get_sg_ok();
        //wait();
    }
    return 0;
}
