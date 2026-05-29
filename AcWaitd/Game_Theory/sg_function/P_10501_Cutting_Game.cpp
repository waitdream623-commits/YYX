#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
int n,m;
int f[N][N];

//bash博弈，对同一个操作，这是反常游戏
int sg(int a,int b)
{
    if(a==1&&b==1)return f[1][1]=0;//sg==0;//此时胜利
    if(f[a][b]!=-1)return f[a][b];
    unordered_set<int>st;

    for(int i=1;i<=a-1)
    {
        st.insert(sg(i,b));
    }
    for(int i=1;i<=b-1;i++)
    {
        st.insert(sg(a,i));
    }
    //mex
    for(int i=0;;i++)
    {
        if(st.count(i))return f[a][b]=i;
    }
}
void solve()
{
    memset(f,-1,sizeof f);
    int a=sg(n,m);
    if(a)
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin>>n>>m) {
        solve();
    }
    return 0;
}
