//P2678 [NOIP 2015 提高组] 跳石头
#include<iostream>

using namespace std;
const int N=1e5+10;
int a[N];
int l,n,m;
int cheack(int x)
{
	int ret=0;
	int i=0,j=1;
	while(j<=n+1)
	{
		while(a[j]-a[i]<x&&j<=n+1)j++;
		ret+=j-i-1;
		i=j;
		j++;
	}
	return ret;
 } 
int main()
{
	cin>>l>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	 } 
	 a[n+1]=l;
	 int left=0,right=l;
	 while(left<right)
	 {
	 	int mid=(left+right+1)/2;
	 	if(cheack(mid)<=m)left=mid;
	 	else right=mid-1;
	 	
	 }
	 cout<<left;
	return 0;
}


////P1873 [COCI 2011/2012 #5] EKO / 砍树
//#include <iostream>
//
//using namespace std;
//typedef long long LL;
//const int N=1e6+10;
//int a[N];
//int n,m;
//
//LL cacl(int x)
//{
//	LL ret=0;
//	for(int i=1;i<=n;i++)
//	{
//		if(a[i]>x)
//		ret+=a[i]-x;
//	}
//	return ret;
//}
//int main()
//{
//	cin>>n>>m;
//	int mx=0;
//	for(int i=1;i<=n;i++)
//	{
//		cin>>a[i];
//		mx=max(mx,a[i]);
//	}
//	int left=1,right=mx;
//	while(left<right)
//	{
//		int mid=(left+right+1)/2;
//		if(cacl(mid)>=m)left=mid;
//		else right=mid-1;
//	}
//	cout<<left;
//	return 0;
//}

////P2440 木材加工
//
//#include<iostream>
//#include<algorithm>
//#include<cmath>
//using namespace std;
//const int N=1e5+10;
//
//long long a[N];
//int n,k;
//bool cheack(int x)
//{
//	int t=0; 
//	int le=1,y=n;
//	//找到大于等于x的第一个数 
//			while(le<y)
//			{
//				int mid=(le+y)/2;
//				if(a[mid]>=x)y=mid;
//				else le=mid+1;
//				
//			 } 
//			 for(int j=le;j<=n;j++)
//			 {
//			 	t+=floor(a[j]/x);
//			 	
//			 }
//			 if(t<k) return 0;
//			 	else return 1;
//			 
//}
//int main()
//{
//	cin>>n>>k;
//	long long sum=0;
//	long long  mx=0;
//	for(int i=1;i<=n;i++)
//	{
//		cin>>a[i];
//		sum+=a[i];
//		mx=max(mx,a[i]);
//	}
//	sort(a+1,a+1+n);
//	//最大长度
//	int l=min(sum/k,mx);
//	
//	int left=0,right=l;//二分查找等于k的长度 
//		while(left<right)
//		{
//			int mid=(left+right+1)/2;
//			if(cheack(mid))left=mid;
//			else right=mid-1; 
//		 } 
//		 cout<<left;
//	 
//	return 0;
// } //P2440 木材加工

//#include<iostream>
//#include<algorithm>
//#include<cmath>
//using namespace std;
//const int N=1e5+10;
//
//int a[N];
//int n,k;
//int main()
//{
//	cin>>n>>k;
//	long long sum=0;
//	for(int i=1;i<=n;i++)
//	{
//		cin>>a[i];
//		sum+=a[i];
//	}
//	sort(a+1,a+1+n);
//	//最大长度
//	int l=sum/k;
//	if(l<1)cout<<0;
//	else 
//	{
//		int flag=0; 
//		int t=k;//需要段数 
//		for(int i=l;i>=1;i--)
//		{
//			int left=1,right=n;
//			//找到大于等于l*j的数
//			 t=k; 
////			 for(int j=1;j<=k;j++)
////			 {
////			 	
////			 	while(left<right)
////			 	{
////			 		int mid=(left+right)/2;
////			 		if(a[mid]>=i*j)right=mid;
////			 		else left=mid+1;
////				  } 
////				  if(a[left]>=i*j)//判断只剩最后一位 
////				   t-=n-left+1;//分成段数 
////				   right=n;
////				  if(t<=0)
////				  {
////				  	flag=1;//最大长度达成 
////				  	break;
////				   } 
////			  } 
//			while(left<right)
//			{
//				int mid=(left+right)/2;
//				if(a[mid]>=i)right=mid;
//				else left=mid+1;
//				
//			 } 
//			 for(int j=left;j<=n;j++)
//			 {
//			 	t-=floor(a[j]/i);
//			 	if(t<=0)
//			 	{
//			 		flag=1;
//			 		break;
//				 }
//			 }
//			 
//			  if(flag)
//			  {
//			  	cout<<i;
//			  	break;
//			  }
//			
//		}
//	
//	 } 
//	
//	return 0;
// } 一个超时
