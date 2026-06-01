#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
#define lc p<<1
#define rc p<<1|1
const int N = 1e6 + 10;
string s="kfdhtshmrw4nxg#f44ehlbn33ccto#mwfn2waebry#3qd1ubwyhcyuavuajb#vyecsycuzsmwp31ipzah#catatja3kaqbcss2th";
bool cheack(string s)
{
    bool flag1=0,flag2=0;
    for(auto e:s)
    {
        if(isdigit(e))flag1=1;
        else if(isalpha(e));
        else
        {
            flag2=1;
        }
    }
    if(flag1&&flag2)return true;
    return false;
}
void solve()
{
    ll ans=0;
    int n=s.size()-1;
    for(int i=0;i<=n-8+1;i++)
    {
        for(int len=8;len<=16;len++)
        {
            if(i+len-1>n)break;
            if(cheack(s.substr(i,len)))
            {
                ans++;
            }
        }
    }
    cout<<ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;  // 多测时取消注释
    while (T--) {
        solve();
    }
    return 0;
}
