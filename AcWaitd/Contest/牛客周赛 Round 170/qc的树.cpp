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
const int N = 2e5 + 10;
int a[N];
vector<int>edge[N];
int sz[N];
int cnt[N];
int add;
int single[N];
void dfs(int x,int f)
{
    sz[x]=1;
    for(auto e:edge[x])
    {
        if(e==f)
        {
            continue;
        }
        dfs(e,x);
        sz[x]+=sz[e];
        cnt[x] +=cnt[e];
        if(a[x]!=a[e])
        {
            cnt[x]++;
        }
    }
    if(cnt[x]==sz[x]-1)//全部满足
    {
        return;
    }
    //选择翻转路径
    add = max(1,add);//必然可以增加1；
    //单链处理
    // if(sz[x]==3&&cnt[x]==0)
    // {
    //     add = max(2,add);
    // }

    //处理根，最多为2(存在子树不全）+根改变的变化
    int cnt1=0;
    vector<int>ans;
    for(auto e:edge[x])
    {
        if(e==f)continue;
        if(cnt[e]!=sz[e]-1&&a[e]!=a[x])//因为只会增加1，保全一个就行
        {
           ans.push_back(e);
        }
        if(a[x]==a[e])cnt1++;

    }
    int cnt2=0;
    int last =0;
    int addsingle =0 ;
    for(auto e:ans)
    {
        if(a[x]!=a[e])//满足的且内部可改一个
        {
            cnt2++;
            addsingle = max(addsingle,last+single[e]);
            last = max(single[e],last);
        }


    }
    int t;
    t = edge[x].size();
   
        if(f!=-1)
        add =max(add,addsingle+cnt1+(a[x]==a[f])-(a[x]!=a[f])-max(0,(t-1-cnt1-2)));
        else
        {
            add =max(add,addsingle+cnt1-max(0,(t-cnt1-2)));
        }
//需要记录单条链与上层根的结合
      single[x] = last+cnt1-max(0,(t-1-cnt1-1));//一条链最多贡献


}
void wait()
{
    int n;cin >> n;
    rep(i,1,n)cin >> a[i];

    rep(i,1,n-1)
    {
        int x,y;cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    dfs(1,-1);
    cout<<cnt[1]+add;
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
