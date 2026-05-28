
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
int a[N];
int f[N],len;//表示i结尾的最大上身子序列，选i与不选i
void slove()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int ans = 0;
    for(int i=1;i<=n;i++)
    {
        if(len==0||a[i]>f[len])f[++len]=a[i];//每个序列末尾尽可能小
       else
       {
            int x=lower_bound(f+1,f+1+len,a[i])-f;
            f[x]=a[i];
            
       }
    }
    cout<<len;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;  // 多测时取消注释
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
// int a[N];
// int f[N];//表示i结尾的最大上身子序列，选i与不选i
// void slove()
// {
//     int n;cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i];
//     }
//     int ans = 0;
//     for(int i=1;i<=n;i++)
//     {
//         f[i]=1;
//          for(int j=1;j<i;j++)
//          {
//             if(a[i]>a[j])
//             {
//                 f[i]=max(f[j]+1,f[i]);
//             }
//          }    
//         ans = max(ans, f[i]);//最大上升子序列不一定以i结尾
//     }
//     cout<<ans;
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
