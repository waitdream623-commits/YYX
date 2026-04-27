//P1678 烦恼的高考志愿
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+10;
int school[N],stu[N];
int n,m;
int deal(int x)
{
	int left=1,right=n;
	//找到大于等于x的第一个数 
	while(left<right)
	{
		int mid=(left+right)/2;
		if(school[mid]>=x)right=mid;
		else left=mid+1;
	}
	if(left==1)
	return abs(school[1]-x);//或者加上左护法 
	return min(abs(school[left]-x),abs(school[left-1]-x));
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>school[i];
	sort(school+1,school+1+n);
	long long  ret=0;
	while(m--)
	{
		int x;cin>>x;
		//寻找离x最近的数的 
		ret+=deal(x); 
	}
	cout<<ret;
	return 0;
}

////P1102 A-B 数对
//#include<iostream>
//#include<algorithm>
//using namespace std;
//const int N=2*1e5+10;
//int a[N];
//int main()
//{
//	int n,c;cin>>n>>c;
//	for(int i=1;i<=n;i++)cin>>a[i];
//	int ret=0;
//	sort(a+1,a+1+n);
//	for(int i=1;i<=n;i++)
//	{
//		int x=a[i]+c;
//		auto r=lower_bound(a+i,a+1+n,x);
//		auto l=upper_bound(a+i,a+1+n,x);
//		ret+=l-r;
//	}
//	cout<<ret;
//	return 0;
//}

////牛可乐和魔法封印
//#include<iostream>
//#include<algorithm>
//using namespace std;
//const int N=1e5+10;
//
//int a[N];
//int main()
//{
//	int n;cin>>n;
//	for(int i=1;i<=n;i++)cin>>a[i];
//	int q;cin>>q;
//	while(q--)
//	{
//		int x,y;cin>>x>>y;
//		auto l=lower_bound(a+1,a+1+n,x);
//		auto r=upper_bound(a+1,a+1+n,y);
//		cout<<r-l<<endl;
//	}
//	return 0;
// } 
