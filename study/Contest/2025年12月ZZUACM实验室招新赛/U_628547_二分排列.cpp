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
const int N = 1e6 + 10;\
bool st[N];
int a[N];
bool b[N];//标记该位置是否被匹配过
void solve()
{
    memset(b,0,sizeof b);//清空
    int n;
    cin>>n;
    string s;
    cin>>s;
    int begin=1,end=n;
    for(int i=0;i<=n/2;i++)
    {
        if(b[i])break;
        b[i]=1;
        for(int j=n-1;j>i;j--)
        {
            if(s[j]!=s[i]&&!b[j])
            {
                a[i]=begin;++begin;
                a[j]=end;--end;
                b[j]=1;//匹配过了
                break;
            }
        }
    }
    for(int i=0;i<n;i++)cout<<a[i]<<' ';
    cout<<endl;

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;  // 多测时取消注释
    while (T--) {
        solve();
    }
    return 0;
}
