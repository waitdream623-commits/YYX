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
    int n;
    cin >> n;
    string s;cin >> s;
    vector<int>one,ze;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0')
        ze.push_back(i);
        else
        {
            one.push_back(i);
        }
    }
    if(n%2==0)
    {
        if(ze.size()==one.size())
        {
            int i =1,j=2;
            for(auto e:s)
            {
                if(e=='0')
                {
                    cout << i<<' ';
                    i+=2;
                }
                else
                {
                    cout << j<<' ';
                    j+=2;
                }
            }
        }
        else
        cout << -1 ;
        cout << '\n';
    }
    else
    {
        if(ze.size()==one.size()+1)
        {
            int i =1,j=2;
            for(auto e:s)
            {
                if(e=='0')
                {
                    cout << i<<' ';
                    i+=2;
                }
                else
                {
                    cout << j<<' ';
                    j+=2;
                }
            }
        }
        else
        cout << -1 ;
        cout << '\n';
    }
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
