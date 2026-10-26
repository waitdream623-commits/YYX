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
vector<int>group[65];
bool king[N];
int fans[N];
int cost[N];
int val[N];

void wait()
{
    int n,m;
    cin >> n >> m;
    rep(i,1,m)
    {
        int c;
        cin >> cost[i] >> val[i] >> c;
        if(c==0)
        {
            king[i] = 1;//标记是否为主件
        }
        else
        {
            fans[c]++;//记录大小
            group[c].push_back(i);//加入组别
        }
    }
    //分组处理cost与val
    vector<vector<PII>>f(m+1);
int pos = 0;

    rep(i,1,m)
    {
        if(king[i])
        {
            for(int k = 0;k<(1<<fans[i]);k++)//枚举
            {
                ll co = cost[i],va = val[i]*co;//主件
                rep(j,0,fans[i]-1)
                {
                    if(k>>j&1)
                    {
                        co += cost[group[i][j]];
                        va +=cost[group[i][j]]*val[group[i][j]];
                    }
                }
                //一种情况，
                f[pos].push_back({co,va});
            }
            pos++;
        }
    }
    vector<int> dp(n+1,0);
    for(auto e:f)//e为其中一组
    {
        for(int i = n;i>=0;i--)
        {
            for(auto [co,va]:e)//在一组中选一个
            {
                if(i>=co)
                {
                    dp[i] = max(dp[i],dp[i-co]+va);
                }
            }
        }
    }
    cout << dp[n];
    
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
