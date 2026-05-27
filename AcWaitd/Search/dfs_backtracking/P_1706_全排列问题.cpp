#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e8 + 10;
int n;
vector<int>v;
bool st[10];//标记此层访问过了
void dfs(int p)//可以不用传参，使用v.size()
{
    if(p>n)
    {
        //输出
        for(auto i=v.begin();i<v.end();i++)
        {
           // printf("%5d",*i);//可能输出乱码
           cout<<setw(5)<<*i;
        }
        cout<<"\n";
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!st[i])
        {
            v.push_back(i);
            st[i]=1;
            dfs(p+1);
            //回溯
            st[i]=0;
            v.pop_back();//每一层返回都会删掉最后一个
        }
    }
}
void slove()
{
        cin>>n;
        dfs(1);//需要传入选第几个了


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
