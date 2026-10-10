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
class Solution {
public:
    bool vis[40][40][1<<6];
    int shortestPathAllKeys(vector<string>& grid) {
        //多了一层需要维护钥匙状态
        //相同状态去重
        //使用bfs即可
        //(维护坐标，钥匙状态)队列，距离，vis去重
        queue<array<int,3>>q;
        int n = grid.size(), m = grid[0].size();
        //计算钥匙个数
        int k =0;
        int sx = 0 ,sy = 0;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j< m; ++j)
            {
                if(grid[i][j] >= 'a' && grid[i][j] <= 'f')k++;
                if(grid[i][j] == '@')
                {
                    sx = i;
                    sy = j;
                }
            }
        }
        q.push({sx,sy,0});

        vis[sx][sy][0] = 1;
        int a[] = {-1, 0, 1, 0, -1};
        int level = 0;
        while(q.size())
        {
           int s =q.size();
           level ++;
            while(s--)
            {
                 array<int,3> e = q.front();
                q.pop();
                for(int i = 0; i < 4; ++i)
                {
                    int nw = e[2];//先继承上一步钥匙数据
                    int nx = e[0] + a[i], ny = e[1] + a[i + 1];
                    if(nx < 0|| ny < 0 || ny > m-1 || nx > n-1 || grid[nx][ny] == '#'||vis[nx][ny][nw])continue;
                    //处理数据
                    //是钥匙
                    if(grid[nx][ny] >= 'a' && grid[nx][ny] <= 'f')
                    {

                        nw = e[2] | (1<<(grid[nx][ny]-'a'));
                    
                        //先找有几个钥匙，决定返回条件
                        int t = nw;
                        int cnt = 0;
                        while(t)
                        {
                            if(t & 1)
                            cnt++;
                            t>>=1;
                        }
                        if(cnt == k)return level;
                        if(vis[nx][ny][nw])continue;
                        vis[nx][ny][nw] = 1;
                        q.push({nx,ny,nw});
                        //cout << nx << ' '<<ny <<' '<<nw<<' '<<endl;

                    }
                    else if(grid[nx][ny] >= 'A' && grid[nx][ny] <= 'F')
                    {
                        //找有没有钥匙
                        if((nw & (1<<(grid[nx][ny] - 'A'))) == 1)
                        {
                            vis[nx][ny][nw] = 1;
                            q.push({nx,ny,nw});

                        }
                        else
                        continue;
                    }
                    else
                    {
                        vis[nx][ny][nw] = 1;
                        q.push({nx,ny,nw});
                    }

                } 
            }
        }
        return -1;

    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;  // 多测时取消注释
    while (T--) {
       vector<string> grid;
       grid.push_back ("@fedcbBCDEFaA");
       Solution s;
       s.shortestPathAllKeys(grid);
    }
    return 0;
}
