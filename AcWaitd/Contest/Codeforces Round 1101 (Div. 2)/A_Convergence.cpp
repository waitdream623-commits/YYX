#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
int a[N];
void solve()
{
    int n;cin>>n;
    set<int>st;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        st.insert(a[i]);
    }
    sort(a+1,a+1+n);
    //从中间开始往两边找
    int mid=(1+n)>>1;
    int c1=0;
    int c2=0;
    
    for(int i=1;i<=n;i++)
    {
       if(a[i]>a[mid])c1++;
       if(a[i]<a[mid])c2++;
    }
    cout<<max(c1,c2)<<endl;
    

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
