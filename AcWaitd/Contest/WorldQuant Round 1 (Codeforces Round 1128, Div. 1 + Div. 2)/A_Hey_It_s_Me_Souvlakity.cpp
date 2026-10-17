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
void wait()
{
    int n;cin >> n;
    string s;cin >> s;
    int l=0,r=0;
    //如果只要
    int cnt=0;
    for(int i = 0;i<s.size();i++)
    {
        if(s[i]=='1')cnt++;
        if(s[i]=='1'&&!l)
        {
            l = i+1;
        }
        else if(s[i]=='1')
        {
            r=max(i+1,r);
        }
    }
    if(r==0)r=l;
    if(cnt==2)
    {
        if(s[r-2]=='0')
        {
            cout << 1<<'\n';
            return;
        }
    }
    cout << r-l<<"\n";
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
