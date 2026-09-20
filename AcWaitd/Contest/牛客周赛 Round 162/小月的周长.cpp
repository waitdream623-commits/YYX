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
void wait()
{
    int n,m , x, y;
    cin >>n>>m>>x>>y;
    if(n==1||m==1){
        cout<<0<<'\n';return;
    }
    int c=2*(n+m);
    
    if((x==1||x==n)&&(y!=1&&y!=m))
    {
        c+=2*n-6;
    }
    else if((y==1||y==m)&&(x!=1&&x!=n))
    c+=2*m-6;
    else if((y==1||y==m)&&(x==1||x==n))
    c-=4;
    else
    c+=2*m+2*n-8;

    
    
    cout<< c<<'\n';
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
