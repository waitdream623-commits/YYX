#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
#define lc p<<1
#define rc p<<1|1
const int N = 1e6 + 10;
void solve()
{
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;  // 多测时取消注释
    while (T--) {
        solve();
    }
    return 0;
}

//过70分
// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// typedef unsigned long long ull;
// typedef pair<int,int>PII;
// int INF=0x3f3f3f3f;
// #define lc p<<1
// #define rc p<<1|1
// const int N = 1e6 + 10;
// int a[60][60],b[60][60];
// vector<PII>m1,m2;//标记该连通块是否与边界相连
// //记录该连通块是否有边界，只有有边界就能与另一个有边界相连
// vector<pair<int,int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
// int ret;
// int flag;
// int n;
// bool vis1[60][60];bool vis2[60][60];
// void dfs(int x,int y,int t[][60],bool v[][60])
// {
//     v[x][y]=1;//必须
//     ret++;
//     for(auto [dx,dy]:dir)
//     {
//         int nx=x+dx,ny=y+dy;
//         if(nx<1||ny<1||nx>n||ny>n)continue;
//         if(nx==1||nx==n||ny==1||ny==n)flag=1;
//         if(t[nx][ny]==0||v[nx][ny])continue;
//         dfs(nx,ny,t,v);
//     }
// }
// void solve()
// {
//     cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=n;j++)cin>>a[i][j];
//     }
//      for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=n;j++)cin>>b[i][j];
//     }

//      //标记是否可以连接
//     bool f1=0,f2=0;
//      int ans=0;
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=n;j++)
//         {
//             if(a[i][j]==1)
//             {
//                 if(!vis1[i][j])
//                 {
//                     dfs(i,j,a,vis1);
//                     m1.push_back({ret,flag});
//                     if(flag)f1=1;
//                     ans=max(ans,ret);
//                     ret=0,flag=0;
//                 }
//             }
//         }
//     }
   
//        for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=n;j++)
//         {
//             if(b[i][j]==1)
//             {
//                 if(!vis2[i][j])
//                 {
//                     dfs(i,j,b,vis2);
//                     m2.push_back({ret,flag});
//                     if(flag)f2=1;
//                     ans=max(ans,ret);

//                     ret=0,flag=0;
//                 }
//             }
//         }
//     }
//    if(f1&&f2)
//     for(auto e:m1)
//     {
//         for(auto y:m2)
//         {
//             if(e.second&&y.second)
//             ans=max(ans,e.first+y.first);//可能同时连接多个连通块
//         }
//     }
//     cout<<ans;
// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin >> T;  // 多测时取消注释
//     while (T--) {
//         solve();
//     }
//     return 0;
// }
