//P16229 [蓝桥杯 2026 省 A] 外卖配送
//dp
#include <iostream>
#include <cstring> 
using namespace std;
typedef long long ll;
const int N=5e3+10;
ll f[N][N];//f[i][j]表示0->i种交通方式，运输j份订单最小耗时
ll a[N],b[N]; 
int main()
{
	ll m,n,x;
	cin>>m>>n>>x;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	//初始化
	memset(f,0x3f,sizeof f);
	f[0][0]=0;
    f[1][0]=0;
	for(int i=1;i<=n;i++)
	{
		//从1开始爆零 
		for(int j=0;j<=m;j++)
		{
			//不用等i种交通工具 
			f[i][j]=f[i-1][j];
			//枚举使用该交通工具载的订单数
			for(int k=0;k<=j;k++)
			{
				f[i][j]=min(f[i][j],f[i][j-k]+k*a[i]+k*(k-1)/2*b[i]+x);
			 } 
		}
	 } 
	 cout<<f[n][m]-x;
	return 0;
 } 



////P16227 [蓝桥杯 2026 省 A] 切割木材
//
//#include <iostream>
//#include <algorithm>
//using namespace std;
//const int N=1e6+10;
//typedef long long ll;
//ll a[N];
//ll n,k;
////判断mid长度，能否满足要求
//bool cheack(ll x)
//{
//	ll cnt=k;
//	for(int i=n;i>0;i--)
//	{
//		if(a[i]<=x&&cnt>=0)return true;
//		//最长长度需要分割几次
//		int t=(a[i]+x-1)/x-1;
//		cnt-=t;
//		if(cnt<0)return false;
//		 
//	}
// } 
//int main()
//{
//	
//	cin>>n>>k;
//	ll mx=0;
//	for(int i=1;i<=n;i++)
//	{
//		cin>>a[i];
//		mx=max(mx,a[i]);//后续二分答案，找到右端点
//		 
//	}
//	//a[i]排序
//	sort(a+1,a+1+n); 
//	ll l=1,r=mx;
//	//二分答案 
//	while(l<r)
//	{
//		ll mid=(l+r)>>1;
//		if(cheack(mid))r=mid;
//		else
//		l=mid+1;
//	 } 
//	 cout<<l<<endl; 
//	return 0;
// } 
