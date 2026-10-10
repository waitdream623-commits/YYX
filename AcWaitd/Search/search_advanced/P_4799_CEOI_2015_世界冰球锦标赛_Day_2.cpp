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
//对于数据量采用折半搜索
ll a[50];
//数据量对半
ll lsum[(1<<20)+1];
ll rsum[(1<<20)+1];
ll j = 0;//数据位置
ll m;
void dfs(int i , int e ,ll sum , ll lsum[])
{
    if(i == e)//end是下个数要选的，本轮不选
    {
        lsum[j++]=sum;
    }
    else
    {
       dfs(i+1,e,sum,lsum);
        dfs(i+1, e,sum+a[i],lsum);
    }
}
void wait()
{
    int n;
    cin >> n >> m;
    rep(i,0,n-1)cin >> a[i];
    //sort(a+1,a+1+n);//有序情况下，可以快速排除以一些操作
    dfs(0,(n>>1),0,lsum);//开始位置，结束位置，累加和
    ll lsize = j;
    j = 0;
   dfs((n>>1),n,0,rsum);
    ll rsize = j;
    //两边数据整合
    sort(lsum, lsum+lsize);
    sort(rsum, rsum+rsize);
     int r = rsize-1;
     ll ans = 0;
    for( int l = 0;l < lsize; ++l)
    {
        while(r>=0&&rsum[r]+lsum[l]>m)
        r--;

        ans += r+1;
    }
    cout <<ans;
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
