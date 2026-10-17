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
string st[4][2] = {{"VOY","HUA"},{"HUA","VOY"},{"VOY","HUA"}};
int flag[3][2] = {{1,0},{1,1},{0,1}};
int t[2] = {0,0};//记录上一次x,y;
    int T = 0;
bool fg=0;
void wait()
{
    string a,b;
    int f1,f2,x,y;
    cin >> a >> b>>f1>>f2>>x >> y;
  //   int i = 0;
  //   while (i<a.size())
  // {
  //   a[i]=toupper(a[i]);
  //   i++;
  // }
  //   i = 0;
  //     while (i<b.size())
  // {
  //   b[i]=toupper(b[i]);
  //   i++;
  // }

  if(st[T-1][0]!=a||st[T-1][1]!=b||flag[T-1][0]!=f1||flag[T-1][1]!=f2)
  {
        fg=1;
  }
  if(T==1)
  {
    if(y!=0)
    {
        fg=1;
    }
    t[0] = x,t[1] = y;
  }
  else if(T==2)
  {
    if(y!=t[0]+1)
    {
            fg=1;
    }
        t[0] = x,t[1] = y;
  }
  else
  {
    if(x!=t[1]||y!=t[0]+1){ 
      
      fg=1;
    }
    
        if(fg)
        {
            cout << "NO";

        }
        else
        cout << "YES";
    
  }
     


}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // cin >> T;  // 多测时取消注释
    while (T<3) {
        T++;
        wait();
    }
    return 0;
}
