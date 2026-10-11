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
vector<int>x,y;
//保证所有点不重合且不位于原点上
//全部位于x或y轴上
//两边都有
void wait()
{
    int n ; cin >> n;
    rep(i,1,2 * n)
    {
        int  a, b;
        cin >> a >>b;
        if(a==0)
        {
            y.push_back(b);
        }
        else
        x.push_back(a);
    }
    if(n==1)
    {
        cout << "YES";
        return ;
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    //全在一边
    if(x.size() == 0)
    {
        int l = 0, r = y.size()-1;
        int k = y[l++]+y[r--];
        while(l<r)
        if(y[l++]+y[r--] != k)
        {
            cout << "NO";
            return ;

        }
        cout <<"YES";
        return ;
    }
     if(y.size() == 0)
    {
        int l = 0, r = x.size()-1;
        int k = x[l++]+x[r--];
        while(l<r)
        if(x[l++]+x[r--] != k)
        {
            cout << "NO";
            return ;

        }
        cout <<"YES";
        return ;
    }
    if(x.size()!=y.size())
    {
        cout << "NO" <<endl;
        return;
    }
    //处理对称轴是否相同只能是1才可满足，
    int i = 0;
    int k = 1;
    for(i = 0; i < x.size(); ++i)
    {
        double t = y[i]*1.0/x[i];
        if(t != k)
        {
            cout << "NO" <<endl;
        return; 
        }
        //求中点，
    }
    //都相同看中点在不在对称轴上
    cout<<"YES";
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;  // 多测时取消注释
    while (T--) {
        wait();
    }
    return 0;
}
