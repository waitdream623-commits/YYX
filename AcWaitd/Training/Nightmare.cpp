#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;

int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
int maze[110][110];
int sx,sy;
vector<pair<int,int >>dir={{1,0},{-1,0},{0,1},{0,-1}};
int dist[110][110][8];
int n,m;

int bfs()
{
    // 重置状态
    memset(dist, -1, sizeof dist);
    
    queue<tuple<int,int,int>> q;
    dist[sx][sy][6] = 0; 
    q.emplace(sx, sy, 6);
    
    while(q.size())
    {
        auto e = q.front(); q.pop();
        int x = get<0>(e);
        int y = get<1>(e);
        int k = get<2>(e);
        int step = dist[x][y][k];
        
        // 【标准终点判定】：只要活着出队且是终点，直接返回步数
        if(maze[x][y] == 3) return step;

        for(auto [dx,dy] : dir)
        {
            int nx = x + dx, ny = y + dy;
            // 1. 越界检查
            if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
            // 2. 撞墙检查
            if(maze[nx][ny] == 0) continue;
            
            int nk = k - 1;
            
            // 【硬核防线 1】：移动后时间归零，直接在边缘拦截，死人绝不入队
            if(nk <= 0) continue;
            
            // 【硬核防线 2】：只有活着走到炸弹点，才能合法重置时间
            if(maze[nx][ny] == 4) {
                nk = 6;
            }
            
            // 3. 状态查重检查
            if(dist[nx][ny][nk] != -1) continue; 
            
            dist[nx][ny][nk] = step + 1;
            q.emplace(nx, ny, nk);
        }
    }
    return -1;
}

void solve()
{
    if (!(cin >> n >> m)) return;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> maze[i][j];
            if(maze[i][j] == 2)
            {
                sx = i, sy = j;
            }
        }
    }
    cout << bfs() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}