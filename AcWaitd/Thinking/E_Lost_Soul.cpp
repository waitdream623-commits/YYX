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
int a[N],b[N];
void wait()
{
    int n;cin >> n;
    rep(i,1,n)
    {
        cin >> a[i];
    }
    rep(i,1,n)
    {
        cin >> b[i];
    }
    //逆序遍历找到最近位置

    map<int,int>mp1,mp2;
    for(int i = n;i>0;i--)
    {
        int t1 = a[i],t2= b[i];
        if(mp1.count(t1)||mp2.count(t2)||t1==t2)
        {
            cout << i << '\n';
            return ;
        }
        if((mp2.count(t1)&&mp2[t1]-i!=1)||(mp1.count(t2)&&mp1[t2]-i!=1))//异边不能距离差等于1
        {
            cout << i << '\n';
            return ;
        }
        mp1[t1]=i;
        mp2[t2]=i;

    }
    cout << 0 <<'\n';
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
