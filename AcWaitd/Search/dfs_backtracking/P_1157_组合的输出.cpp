#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
vector<int>v;
//bool st[N];
int n,r;

void dfs(int start)
{
    if(v.size()==r)
    {
        for(auto e:v)
        {
            cout<<setw(3)<<e;
        }
        cout<<"\n";
        return;
    }
    for(int i=start;i<=n;i++)
    {
        //if(!st[i])
        //{
           // st[i]=1;
            v.push_back(i);
            dfs(i+1);//传入该值下一个，不能写成dfs(start+1);
            //st[i]=0;//每必要，通过start，传值控制重复
            v.pop_back();
        //}
    }
    return;
}
void slove()
{
    cin>>n>>r;
    dfs(1);//传入开始位置，从左往右依次枚举，防止重复
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
