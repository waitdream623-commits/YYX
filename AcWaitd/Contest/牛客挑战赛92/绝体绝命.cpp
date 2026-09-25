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
void wait()
{   
    int n;cin>>n;
    cin >>s ;
    int d,t;cin>>d>>t;
    map<PII,int>cnt;
    cnt[{0,0}]=1;
    PII a={0,0};
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='U')
        {
            a.second++;
        }
        if(s[i]=='D')
        {
            a.second--;
        }
        if(s[i]=='R')
        {
            a.first++;
        }
        if(s[i]=='L')
        {
            a.first--;
        }
    }
    //目标
    PII sce={d-a.first,t-a.second};
    
    // if(sce.first!=sce.second)
    // {
    //     cout<<0;
    //     return;
    // }
     auto [x,y]=sce;
     if((x+y)&1)//必须是偶数
     {
        cout<<0;
        return ;
     }
    a={0,0};
    //顺时针
    //需要找到：a=-(x+y)/2,b=(x-y)/2;
    int z=-(x+y)/2,q=(x-y)/2;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='U')
        {
            a.second++;
          
        }
        if(s[i]=='D')
        {
            a.second--;
        }
        if(s[i]=='R')
        {
            a.first++;
        }
        if(s[i]=='L')
        {
            a.first--;
        }
          ans+=cnt[{a.first-z,a.second-q}];
            cnt[{a.first,a.second}]++;
    }
    
      //逆时针
    //a=(y-x)/2,b=-(x+y)/2
    z=(y-x)/2,q=-(x+y)/2;
    cnt.clear();
    a={0,0};
    cnt[{0,0}]=1;
   
    for(int i=0;i<n;i++)
    {
        if(s[i]=='U')
        {
            a.second++;
          
        }
        if(s[i]=='D')
        {
            a.second--;
        }
        if(s[i]=='R')
        {
            a.first++;
        }
        if(s[i]=='L')
        {
            a.first--;
        }
          ans+=cnt[{a.first-z,a.second-q}];
            cnt[{a.first,a.second}]++;
    }
  
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
