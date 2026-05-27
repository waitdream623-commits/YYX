#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
const int N = 1e6 + 10;
int rmb[110], rp[110], t[110];
int m, d;
PII f[110][110];

void slove() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> rmb[i] >> rp[i] >> t[i];

    cin >> m >> d;

    // 【修改 1】全部初始化为 0，代表“容量上限为 j, k 时，人数为0，时间为0”
    memset(f, 0, sizeof f);
    
    // 人数不同 -> 选人数多的
    // 人数相同 -> 选时间少的
    for(int i = 1; i <= n; i++) {
        for(int j = m; j >= rmb[i]; j--) {
            for(int k = d; k >= rp[i]; k--) {
                
                // 选第 i 个女孩能达到的人数和时间
                int a = f[j-rmb[i]][k-rp[i]].first + 1;
                int b = f[j-rmb[i]][k-rp[i]].second + t[i];
                
                // 【修改 2】删去 INF 相关的 continue 阻断判断
                
                // 新人数比较：如果人数变多，无脑覆盖更新
                if (a > f[j][k].first) {
                    f[j][k] = {a, b};
                }
                // 人数相同：取时间更少的方案
                else if (a == f[j][k].first) {
                    f[j][k].second = min(f[j][k].second, b);
                }
                //不选i
            }
        }
    }
    
    // 因为是“最多装满”，答案一定汇聚在拥有最大容量的 f[m][d] 中
    cout << f[m][d].second << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T; 
    while (T--) {
        slove();
    }
    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// typedef unsigned long long ull;
// typedef pair<int,int>PII;
// int INF=0x3f3f3f3f;
// const int N = 1e6 + 10;
// int rmb[110],rp[110],t[110];
// int m,d;
// PII f[110][110];
// //尽可能交到更多gf
// void slove()
// {
//     int n;
//     cin>>n;
//     for(int i=1;i<=n;i++)
//     cin>>rmb[i]>>rp[i]>>t[i];

//     cin>>m>>d;

//     memset(f,INF,sizeof f);
//     f[0][0]={0,0};
//     //人数不同 → 选人数多的
//     //人数相同 → 选时间少的
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=m;j>=rmb[i];j--)
//         for(int k=d;k>=rp[i];k--)
//         {
            
//             //选i
           
//             if (f[j-rmb[i]][k-rp[i]].first == INF)
//             {
//                 continue;
//             }
//              int a=f[j-rmb[i]][k-rp[i]].first+1,b=f[j-rmb[i]][k-rp[i]].second+t[i];
//             //可能人数与时间均为无穷大

//             if(f[j][k].first == INF||a>f[j][k].first)//新人数比较，选i，当未更新过优先更新
//            {
//             f[j][k]={a,b};
//            }
//             //相同
//             else if(a==f[j][k].first)
//              f[j][k].second=min(f[j][k].second,b);
//             //不选i
          
//         }
//     }
//     cout<<f[m][d].second<<'\n';

// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin >> T;  // 多测时取消注释
//     while (T--) {
//         slove();
//     }
//     return 0;
// }
