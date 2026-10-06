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
//由于m与n都是20，需要向下和向右走19步，c_38^19,10！已经是106次方
ll grid[30][30];
void wait()
{
    int n, m; ll k;
    cin >> n >> m>> k;
    rep(i, 0, n-1)
    {
        rep(j,0,m-1)
        {
            cin >> grid[i][j];
        }
    }
    int h =min(m,n);
        //沿对角线 (0, h-1) 到 (h-1, 0) 枚举
        //对角线上共 h 个点，分别保存结果，按照行号索引
    
        vector<std::unordered_map<int64_t, int64_t>> res1(h), res2(h);
        //dfs 起点暴搜
        auto dfs1 = [&](auto&& dfs1, int i, int j, int64_t value){
            value ^= grid[i][j]; //从起点出发的话，因有对角线限制，一定不会出界
            if(i + j == h - 1){ //刚好到达对角线
                res1[i][value]++;
                return;
            }
            dfs1(dfs1,i+1, j, value);
            dfs1(dfs1,i, j+1, value);
        };
        //dfs 终点暴搜
        auto dfs2 = [&](auto&& dfs2, int i, int j, int64_t value){
            //从终点出发的话，如果表格不是正方形，那么对角线偏左上，下标可能会出界，需要先检查
            if(i < 0 or j < 0){
                return;
            }
            if(i + j == h - 1){ //刚好到达对角线
                res2[i][value]++;
                return;
            }
            //对角线上的点不要重复进行 异或计算，dfs1中已经处理了对角线上的点
            value ^= grid[i][j]; 
            dfs2(dfs2,i-1, j, value);
            dfs2(dfs2,i, j-1, value);
        };
        dfs1(dfs1,0, 0, 0);
        dfs2(dfs2,n-1, m-1, 0);
        int64_t ans = 0;
        for(int i = 0; i < h; i++){
            for(auto [val, cnt] : res1[i]){
                ans += cnt * res2[i][k ^ val];
            }
        }
        cout<< ans;
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
