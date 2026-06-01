#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
#define lc p<<1
#define rc p<<1|1
const int N = 1e7 + 10;
int p[N],cnt;
bool st[N];
void getprime()
{
    for(int i=2;i<=N;i++)
    {
        if(!st[i])p[++cnt]=i;
        for(int j=1;1ll*i*p[j]<=N;j++)
        {
            st[i*p[j]]=true;
            if(i%p[j]==0)break;
        }
    }
}
void solve()
{
     char T;
    cin >> T;
   string ans[2];
    ll ret=0;
    getprime();
    for(ll i=1;i<=cnt;i++)
    {
        long long p2=1LL*p[i]*p[i];//最小情况
		if(1LL*p2*p2>23333333333333) break;
        for(int j=i+1;j<=cnt;j++)//不能相等
        {
            if(1ll*p[i]*p[i]*p[j]*p[j]<2333)continue;
            if(1ll*p[i]*p[i]*p[j]*p[j]>23333333333333)
            {
                break;
            }
            //if(1ll*p[i]*p[i]*p[j]*p[j]>=2333&&1ll*p[i]*p[i]*p[j]*p[j]<=23333333333333)
            ret++;
            
        }
    }
    ans[1]=to_string(ret);
    ll dp[4]={0,0,0,0};//初始化
    string s;
    for(int i=1;i<=2023;i++)
    {
        s+=to_string(i);

    }
    for(int i=0;i<=s.size();i++)
    {
        if(s[i]=='2') dp[0]++,dp[2]=dp[2]+dp[1];
			else if(s[i]=='0') dp[1]=dp[1]+dp[0];
			else if(s[i]=='3') dp[3]=dp[3]+dp[2];
    }
   
    ans[0]=to_string(dp[3]);
    cout << ans[T - 'A'] << endl;
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
//#include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;

// const int N = 5e6 + 10; // 优化空间，最大值 4830458，筛到 500万 绰绰有余
// int p[N], cnt;
// bool st[N];

// void getprime()
// {
//     for(int i = 2; i <= N - 1; i++)
//     {
//         if(!st[i]) p[++cnt] = i;
//         for(int j = 1; 1ll * i * p[j] <= N - 1; j++)
//         {
//             st[i * p[j]] = true;
//             if(i % p[j] == 0) break;
//         }
//     }
// }

// void solve()
// {
//     char T;
//     cin >> T;
//     ll ret = 0;
//     getprime();

//     for(int i = 1; i <= cnt; i++)
//     {
//         // 剪枝：因为 p[i] < p[j]，如果 p[i]*p[i] 就已经大于上限，那连 p[j] 都不用找了，直接结束
//         if(1ll * p[i] * p[i] > 4830458) break;

//         for(int j = i + 1; j <= cnt; j++)
//         {
//             ll mul = 1ll * p[i] * p[j]; // 现在最大也就是 483万，连 int 都不溢出，1ll 纯属双重保险
            
//             if(mul >= 49 && mul <= 4830458)
//             {
//                 ret++;
//             }
//             if(mul > 4830458) // 超过最大限制，直接打断内层循环
//             {
//                 break;
//             }
//         }
//     }
    
//     if(T == 'B') cout << ret << "\n";
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin >> T;
//     while (T--) {
//         solve();
//     }
//     return 0;
// }
