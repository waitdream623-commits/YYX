#include <iostream>
using namespace std;
#define int long long
const int N = 2e5 + 10,INF=0x3f3f3f3f;
int a[N], ans[N];
long long f[N];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        f[0]=0;
        int m=0,mn=INF;
        for (int i = 1; i <= n; i++){ cin >> a[i];
            if(a[i]<0)
            f[i]=abs(a[i])+f[i-1];
            else
            {
                f[i]=f[i-1];
            }
            m=max(m,a[i]);
            mn=min(mn,a[i]);
        }
    // if(m<=0)
    // {
    //     cout<<0<<endl;
    //     continue;
    // }
    //    if(mn>=0)
    // {
    //     cout<<0<<endl;
    //     continue;
    // }
    int index=0;
    int mx=0;
    for(int i=1;i<n;i++)
    {
        if(a[i+1]>0)
        {
            if(f[i]-a[i+1]>mx)
            {
                index=i+1;
                mx=f[i]-a[i+1];//开long long
            }
        }
    }    
    if(index==0)
    {
        cout<<0<<endl;
        continue;
    }
        int cnt = 0, flip = 0;
        // 从右向左: 若有效值为正则翻转前缀 [1..i]
        for (int i = index-1; i >= 1; i--) {
            //翻转偶数次为本身，奇数取负
            int cur = flip ? -a[i] : a[i];
            if (cur > 0) {
                ans[++cnt] = i;
                flip ^= 1;
            }
        }
        ans[++cnt]=index;
        cout << cnt << '\n';
        for (int i = 1; i <= cnt; i++) {
            cout << ans[i] << " \n"[i == cnt];
        }
    }
}