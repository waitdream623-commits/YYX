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
const int N = 1e6 + 10;
string s;
string tmp;
// void wait()
// {
//     int n;cin>>n;
    
//     cin>>s;
//     string tt;
//     rep(i,1,n)
//     cin>>tt[i];
//    rep(i,1,n)
//     {
//          tmp=s;
//         reverse(s.begin(),s.end());
//         s=tmp+tt[i]+s;
        

//     }
//     int ans=0;
//     for(int i=1;i<s.size();i++)
//     {
//         if(s[i]==s[i-1])ans++;
//     }
//     cout<<ans;
// }
void wait()
{
    int n;cin>>n;
    
    cin>>s;
    string tt;
    tt.resize(n+1);//需要扩容
    rep(i,1,n)
    cin>>tt[i];
    ll ans=0;
    //题意只有一个字符
//     int k=s.size();
//     //初始长度中相同字符
//     for(int i=1;i<k;i++)
//     {
//         if(s[i]==s[i-1])ans++;
//     }
//     //当长度不为1，且首与尾不相同//特殊处理第一步
//     if(n>=1)
//     {
//         if(tt[1]==s[k-1])//长度不止为1
//         ans=ans*2+2;
//         else
//         ans*=2;

//     }
   rep(i,1,n)
    {
        //  tmp=s;
        // reverse(s.begin(),s.end());
        // s=tmp+tt[i]+s;
        if(tt[i]==s[0])//长度不止为1
        ans=ans*2+2;
        else
        ans*=2;

    }
    // int ans=0;
    // for(int i=1;i<s.size();i++)
    // {
    //     if(s[i]==s[i-1])ans++;
    // }
    cout<<ans;
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
