#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
vector<int>edge[N];
int f[N];//记忆化,记得初始化
int sg(int u)
{
    if(f[u]!=-1) return f[u];
    //向下递归，递归到最底
    unordered_set<int>st;
    for(auto&e:edge[u])
    {
        st.insert(sg(e));
    }
    //mex运算
    for(int i=0;i<=N;i++)
    {
        if(st.count(i)==0)
        {
            return f[u]=i;
        }
    }
    return -1;//完整返回路径
}
void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)f[i]=-1;
    for(int i=1;i<=m;i++)
    {
        int x,y;cin>>x>>y;
        edge[x].push_back(y);

    }
    int ret=0;
    for(int i=1;i<=k;i++)
    {
        int t;cin>>t;
        ret^=sg(t);
    }
    if(ret)
    {
        cout<<"win";
    }
    else
    cout<<"lose";
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
