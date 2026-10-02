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
vector<PII>edges[N];
//1到n的点连城环，每个点都与n+1有连线
//对于每两个点，要么顺时针或者逆时针，或者通过n+1两步转移
//需要枚举跳跃点
//对于逆时针前缀和，增加一倍将环降低为线性
long long presum[N];
void wait()
{
    int n,m;cin >>n>>m;
    rep( i,1, n)//没有连接n+1的路
    {
        int x;cin >>x;
        edges[i].push_back({i%n+1,x});
        edges[i%n+1].push_back({i,x});
        presum[i]+=presum[i-1]+x;
        presum[i+n]+=x;//预先加上
    }
    rep(i,1,n)
    {
        presum[n+i]+=presum[n+i-1];
    }
    vector<ll>b(n+1,0);
    rep(i,1,n)
    {
        int x;cin>>x;
       b[i] = x;
    }
    //debug(presum);
    //预处理每个点最短路径到跳跃点、
    //不对：对于每个点往顺或者逆处理，当到达下一个点的路加上转移小于上一个(不选该点，后面点一定不会选），就停止往后，处理逆
    vector<ll>ton(n+1,0);
    for(int i=1;i<=n;i++)
    {
        //顺着
        ton[i]=b[i];//直接去n+1；
        int j=i+1;
        while(j<2*n)
        {
            if(presum[j-1]-presum[i-1]+b[(j-1)%n+1]<ton[i])
            {
                ton[i]=presum[j-1]-presum[i-1]+b[(j-1)%n+1];
                    
            }
            // else break;//找到第一个不成立
            j++;
        }
        //逆
        j=n+i;
          while(j<2*n)
        {
            if(presum[j-1]-presum[i-1]+b[j]<ton[i])
            {
                ton[i]=presum[j-1]-presum[i-1]+b[j];
                
            }
            // else break;//找到第一个不成立

            j++;
        }
    }
    while(m--)
    {
        int l,r;
        cin >> l >>r;
        if(l==n+1||r==n+1)
        {
            if(l!=n+1)cout<<ton[l];
            else
            cout<<ton[r];
            cout<<'\n';
        }
        else
        {
            // ll ans=1e18;
            // //走n+1路线；
            // ans=min(b[l]+b[r],ans);
            // //顺
            // if(r<l)swap(l,r);
            // ans=min(presum[r-1]-presum[l-1],ans);//r需要-1，画图理解
            // //逆
            // ans=min(presum[n+l-1]-presum[r-1],ans);
            // cout <<ans<<'\n';
            //有bug
            //还是得枚举跳跃点
            ll ans=1e18;
            ans=min({ton[l]+ton[r],presum[r-1]-presum[l-1],presum[n+l-1]-presum[r-1]});
            cout<<ans<<'\n';
        }
    }
    

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
