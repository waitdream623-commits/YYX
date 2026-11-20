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
//对于查询，区间长度小的直接为0，大的查找区间中间大的值
int a[N];
int b[N];
bool flag;
int midmax(int l,int r)
{
    if(flag)
    {
        for(int i = l;i<=r;i++)b[i] = a[i];
        flag=0;
    }
    int idx = ((r-l+1)>>1)+l;//中间大
    while(l<r)
    {
        int mid = (l+r)>>1;
        //分三块
        int i=l,it=l,ir = r;
        while(i<=ir)
        {
            if(b[i]<b[mid])
            {
                swap(b[i],b[it]);
                i++,it++;
            }
            else if (b[i]==b[mid]) {
                i++;
            }
            else
            {
                swap(b[i],b[ir]);
                ir--;
            }
        }
        //[l,it-1][it,i-1][i,r];
        if(idx<it)r=it-1;
        else if(idx>i-1)
        {
            l = i;
        }
        else
        return b[mid];

    }
    return b[l];
}
void wait()
{
    int n, m, k;
    cin >> n >> k >> m;
    rep(i,1,n)cin >> a[i];
    rep(i,1,m)
    {
        int o,x,y;
        cin >> o >>x >>y;
        if(o==1)
        {
            a[x] =y;
            flag=1;
        }
        else
        {
            if(y-x+1<k)
            {
                cout<<0<<'\n';
            }
            else
            {
                //找中间值
                cout << midmax(x,y)<< '\n';
            }
        }
    }
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
