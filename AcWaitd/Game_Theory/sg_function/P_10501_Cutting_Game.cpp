#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
int n,m;
int f[300][300];

//bash博弈拆分为两个，对同一个操作，这是反常游戏，找出反常状态，反常状态sg=0；
int sg(int a,int b)
{
    if(f[a][b]!=-1)return f[a][b];
    unordered_set<int>st;

    for(int i=2;i<a-1;i++)//必败态，为零，进不了递归(2,2),(2,3),(3,2),(3,3)
    {
        st.insert(sg(i,b)^sg(a-i,b));
    }
    for(int i=2;i<b-1;i++)
    {
        st.insert(sg(a,i)^sg(a,b-i));
    }
    //mex
    for(int i=0;;i++)
    {
        if(!st.count(i))return f[a][b]=f[b][a]=i;
    }
    return -1;
}
void solve()
{
    int a=sg(n,m);
    if(a)
    {
        cout<<"WIN\n";
    }
    else cout<<"LOSE\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(f,-1,sizeof f);//只初始化一次，记录

    while (cin>>n>>m) {
        solve();
    }
    return 0;
}
