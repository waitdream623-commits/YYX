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
    int n ,m;cin >> n >> m;
    vector<vector<int>>a(n+1,vector<int>(m+1,0));
    //统计最大值出现位置，
    vector<int>col(m+1,0);
    int mx = 0;
    rep(i,1,n)
    rep(j,1,m)
    {
        cin>>a[i][j];
       mx = max(mx,a[i][j]);
    }
    vector<PII>pos;
    map<int,int>mpx,mpy;
    int m1=0,m2=0;
    int x = 0 , y = 0;//判断交点是否是max
     rep(i,1,m)
    rep(j,1,n)
    {
       
        if(a[j][i] == mx)
        {
            pos.push_back({j,i});
            
            mpx[j]++;
            mpy[i]++;
            if(m1<=mpx[j])//(1,2)(2,1),应该选1，2，或者2，1，不能选1，1，（1，1）（2，2）呢，该选1，2
            {
                x = j;
            }
            if(m2<=mpy[i])
            {
                y = i;
            }
            m1= max(m1,mpx[j]);
            m2= max(m2,mpy[i]);

        }
    }
// // 3 2
// // 1 2
// // 2 1
// // 1 2
// //对于横坐标，1，2，3，不知道选谁，只有选2才正确，选1，3会剔除一部分，此时只会是1，如果大于2，说明不行
//     if(pos.size()==2)//
//     {
//         x = pos[0].first,y= pos[1].second;
//     }
//     //找最大值点能否由两条线包含
//     //找x，排序，相同的标记，
//     //最大的相加是否等于点数，重复的怎么办最多一个，，此时相加大于size;
//     if((m1!=1&&m2!=1)&&a[x][y] == mx)//重复计算
//     {
//         m1--;
//     }
//     //pos = 1;必然为1
//     if(pos.size()==1)
//     {
//         m1--;
//     }
//     if(m1+m2==pos.size())
//     {
//         cout << mx-1<<'\n';
//     }
//     else
//     cout << mx << '\n';
if(pos.size()<=2)
{
    cout << mx -1<<'\n';
    return;
}
 map<PII,bool> vis;
 if(m1==m2&&m1==1)
 {
    if(pos.size()==1)
    {
        cout << mx - 1<<'\n';
    }
    else
    cout << mx <<'\n';

    return ;
 }

 if(m1!=1&&m2==1)//有多个相同m2
 {
    int cnt = 0;
    for(auto [t,k]:pos)
    {
        if(t==x)
        {
            vis[{t,k}] = 1;
            cnt ++ ;
        }
    }
    if(pos.size()==cnt||pos.size()-1==cnt)
    {
        cout << mx - 1<<'\n';
    }
    else
    cout << mx <<'\n';
 }
 else if(m2!=1&&m1==1)
  {
    int cnt = 0;
    for(auto [t,k]:pos)
    {
        if(k == y)
        {
            vis[{t,k}] = 1;
            cnt ++ ;
        }
    }
    if(pos.size()==cnt||pos.size()-1==cnt)
    {
        cout << mx - 1<<'\n';
    }
    else
    cout << mx <<'\n';
 }
 else
 {
        if((m1!=1&&m2!=1)&&a[x][y] == mx)//重复计算
    {
        m1--;
    }
   
    if(m1+m2==pos.size())
    {
        cout << mx-1<<'\n';
    }
    else
    cout << mx << '\n';
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
