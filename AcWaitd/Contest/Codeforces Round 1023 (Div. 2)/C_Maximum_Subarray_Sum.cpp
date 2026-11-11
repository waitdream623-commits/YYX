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
    ll n,k;cin >> n >> k;
    string s ;cin >> s;
    vector<ll>a(n+3,0);
    int cnt = 0;
    rep(i,1,n)
    {
        if(s[i-1]=='0')
        {
            cin >> a[i];
            a[i] = -1e18;
            cnt ++;
        }
        else
        {
            cin >> a[i];
        }
    }
    //左右最大子数组和
    vector<ll> pre(n+1,0),suf(n+2,0);
    ll sum =0 ;
    ll omax = 0;
    rep(i,1,n)
    {
        pre[i] = max(a[i],sum+a[i]);
        sum = pre[i];
        omax = max(omax,sum);
    }
    sum = 0;
    for(int i = n;i>0;i--)
    {
        suf[i] = max(a[i],sum + a[i]);
        sum = suf[i];
    }
    if(omax > k)
    {
        cout << "No\n";
    }
    else 
    {
        
        if(omax == k)
        {
            cout << "Yes\n";
            rep(i,1,n)
            {
                cout << a[i]<<' ';
            }
        }
        else if(cnt >0)
        {
            cout << "Yes\n";

            //找到第一个0，看前后缀子数组，再看x改为多少
            int i = 1;
            while(i<=n&&s[i-1]!='0')//此处写错，
            i++;

            ll left = pre[i-1];
            ll right = suf[i+1];
            if(left<0)
            left = 0;
            if(right<0)
            right = 0;
            a[i] = k - left-right;
            rep(i,1,n)cout << a[i] << ' ';

        }
        else
        {
            cout << "No";
        }
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
