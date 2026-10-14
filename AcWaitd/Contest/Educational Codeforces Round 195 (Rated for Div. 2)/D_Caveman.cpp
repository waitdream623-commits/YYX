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
int fa[N];
int find(int x)
{
    return fa[x] == x?x:fa[x] = find(fa[x]);
}
int sz[N];
void un(int x,int y)
{
    int fx = find(x);
    int fy = find(y);
    if(fx!=fy)
    {
        if(fx>fy)
        swap(fx,fy);
        fa[fx]  = fy;
        sz[fy] +=sz[fx];
    }
}
//节点多不一定是many，可能是星型图
int in[N];
void wait()
{
    int n,k;
    cin >> n >> k;
    rep(i,1,n)
    {
        fa[i] = i;
        sz[i] = 1;
        in[i] = 0;
    }
    rep(i,1,k)
    {
        int a , b;
        cin >> a >> b;
        // if(find(a)==find(b))//3个成环
        // {
        //     flag = 1;
        // }
        in[a]++;
        in[b]++;
        un(a,b);
    }
    int cnt = 0;
    bool flag = 0;
    rep(i,1,n)
    {
        if(in[i] == 0)
        {
            cout << "Brain Melt\n";
            return;
        }
        if(fa[i] == i)
            cnt++;//必然多余两个
        if(in[i] == n-1)
            flag = 1;
    }

    if(cnt>1)
        cout << "Many\n";
    else if(k == n-1 && flag)
        cout << "2\n";
    else
        cout << "Many\n";
    //不止一个集合
    // vector<int>s;
    // ll ans = 0;
//     rep(i,1,n)
//     {
//         if(fa[i] == i)
//         {
//             s.push_back(sz[i]);
//             if(sz[i] == 1)//其余不能提前返回，万一后续有单点
//             {
//                  cout << "Brain Melt\n";
//                 return ;
//             }
//             if(sz[i] == 2)
//             ans+=2;
//             else if(sz[i] == 3&&flag)
//             {
//                 cout << "Many\n";
//                 return;
//             }
//             else if(sz[i] == 3)ans+=2;
//             else
//             {
//                  cout << "Many\n";
//                 return;
//             }
//             if(ans>2)
//             {
//                  cout << "Many\n";
//                 return;
//             }
//         }
//     }
//  cout << 2<< "\n";
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
