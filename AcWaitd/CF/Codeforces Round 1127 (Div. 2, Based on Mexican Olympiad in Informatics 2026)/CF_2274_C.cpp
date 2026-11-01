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
//二分判断是否可以拆分成满足的
void wait()
{
    int n;
    cin >> n;
    // if(n<4)
    // {
    //     cout << 1 <<"\n";
    //     return;
    // }
    //二分
    int l = 1, r = n;
    auto cheack = [&](int mid)->bool
    {
        ll s = n;
        for(int x = mid; x >0 ;x--)
        {
            s -= mid/x*x;
            if(s <= 0) return true;
        }
        return false;
    };
    while(l<r)
    {
        int mid = (l+r)>>1;
        if(cheack(mid))
        {
            r=mid;
        }
        else
        l = mid +1;
    }
    cout << l<< '\n';
    //分配
    int cnt = l;//l个选择相同袋子
    int t = cnt;//备份如果还要再选这么多次
    int cnt2 = 1;//选择几批；
    int j =1;//袋子号
    for(int i = 1;i<=n;i++)
    {
        if(cnt)
        {
            cout << j<<' ';
            cnt --;
        }
        else
        {
            if(--cnt2)
            {
                cnt = t;//还要往一个袋子中装
                j++;
                cout << j<<' ';
                cnt --;
            }
            else
            {
                j++;
                cnt = t -1;
                cnt2 = l/(t-1);
                t = cnt;//备份
                cout << j<<' ';
                cnt --;
            }
        }
    }
    cout << endl;
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
