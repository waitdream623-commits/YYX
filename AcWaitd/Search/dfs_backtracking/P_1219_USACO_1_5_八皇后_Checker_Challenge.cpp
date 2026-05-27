#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
//标记对角线
//x+y为定值或者y-x为定值
int n;
bool vis1[30];//斜率为负，和全为正
bool vis2[2][14];//斜率为正，差有正有负，i=0,为正，i=1为负,取绝对值
bool col[30];
ll ret=0;
vector<int>v;
void dfs(int p)
{
    if(p>n)
    {
        if(ret<3)
        {
            for(auto e:v)
            {
                cout<<e<<" ";
            }
            cout<<"\n";
        }
        ret++;
        return;
    }
    for(int i=1;i<=n;i++)//选每一行的列
    {
        int d=p-i;
        //行为p
        if(!col[i]&&!vis1[p+i]&&!vis2[d>0?0:1][abs(d)])
        {
            v.push_back(i);
            col[i]=vis1[p+i]=vis2[d>0?0:1][abs(d)]=1;
            dfs(p+1);
            col[i]=vis1[p+i]=vis2[d>0?0:1][abs(d)]=0;
            v.pop_back();
        }

    }
    return;
}
void slove()
{
    cin>>n;
    dfs(1);
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
