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
int mask[110][110];
int dx[] = {1,0,-1,0,1};

// void wait()
// {
//     int n,m,x,y;
//     cin >> n >> m >> x >>y;
//     rep(i,1,n)
//     {
//         rep(j,1,m)mask[i][j] = 0;
//     }
//     queue<PII>q;
//     q.push({x,y});
//     while(q.size())
//     {
//         auto [a,b] = q.front();
//         q.pop();
//         mask[a][b]=5;//探索过了，防止回退
//         for(int i = 0;i<=3;i++)
//         {
//             int nx = a+ dx[i] ,ny = b+dx[i+1];
//             if(nx>n||nx<1||ny>m||ny<1)continue;
//             if(mask[nx][ny]<=3)//未上锁或者，未探索
//             {
//                 if(dx[i]!=0)
//                 {
//                     if(dx[i] == 1)
//                     {
//                         cout << "D"<<endl;
//                     }
//                     else
//                     cout << "U"<<endl;
//                 }
//                 else
//                 {
                    
//                     if(dx[i+1] == 1)
//                     {
//                         cout << "R"<<endl;
//                     }
//                     else
//                     cout << "L"<<endl;
//                 }
//                 int x;
//                 while(!(cin>>x)||x==-1)return;
//                 if(x == 0)
//                 {
//                     mask[nx][ny]++;//墙与房间关系，可能通过另一道门进来
//                 }
//                 else
//                 {
//                     q.push({nx,ny});//继续探索
//                 }
//             }
//         }

//     }
//     cout << "!"<<'\n';
// }
//每一步询问后，人就在询问后位置
void wait()
{
    int n,m,x,y;
    cin >> n >> m >> x >> y;

    rep(i,1,n)
    {
        rep(j,1,m)mask[i][j] = 0;
    }
    auto ask = [&](int i) -> int
    {
        if(dx[i] != 0)
        {
            if(dx[i] == 1)cout << "D" << endl;
            else cout << "U" << endl;
        }
        else
        {
            if(dx[i+1] == 1)cout << "R" << endl;
            else cout << "L" << endl;
        }

        int x;
        if(!(cin >>x)||x == -1)exit(0);
        return x;
    };

    auto dfs = [&](auto&& dfs, int a, int b) -> void
    {
        mask[a][b] = 1;

        for(int i = 0; i<= 3;i++)
        {
            int nx = a + dx[i], ny = b + dx[i+1];
            if(nx>n||nx<1||ny>m ||ny<1)continue;
            if(mask[nx][ny])continue;

            int reply = ask(i);
            if(reply == 1)
            {
                dfs(dfs, nx, ny);  
                ask((i+2)%4);//回退
            }
        }
    };

    dfs(dfs,x,y);
    cout << "!" << endl;
}
int main() {
    ios::sync_with_stdio(false);
    //cin.tie(nullptr);

    int T = 1;
    // cin >> T;  // 多测时取消注释
    while (T--) {
        wait();
    }
    return 0;
}
