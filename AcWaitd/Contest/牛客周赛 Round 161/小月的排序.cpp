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
int cacu(int x)
{
    int r=0;
    if(x==0)return 0;
    while(x)
    {
        if(x&1)
        r++;

        x>>=1;
    }
    return r;
}
int cacu2(int x)
{
      int r=0;
    if(x==0)return 31;
    while(x)
    {
        r++;
        if(x&1)
        {
        return r;}

        x>>=1;
    }
    return r;
}
bool cmp(int a,int b)
{
    
    int ai=cacu(a);
    int bi=cacu(b);
    if(ai!=bi)
    {
        return ai<bi;
    }
    else
    {
        int ax=cacu2(a);
        int bx=cacu2(b);
        if(ax!=bx)
        return ax<bx;
        else
        {
            return a<b;
        }
    }
}
int a[N];
void wait()
{
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    cout<<a[k];
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
