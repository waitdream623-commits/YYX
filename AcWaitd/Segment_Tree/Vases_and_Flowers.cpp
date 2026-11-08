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
//二分找到第一个和最后一个零
//如果一个都无法修改，输出...利用和等于长度
//有花表示1，无花为0；
//当放花时，
int t[N<<2];
int lazy[N<<2];
int sum[N<<2];
void up(int p)
{
    sum[p] = sum [lc]+sum[rc];
}
void down(int l,int r,int p)
{
    if(lazy[p]!=-1)
    {
        int val = lazy[p];
        int mid = (l+r)>>1;
        sum[lc] = (mid-l+1)*val;
        lazy[lc] = val;
        sum[rc] = (r-mid)*val;
        lazy[rc] = val;
        lazy[p] = -1;
    }
}
void update(int jobl,int jobr,int l,int r,int p,int val)
{
    if(jobl<=l&&r<=jobr)
    {
        if(val==0)
        {
            sum[p]=0;
        }
        else
        {
            sum[p] = r-l+1;
        }
        lazy[p] = val;
        return;
    }
    int mid = (l+r)>>1;
    down(l,r,p);
    if(jobl<=mid)
    {
        update(jobl,jobr,l,mid,lc,val);
    }
    if(jobr>mid)
    {
        update(jobl,jobr,mid+1,r,rc,val);
    }
    up(p);
    return;
}
int query(int jobl,int jobr,int l,int r,int p)
{
        if(jobl<=l&&r<=jobr)
    {
        
        return sum[p];
    }
    int mid = (l+r)>>1;
    down(l,r,p);
    int ans = 0;
    if(jobl<=mid)
    {
        ans+=query(jobl,jobr,l,mid,lc);
    }
    if(jobr>mid)
    {
        ans+=query(jobl,jobr,mid+1,r,rc);
    }
    return ans;
}
void wait()
{
   int n, k;
    cin >> n >> k;

    fill(sum, sum + 4 * n, 0);      // 所有瓶子为空
    fill(lazy, lazy + 4 * n, -1);   // 没有待下传的赋值
    while(k--)
    {
        int op ,a,f;
        cin >> op>> a >>f;
        if(op==1)
        {
            int l = a+1,r=n;
            int x   = l, y =r;

            int t = r-l+1-query(l,r,1,n,1);//0的数目
            if(t==0)//没有0
            {
                cout << "Can not put any one.\n";
                continue;
            }
            //找左边界
            while(l<r)
            {
                int mid = (l+r)>>1;
                if((mid-l+1)-query(l,mid,1,n,1)>=1)
                {
                    r = mid;
                }
                else
                l=mid+1;
            }
            cout << l-1<<' ';
              //找右边界空瓶
                 int fm  = l;
                 r = n;
                while(l<r)
                {
                int mid = (l+r)>>1;
                if((mid-fm+1)-query(fm,mid,1,n,1)>=min(f,t))//可能插不下
                {
                    r = mid;//找右边界
                }
                else
                l = mid+1;
             }
            cout << l-1 << '\n';
            update(fm,l,1,n,1,1);//放上花
        }
        else
        {
            int l = a,r = f;
            cout << query(l+1,r+1,1,n,1)<<'\n';
            update(l+1,r+1,1,n,1,0);
        }
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;  // 多测时取消注释
    while (T--) {
        wait();
    }
    return 0;
}
