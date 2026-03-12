//P1094 [NOIP 2007 普及组] 纪念品分组
#include<iostream>
#include<algorithm>
using namespace std;
const int N=3e4+10;
int a[N];
int main()
{
	int k,n;cin>>k>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int l=1,r=n; 
	//最多两个为一组 
	int ret=0;
	while(l<=r)//取等，当奇数时需要加一 
	{
		if(a[l]+a[r]<=k)l++,r--;
		else r--;
		ret++;
	}
	cout<<ret; 
	return 0;
 } 


////P1115 最大子段和
//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	int n;cin>>n;
//	int sum=0;int ret=-1e6;
//	for(int i=1;i<=n;i++)
//	{
//		int x;cin>>x;
//		sum+=x;
//		ret=max(ret,sum);
//		if(sum<0)sum=0;
//		}
//		cout<<ret;	
//	return 0;
// } 


////P10452 货仓选址
//#include <iostream>
//#include<algorithm>
//using namespace std;
//const int N=1e5+10; 
//int a[N];
//int main()
//{
//	int n;cin>>n;
//	for(int i=1;i<=n;i++)cin>>a[i];
//	sort(a+1,a+1+n);
//	int ret=0;
//	for(int i=1;i<=n/2;i++)
//	{
//		ret+=abs(a[i]-a[n+1-i]);
//	}
//	cout<<ret;
//	
//	return 0;
//}

