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
// int a[N];int k[5];
// int n,m;
// int ans=0;
// int dfs(int start)
// {
//     if(start<0)return 0;   
//     if(start==1)
//     {
//         return a[1];
//     }
//     int ans=0;
//     rep(i,1,4)
//     {
//         if(k[i])
//        {
//         k[i]--;
//          ans=max(dfs(start-i)+a[start],ans);//-i不是-k[i]
//          k[i]++;
//        }

//     }
//     return ans;
// }
// int dp[50][50][50][50];
// int dfs2(int e,int b,int c,int d)
// {
//     if(e==k[1]&&b==k[2]&&c==k[3]&&d==k[4])return dp[e][b][c][d]=a[n]=a[n];
//     int p=1+e+2*b+c*3+d*4;
//     if(dp[e][b][c][d]!=0)return dp[e][b][c][d];
//     int ans=0;
//     if(e<k[1])ans=max(dfs2(e+1,b,c,d)+a[p],ans);
//     if(b<k[2])ans=max(dfs2(e,b+1,c,d)+a[p],ans);
//     if(c<k[3])ans=max(dfs2(e,b,c+1,d)+a[p],ans);
//     if(d<k[4])ans=max(dfs2(e,b,c,d+1)+a[p],ans);
//     return dp[e][b][c][d]=ans;


// }
// void wait()
// {
//     cin>>n>>m;
//     rep(i,1,n)
//     {
//         cin>>a[i];
//     }
//     rep(i,1,m)
//     {
//         int x;
//         cin>>x;
//         k[x]++;
//     }
//     //cout<<dfs(n);
//     cout<<dfs2(0,0,0,0);

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
//优化初始值为-1，防止后续数组得分为零
#include <bits/stdc++.h>
using namespace std;

#define rep(i, m, n) for(int i = m; i <= n; ++i)

const int N = 355;
int a[N];
int k[5];
int n, m;
int dp[45][45][45][45];

int dfs2(int e, int b, int c, int d) {
    // 递归终点：所有卡片全部用完，乌龟已到达第 n 格
    if (e == k[1] && b == k[2] && c == k[3] && d == k[4]) {
        return a[n];
    }

    // 记忆化命中直接返回
    if (dp[e][b][c][d] != -1) {
        return dp[e][b][c][d];
    }

    int p = 1 + e * 1 + b * 2 + c * 3 + d * 4;
    int next_max = 0;

    // 枚举下一步使用哪种卡片，找出后续的最大得分
    if (e < k[1]) next_max = max(next_max, dfs2(e + 1, b, c, d));
    if (b < k[2]) next_max = max(next_max, dfs2(e, b + 1, c, d));
    if (c < k[3]) next_max = max(next_max, dfs2(e, b, c + 1, d));
    if (d < k[4]) next_max = max(next_max, dfs2(e, b, c, d + 1));

    // 记录并返回：当前格子的分值 + 后续步数的最大收益
    return dp[e][b][c][d] = next_max + a[p];
}

void solve() {
    cin >> n >> m;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, m) {
        int x;
        cin >> x;
        k[x]++;
    }

    memset(dp, -1, sizeof dp);
    cout << dfs2(0, 0, 0, 0) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
// //P1541 [NOIP 2010 提高组] 乌龟棋

// #include <iostream>

// using namespace std;
// const int N=50;
// int f[N][N][N][N];//dp数组，P1541，f[a][b][c][d]
// 					//使用a张1到达.....的最大值
// int x[450];
// int cnt[N];//统计每张牌数量 
// int main()
// {
// 	int n,m;cin>>n>>m;
// 	for(int i=1;i<=n;i++)
// 	cin>>x[i];
// 	for(int i=1;i<=m;i++)
// 	{
// 		int x;cin>>x;
// 		cnt[x]++;
		
// 	 } 
// 	//初始
// 	f[0][0][0][0]=x[1];
// 	for(int a=0;a<=cnt[1];a++)
// 		for(int b=0;b<=cnt[2];b++)
// 			for(int c=0;c<=cnt[3];c++)
// 				for(int d=0;d<=cnt[4];d++)
// 				{
// 					int i=1+a+2*b+3*c+4*d;//初始位置为1 
// 					int& t=f[a][b][c][d];
// 					if(a)t=max(t,f[a-1][b][c][d]+x[i]);
// 					if(b)t=max(t,f[a][b-1][c][d]+x[i]);
// 					if(c)t=max(t,f[a][b][c-1][d]+x[i]);
// 					if(d)t=max(t,f[a][b][c][d-1]+x[i]);
// 				}
// 	cout<<f[cnt[1]][cnt[2]][cnt[3]][cnt[4]];
// 	return 0;
//  } 