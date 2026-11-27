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

void wait()
{
    int n,k;cin >> n >>k;
    vector<string>s(n+1);
//    using T = tuple<int, int, int>;
//     priority_queue<T, vector<T>, greater<T>> q;
//     ll t=0;
//     rep(i,1,n)
//     {
//         cin >> s[i];
//         t+=s[i][0]-'a'+1+s[i][1]-'a'+1+s[i][2]-'a'+1;
//         //相同权值不知道该选谁，可能中间更小

//         q.push({s[i][0]-'a'+1,s[i][0]-'a'+1+s[i][1]-'a'+1,i});
//         q.push({s[i][2]-'a'+1,s[i][1]-'a'+1+s[i][2]-'a'+1,i});
//     }
//     vector<bool>vis(n+1);
//     while(q.size())
//     {
//         if(k==0)break;
//       const int INF = 1'000'000'000;
//         auto [last, r, j] = q.top();

//         while (vis[j] && r != INF) {
//             q.pop();
//             q.push({last, INF, j});
//             tie(last, r, j) = q.top();
//         }
//         auto [e,x,i]=q.top();
//         q.pop();
//         t-=e;
//         if(!vis[i])//只能加一次中间
//        {
//          q.push({s[i][1]-'a'+1,1e9,i});//尽量暴露出更多可能性，此时如果还有尾巴其权重应该降低
//          vis[i]=1;
//        }
//         k--;
//     }
//     cout << t<<'\n';
//可能连续选两个
//分组背包
ll t=0;
vector<array<int,4>>cost(n+1);
    rep(i,1,n)
    {
        cin >> s[i];
        int a = s[i][0]-'a'+1;
        int b = s[i][1]-'a'+1;
        int c = s[i][2]-'a'+1;
        int sum = a+b+c;
        t+=sum;
         cost[i] = {0,min(a,c),sum-max({a,b,c}),sum};
       
    }
    vector<int>f(k+1,1e9);
    f[0]=0;
    rep(i,1,n)
    {
         for(int j = k ;j>=1;j--)
        {
            for(int x = 1;x<=3&&x<=j;x++)
            {
                f[j]=min(f[j],f[j-x]+cost[i][x]);
            }
        }
    }
    cout << t - f[k]<<'\n';

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;  // 多测时取消注释
    while (T--) {
        wait();
    }
    return 0;
}
