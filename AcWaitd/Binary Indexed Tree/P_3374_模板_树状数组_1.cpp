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
#define lowbit(x) (x & -x)
const int N = 1e6 + 10;
int t[N];
int n;
void modify(int x,int k)
{
    for(int i=x;i<=n;i+=lowbit(i))
    t[i]+=k;

}
int query(int x)
{
    int sum=0;
    for(int i=x;i;i-=lowbit(i)){
        sum+=t[i];
    }
    return sum;
}
void wait()
{
    cin>>n;
    int m;cin>>m;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        modify(i,x);

    }
    while(m--)
    {
        int op,a,b;
        cin>>op>>a>>b;
        if(op==1)
        modify(a,b);
        else
        cout<<query(b)-query(a-1)<<"\n";
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
