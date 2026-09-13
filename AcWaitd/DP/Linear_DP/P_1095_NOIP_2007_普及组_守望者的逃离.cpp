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
// int tmin=0x3f3f3f3f,sm=0;
// int m,s,t;
// void dfs(int a,int b,int c)
// {
//     if(b>=s)
//     {
//         tmin=min(tmin,c);
//        return;
//     }
//     if(c>=t)//等于时候判断
//     {
//         sm=max(sm,b);
//         return;
//     }
//     if(a>=10)
//     {
//         dfs(a-10,b+60,c+1);

//     }
//     dfs(a,b+17,c+1);//走一步
//     dfs(a+4,b,c+1);//不走
// }
// void wait()
// {
    
//     cin>>m>>s>>t;
//     dfs(m,0,0);
//     if(tmin!=0x3f3f3f3f)
//     {
//         cout<<"Yes\n";
//         cout<<tmin;
//     }
//     else
//     {
//         cout<<"No\n";
//         cout<<sm;
//     }
// }
int d[N];//表示时间t运动距离
void wait()
{
    int m,s,t;cin>>m>>s>>t;
    int z;
    for(int i=1;i<=t;i++)
    {
        if(m>=10)d[i]=d[i-1]+60;
        else
        d[i]=d[i-1];
        z=m;
        m -= (10 * (z >= 10));   //省去判断
        m += (4 * (z < 10));    //省去判断

    }
    for(int i=1;i<=t;i++)
    {
        d[i]=max(d[i],d[i-1]+17);
        if(d[i]>=s)
        {
            cout<<"Yes\n";
            cout<<i;
            return;
        }

    }
    cout<<"No\n";
    cout<<d[t];
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
