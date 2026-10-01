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
//不能用线段树，因为不是区间修改，而是没放方块的改颜色
//记录每个点最后状态，倒着处理，如果遇到2操作，且最终状态是无方块直接去掉该点，遇到方块操作，改变状态，直到所有点修改完毕
//如何记录点，将其加入set?
set<int>st;//记录还需要操作点

//记录操作

const int N = 1e6 + 10;
PII q[N];
void wait()
{
    int n, m;cin >> n>>m;
    vector<bool>has(n+1,0);//记录状态
    vector<bool> done(n + 1, false);//记录该点处理完毕，不需要加入st
    vector<char>ans(n+1,'a');//记录颜色；
    vector<PII>qu(m+1,{0,0});//记录操作
    //rep(i,1,n)st.insert(i);//不用全部加入，加入需要修改的点
    for(int i=1;i<=m;i++)
    {
        int o; cin >> o;
        if (o == 1) { int x; cin >> x; qu[i] = {1, x}; has[x] = !has[x]; }
        else        { char c; cin >> c; qu[i] = {2, c - 'a'}; }
    }
    //加入第一波
    for(int i =1; i <=n;i++)
    {
        if(!has[i])st.insert(i);
    }
    //逆序处理操作
    for(int i = m;i>0;i--)
    {
        auto [a,b]=qu[i];
        
        if(a==2)
        {
            for(auto e:st)
            {
                
                    ans[e]=char(b+'a');
                     //记录该点是否已经处理完毕
                     done[e]=true;

            }
            st.clear();//全部处理完毕
        }
        else
        {
            has[b]=has[b]^1;//可能再次变为有方块
           
            if(!done[b])//没方块和没处理
            {
                if(!has[b])
                st.insert(b);
                else//状态改变
                st.erase(b);
            }
        }
    }
    //for(auto e:ans)cout << e;//第一个非法值
    rep(i, 1 ,n)cout << ans[i];

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
