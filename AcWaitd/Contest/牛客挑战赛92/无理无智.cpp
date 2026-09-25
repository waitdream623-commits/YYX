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
const int N = 2e5 + 10;
bool a[N][N];
void wait()
{
    int n,m;
    cin>> n >>m;
    rep(i,1,n)
    rep(j,1,m)
    {
        cin>>a[i][j];

    }
    bool flag1=0;
    bool flag2=0;
    //找1
    bool b[N][N];
    memcpy(b,a,sizeof a);
    rep(i,1,n)
    {
        rep(j,1,m)
    {
       if(a[i][j])//找到一列
       {
        flag1=1;//表示该点可能被行删除
        a[i][j]=0;
        for(int k=i+1;k<=n;k++)
        {
            if(a[k][j])//大于1，必须选这列
            {
                flag2=1;
                flag1=0;
                a[k][j]=0;//全部修改，之后找行
            }
        }
        break;
       }

    }
    if(flag2)
    break;
   //没找到必须删的列，表示，该点可以由行删除，那么结果为列
    }
    int cnt=0;
    rep(i,1,n)
    rep(j,1,m)
    {
       if(a[i][j])
       {
        cnt++;
        break;//看有几层；
       }

    }
    if(cnt==0&&!flag1)
    {
        cout<<n;
        return;
    }
    else if(flag1)
    {
        cout<<m;
        return;
    }
    // else
    // {
    //     //找0
    //     flag=0;
    // rep(i,1,n)
    // {
    //     rep(j,1,m)
    // {
    //    if(a[i][j]==0)
    //    {
    //     a[i][j]=1;
    //     for(int k=i+1;k<=n;k++)
    //     {
    //         if(!a[k][j])
    //         {
    //             flag=1;
    //             a[k][j]=1;
    //         }
    //     }
    //     break;
    //    }

    // }
    // if(flag)
    // break;
    // }
    // int cnt=0;
    // rep(i,1,n)
    // rep(j,1,m)
    // {
    //    if(!a[i][j])
    //    {
    //     cnt++;
    //     break;//看有几层；
    //    }

    // }
    // if(cnt==0)
    // {
    //     cout<<n;
    //     return;
    // }
    // else 
    // {
    //     cout<<0;
    //     return;
    // }
    // }
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
