//P1091 [NOIP 2004 提高组] 合唱队形
#include <iostream>

using namespace std;
const int N=110;
int a[N];
int f[N],g[N];//从左到右最长，从右到左 
int main()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	 } 
	
	//升序
	for(int i=1;i<=n;i++)
	{
		f[i]=1;
		for(int j=1;j<i;j++)
		{
			if(a[j]<a[i])f[i]=max(f[i],f[j]+1);
		}
		
		
		 }
	//降序
//最长不部分存在最小处，不对 
//	for(int i=1;i<=n;i++)
//	{
//		g[i]=1;
//		for(int j=1;j<i;j++)
//		{
//			if(a[j]>a[i])g[i]=max(1,g[j]+1);
//		}
//	 } 
//逆序处理
	for(int i=n;i>0;i--)
	{
		g[i]=1;
		for(int j=n;j>i;j--)
		{
			if(a[j]<a[i])g[i]=max(g[i],g[j]+1); 
		}
		
	 } 
	 int ret=0;
	 for(int i=1;i<=n;i++)
	 {
	 	ret=max(f[i]+g[i]-1,ret);
	 }
	 cout<<n-ret;
	return 0;
}



////【模板】最长上升子序列
////利用二分+贪心
//#include <iostream>
//
//using namespace std;
//const int N=1e5+10;
//int a[N];
//int f[N],len;//dp表表示链表长度为i的最小末尾，最长长度 
// 
//int main()
//{
//	int n;cin>>n;
//	for(int i=1;i<=n;i++)cin>>a[i];
//	for(int i=1;i<=n;i++)
//	{
//		//初始放入第一个，或者寻找最长值 
//		if(len==0||a[i]>f[len])f[++len]=a[i];
//		//贪心优化，为上面寻找最大len 
//		else
//		{
//			//二分查找大于前一个长度的下一位，然后替换原先
//			//相同长度后加入一定小于之前，贪心策略 
//			 int l=1,r=len;
//			 while(l<r)
//			 {
//			 	int mid=(l+r)/2;
//				 if(f[mid]>=a[i])r=mid;
//				 else l=mid+1; 
//			  } 
//			  f[l]=a[i];
//		}
//		}	
//	cout<<len;
//	return 0;
// } 



////B3637 最长上升子序列
//
//#include <iostream>
//
//using namespace std;
//const int N=1e4;
//int a[N];
//int f[N];//i号位值，所能构成最长长度 
//int main()
//{
//	int n;cin>>n;
//	for(int i=1;i<=n;i++)cin>>a[i];
//	int ret=0;
//	for(int i=1;i<=n;i++)
//	{
//		f[i]=1;
//		for(int j=1;j<i;j++)
//		{
//			if(a[i]>a[j])
//			f[i]=max(f[i],1+f[j]);
//		}
//		ret=max(ret,f[i]);
//	 } 
//	cout<<ret; 
//	return 0;
// } 
