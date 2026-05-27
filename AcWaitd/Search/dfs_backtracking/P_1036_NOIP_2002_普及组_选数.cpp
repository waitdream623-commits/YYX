#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
bool is_prime(int x)
{
    for(int i=2;i<=x/i;i++)
    {
        if(x%i==0)return false;
    }
    return true;
}
int a[N];
int n,k;
ll ret=0;
ll sum=0;
void dfs(int start,int pos,ll sum)//起始与该选第几个数
{
    if(pos>k)
    {
        if(is_prime(sum))
        {
            ret++;
        }
        //不能在此处重置sum
        return;
    }
    for(int i=start;i<=n;i++)
    {
        
        dfs(i+1,pos+1,sum+a[i]);
        

    }
    return;
}
// void dfs(int start,int pos)//起始与该选第几个数
// {
//     if(pos>k)
//     {
//         if(is_prime(sum))
//         {
//             ret++;
//         }
//         //不能在此处重置sum
//         return;
//     }
//     for(int i=start;i<=n;i++)
//     {
//         sum+=a[i];
//         dfs(i+1,pos+1);
//         sum-=a[i];

//     }
//     return;
// }
void slove()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    dfs(1,1,0);
    cout<<ret;
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
