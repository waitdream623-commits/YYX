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
PII cnt[N];
int pos;
void wait()
{
    memset(cnt,0,sizeof cnt);
    pos = 0;
    string s=" ";;
    string x;
    cin >> x;
    s+=x;
    int n = x.size();\
    int start = 1;
    int end = 1;
    s+=s[n]=='0'?'1':'0';
    int t = 0;
    for(int i = 1;i<=n;i++)
    {   
        if(s[i]!=s[i+1])//压缩
        {
            if((i==1&&end-start==1)||(i==n&&end-start==1))//排除首尾只有一个要加变的次数
            {
               t++;
            }
            end = i+1;
            cnt[++pos].first = s[i]-'0';
            cnt[pos].second = end - start;
            start = end; 
            
        }
    }
    int ans= 1;
    cnt[0].first = cnt[1].first;
    cnt[pos+1].first = cnt[pos].first;
//排除连续两个1的变化
    for(int i = 1;i<=pos;i++)
    {
        if(cnt[i].second>=3)
        ans++;
        else if(cnt[i].second == 1)
        {
            if(cnt[i].first!=cnt[i-1].first&&cnt[i].first!=cnt[i+1].first)
            ans++;
        }
    }
   // if(cnt[pos].second == n)ans++;
    cout <<ans<<'\n';
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
