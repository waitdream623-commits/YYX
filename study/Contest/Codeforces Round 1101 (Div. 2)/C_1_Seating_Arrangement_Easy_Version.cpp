#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
void solve()
{
    int n,s,k;cin>>n>>s>>k;
    string a;
    cin>>a;
    multiset<char>t[s];
    ll ret=0;
    for(int i=0;i<a.size();i++)
    {
        char tmp=a[i];
        if(tmp=='E')
        {
            //找有人
            for(int j=0;j<s;j++)
            {
                int si=t[j].size();
                if(si!=0&&si<k)
                {
                    t[j].insert(tmp);
                    ret++;
                    break;
                }
            }
        }
        else if(tmp=='I')
        {
             //找没有人或者有人全是i人
            for(int j=0;j<s;j++)
            {
                int si=t[j].size();
                if(si==0||(si<k&&t[j].count('I')==si))
                {
                    t[j].insert(tmp);
                    ret++;
                    break;
                }
            }
        }
        else
        {
             //找空位
            for(int j=0;j<s;j++)
            {
                if(t[j].size()<k)
                {
                    t[j].insert(tmp);
                    ret++;
                    break;
                }
            }
        }
    }
    cout<<ret<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;  // 多测时取消注释
    while (T--) {
        solve();
    }
    return 0;
}
