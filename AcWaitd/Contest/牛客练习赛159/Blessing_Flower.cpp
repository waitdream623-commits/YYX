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
int a[N];
int l[2][N],r[2][N];
// void wait()
// {
//     int n;cin >> n;
//     rep(i,1,n)
//     {
//         cin >> a[i];
//     }
//     string s;
//     cin >>s;
//     vector<int>f;
//     int last = 0;
//     int mx = 0;
//     rep(i,1,n)//跑最大上升,中间可能有
//     {
//         if(s[i-1]=='R'&&a[i]>mx)//不会被档
//         {
//             auto p = lower_bound(f.begin(),f.end(),a[i]);
//             if(p !=f.end())
//             {
//                 *p= a[i];
//             }
//             else
//             f.push_back(a[i]);

//             l[1][i] = f.size();
//             last = l[1][i];
//         }
//         else
//         {
//             mx = max(a[i],mx);
//             l[1][i] = last;//继承之前的
//         }
//     }
//     f.resize(0);
//     last = 0;
//     mx = 0;
//      rep(i,1,n)//跑最大上升
//     {
//         if(s[i-1]=='L'&&a[i]>mx)
//         {
//             auto p = lower_bound(f.begin(),f.end(),a[i]);
//             if(p !=f.end())
//             {
//                 *p= a[i];
//             }
//             else
//             f.push_back(a[i]);

//             l[0][i] = f.size();
//             last = f.size();
//         }
//          else
//         {
//             mx = max(a[i],mx);

//             l[0][i] = last;//继承之前的
//         }
//     }
//     f.resize(0);
//     last = 0;
//     mx = 0;
//      for(int i = n;i>0;i--)
//     {
//         if(s[i-1]=='R'&&a[i]>mx)
//         {
//             auto p = lower_bound(f.begin(),f.end(),a[i]);
//             if(p !=f.end())
//             {
//                 *p= a[i];
//             }
//             else
//             f.push_back(a[i]);

//             r[0][i] = f.size();
//             last = f.size();

//         }
//          else
//         {
//             mx = max(a[i],mx);

//             r[0][i] = last;//继承之前的
//         }
//     }
//     f.resize(0);
//     last = 0;
//     mx = 0;
//         for(int i = n;i>0;i--)
//     {
//         if(s[i-1]=='L'&&a[i]>mx)
//         {
//             auto p = lower_bound(f.begin(),f.end(),a[i]);
//             if(p !=f.end())
//             {
//                 *p= a[i];
//             }
//             else
//             f.push_back(a[i]);

//            r[1][i] = f.size();
//             last = f.size();

//         }
//          else
//         {
//             mx = max(a[i],mx);

//             r[1][i] = last;//继承之前的
//         }
//     }
//      int ans = 0;
//      int k =0;
//      r[0][n+1] = 0;
//         ans = max(ans,l[0][n]+r[0][1]);

//     rep(i,1,n)
//     {
//         if(l[1][i]+r[0][i+1]>ans)//i位置已经翻转，后续怎么连接
//         {
//             k = i;
//             ans = l[1][i]+r[0][i];
//         }
//         if(l[0][i-1]+r[1][i]>ans)
//         {
//             k = i;
//             ans = l[0][i]+r[1][i];
//         }
//     }
//     f.resize(0);
//     cout << ans << ' '<< k<<"\n";

// }
void wait()
{
    int n;
    cin >> n;

    rep(i,1,n)cin >> a[i];

    string s;
    cin >> s;

    int mx = 0;
    rep(i,1,n)
    {
        l[0][i] = (a[i] > mx); // 左侧可见
        mx = max(mx, a[i]);
    }

    mx = 0;
    for(int i = n; i >= 1; i--)
    {
        r[0][i] = (a[i] > mx); // 右侧可见
        mx = max(mx, a[i]);
    }

    int cur = 0;
    rep(i,1,n)//不翻转
    {
        if(s[i-1] == 'L')cur += l[0][i];
        else cur += r[0][i];
    }

    int ans = cur;
    int k = 0;

    rep(i,1,n)//枚举翻转位置，记录最大处
    {
        if(s[i-1] == 'L')
            cur += r[0][i] - l[0][i];
        else
            cur += l[0][i] - r[0][i];

        if(cur > ans)
        {
            ans = cur;
            k = i;
        }
    }

    cout << ans << ' ' << k << '\n';
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
