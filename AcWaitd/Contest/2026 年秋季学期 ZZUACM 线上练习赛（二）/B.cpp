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
int a[28];
void wait()
{
    int n , l ,r;
    cin >>  n >> l>>r;
    string s;cin >> s;
    if(26*l>n||26*r<n)
    {
        cout << -1<<'\n';
        return;
    }
    memset(a,0,sizeof a);
    ll cnt = 0;
    for(auto e:s)
    {
        if(e=='?')cnt++;
        else
        {
            a[e-'a']++;
            if(a[e-'a']>r)
            {
                cout << -1 <<'\n';
                return;
            }
        }
    }
    ll need = 0;
    rep(j,0,25)
    {
        need += max(0, l-a[j]);
    }

    if(need > cnt)
    {
        cout << -1 << '\n';
        return;
    }
    int i ='a'-'a';
    for(auto e:s)
    {
        if(e=='?')
        {
            while(i<='z'-'a'&&a[i]>=l)i++;//满足最低要求
            if(i>'z'-'a')//要求都满足
            {
                i = 0;
                while(i<='z'-'a'&&a[i]==r)
                {
                   i++;
                }
                if(i>'z'-'a')//不够
                {
                    cout << -1;
                    return;
                }
                a[i]++;
                cout << (char)(i+'a');
            }
            else
            {
                a[i]++;
                cout << (char)(i+'a');
            }
        }
        else
        cout <<e;
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
