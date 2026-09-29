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
//区间修改差分数组
int a[N];
int n;
void modify(int x,int v)
{
    while(x<=n)
    {
        a[x]+=v;
        x+=lowbit(x);
    }
}
int query(int x)
{
    int ret=0;
    while(x>0)
    {
        ret+=a[x];
        x-=lowbit(x);
    }
    return ret;
}
void wait()
{
    cin>>n;
    int m;cin>>m;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        modify(i,x);
        modify(i+1,-x);

    }
    while(m--)
    {
        int op,x;
        cin >> op >> x;
        if(op==1)
        {
            int y;cin>>y;
            int v;cin>>v;
            modify(x,v);
            modify(y+1,-v);
        }
        else
        {
            cout<<query(x)<<'\n';
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
