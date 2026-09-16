// #include <bits/stdc++.h>
// using namespace std;
// #ifndef DEBUG
// struct __X {
//   __X& operator<<(const auto& str) {return *this;}
//   void sp(const string& str = "") {}
// } dout;
// #define debug(x)
// #endif
// typedef long long ll;
// typedef unsigned long long ull;
// typedef pair<int,int>PII;
// int INF=0x3f3f3f3f;
// #define rep(i,m,n) for(int i=m;i<=n;++i)
// #define lc p<<1
// #define rc p<<1|1
// const int N = 1e6 + 10;
// //叶子节点，其上方有父节点，父节点放最优，
// //三种状态
// //0 未被覆盖，
// //1 被覆盖，但没放塔
// //2 被覆盖，放塔  
// vector<int>edge[N];
// int n;
// int ans=0;
// int  dfs(int x ,int fa)
// {
//     bool flag=1;
//     for(auto e: edge[x])
//     {
//         flag=0;
//         if(x==fa)continue;
//         int a = dfs(e,x);
//         if(a==0)//不能这样写没便利完
//         {
//             ans++;
//             return 2;
//         }
//         //只剩1/2
//         //全是1返回0
//         if(a==2)
//         {
//             return 1;
//         }

//     }
//     if(flag)//叶子节点
//     return 0;
//     if(x==1)//是根节点，必须保证全覆盖,//此时全是1，需要自己放塔
//     {
//         ans++;
//         return 2;
//     }
//     return 0;//全是1的情况
// }
// void wait()
// {
//     cin>>n;
//     rep(i,1,n-1)
//     {
//         int a,b;
//         cin>>a>>b;
//         edge[a].push_back(b);
//         edge[b].push_back(a);
//     }
//     dfs(1,-1);
//     cout<<ans;
// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin >> T;  // 多测时取消注释
//     while (T--) {
//         wait();
//     }
//     return 0;
// }
// #include <bits/stdc++.h>
// using namespace std;
// #ifndef DEBUG
// struct __X {
//   __X& operator<<(const auto& str) {return *this;}
//   void sp(const string& str = "") {}
// } dout;
// #define debug(x)
// #endif
// typedef long long ll;
// typedef unsigned long long ull;
// typedef pair<int,int>PII;
// int INF=0x3f3f3f3f;
// #define rep(i,m,n) for(int i=m;i<=n;++i)
// #define lc p<<1
// #define rc p<<1|1
// const int N = 1e6 + 10;
// //叶子节点，其上方有父节点，父节点放最优，
// //三种状态
// //0 未被覆盖，
// //1 被覆盖，但没放塔
// //2 被覆盖，放塔  
// vector<int>edge[N];
// int n;
// int ans=0;
// int dfs(int x, int fa)
// {
//     bool has0 = false;
//     bool has2 = false;

//     for(auto e : edge[x])
//     {
//         if(e == fa) continue;

//         int state = dfs(e, x);

//         if(state == 0) has0 = true;
//         if(state == 2) has2 = true;
//     }

//     if(has0)
//     {
//         ans++;
//         return 2;
//     }

//     if(has2)
//         return 1;

//     return 0;
// }
// int main()
// {
//     cin>>n;
//     rep(i,1,n-1)
//     {
//         int a,b;
//         cin>>a>>b;
//         edge[a].push_back(b);
//         edge[b].push_back(a);
//     }
//     if(dfs(1,-1)==0)
//     ans++;
//     cout<<ans;
// }
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e6 + 10;

vector<int> edge[N];
int n;
int ans = 0;

// 返回值含义：
// 0: 未被覆盖
// 1: 已被覆盖（没放塔）
// 2: 放置了塔
int dfs(int x, int fa) {
    bool need_tower = false; // 是否有子节点处于未覆盖状态(0)
    bool has_tower = false;  // 是否有子节点放置了塔(2)

    for (auto e : edge[x]) {
        if (e == fa) continue; // 避开父节点，防止回溯
        
        int res = dfs(e, x);
        if (res == 0) need_tower = true;
        if (res == 2) has_tower = true;
    }

    // 优先级 1：只要有子节点没被覆盖，当前节点必须放塔
    if (need_tower) {
        ans++;
        return 2;
    }

    // 优先级 2：子节点全被覆盖，且至少有一个子节点放了塔，当前点被覆盖
    if (has_tower) {
        return 1;
    }

    // 优先级 3：叶子节点，或所有子节点均处于状态 1（没放塔但也已被覆盖）
    // 当前节点处于未覆盖状态，留给父节点去解决
    return 0;
}

void wait() {
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    // 特判：只有一个节点时，必须自身放塔
    if (n == 1) {
        cout << 1 << "\n";
        return;
    }

    // 根节点没有父节点，若最终仍为未覆盖状态(0)，必须额外放塔
    if (dfs(1, 0) == 0) {
        ans++;
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--) {
        wait();
    }
    return 0;
}