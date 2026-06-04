#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
int a[N];
int f[N];//以i为结尾，所有子数组最大和,转移单独自己或者与前面元素结合
void slove()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    int ret=-INF;
    for(int i=1;i<=n;i++)
    {
        f[i]=max(a[i],f[i-1]+a[i]);
        ret=max(ret,f[i]);
    }
    cout<<ret;
    
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
//分为三种情况，只在左边，右边，横跨两边，mid向左右枚举
//分治
// //P1115 最大子段和
// #include <iostream>
// #include <algorithm>
// using namespace std;
// const int N=2*1e5+10;
// int a[N];
// int n;
// int dfs(int l,int r)
// {
// 	if(l==r)return a[l];
// 	int mid=(l+r)/2;
//左右区间最大
// 	int ret=max(dfs(l,mid),dfs(mid+1,r));
// 	//一左一右

// 	//左 
// 	int sum=a[mid];int lmax=a[mid];
// 	for(int i=mid-1;i>=l;i--)
// 	{
		
// 		sum+=a[i];
// 		 lmax=max(sum,lmax);
// 	 } 
// 	 //右 
// 	 sum=a[mid+1];int rmax=a[mid+1];
// 	 for(int i=mid+2;i<=r;i++)
// 	{
// 		sum+=a[i];
// 	 rmax=max(sum,rmax);
// 	 } 
// 	ret=max(ret,lmax+rmax);
// 	return ret;
// }
// int main()
// {
// 	cin>>n;
// 	for(int i=1;i<=n;i++)
// 	{
// 		cin>>a[i];
// 	}
// 	cout<<dfs(1,n);
// 	return 0;
//  } 