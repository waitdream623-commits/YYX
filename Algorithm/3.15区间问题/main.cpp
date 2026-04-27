//P2859 [USACO06FEB] Stall Reservations S
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int N=1e5+10;
struct node{
	int x,y,index,r;//r表示安排牛棚 
}a[N];
typedef pair<int,int>PII;
priority_queue<PII,vector<PII>,greater<PII>>heap;
bool cmp1(node&x,node&y)
{
	return x.x<y.x;
}
bool cmp2(node& x,node& y)
{
	return x.index<y.index;
}
int main()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].y,a[i].index=i;
	//按左开始排序 
	sort(a+1,a+1+n,cmp1);
	int ret=1;
	a[1].r=1;
	heap.push({a[1].y,a[1].r});
	 //结束时间放入小根堆中 
	for(int i=2;i<=n;i++)
	{
		if(a[i].x>heap.top().first)//可以重复放置
		{
			a[i].r= heap.top().second;
			heap.pop();//处理上一个已经放过的 
			heap.push({a[i].y,a[i].r});
		}
		else
		{
			ret++;
			a[i].r=ret;
			heap.push({a[i].y,a[i].r});
		}
	}
	cout<<ret<<endl;
	//按下标排序
	sort(a+1,a+1+n,cmp2); 
	for(int i=1;i<=n;i++)
	cout<<a[i].r<<endl;
	
	return 0;
}

////P2859 [USACO06FEB] Stall Reservations S
//#include <iostream>
//#include <cmath>
//#include <algorithm>
//using namespace std;
//struct node{
//	int x,y;
//}a[2520],b[2520];
//bool cmp(node& x,node& y)
//{
//	return x.x>y.x;
//}
//int main()
//{
//	int n,m;cin>>n>>m;
//	for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].y;
//	for(int i=1;i<=m;i++)cin>>b[i].x>>b[i].y;
//	sort(a+1,a+1+n,cmp);
//	sort(b+1,b+1+m,cmp);
//	int ret=0;
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		{
//			if(b[j].y==0)continue;//用完了
//			if(b[j].x<a[i].x)break;
//			if(b[j].x>a[i].y)continue;
//			//找到匹配防晒 
//			ret++;
//			b[j].y--;
//			break; 
//		}
//	 } 
//	 cout<<ret; 
//	return 0;
//}

////UVA1193 Radar Installation
//#include <iostream>
//#include <cmath>
//#include <algorithm>
//using namespace std;
//typedef pair<double,double>PII;
//PII a[1110];
//
//int main()
//{
//	int n,d;
//	int count=0;
//	while(cin>>n>>d,n&&d)
//	{
//		count++;
//		int flag=0;
//		for(int i=1;i<=n;i++)
//		{
//			int x,y;cin>>x>>y;
//			if(y>d)flag=1;
//			double l=sqrt(d*d-y*y);
//			a[i].first=x-l;a[i].second=x+l;
//		}
//		cout<<"Case "<<count<<": ";
//		if(flag)cout<<-1<<endl;
//		else 
//		{
//			sort(a+1,a+1+n);
//			int ret=1;
//			double r=a[1].second;
//			for(int i=2;i<=n;i++)
//			{
//				if(a[i].first<=r)
//				{
//					r=min(r,a[i].second);
//				}
//				else 
//				{
//					ret++;
//					r=a[i].second;
//				}
//			}
//			cout<<ret<<endl;
//		 } 
//	}
//	return 0;
//}


////P1803 凌乱的yyy / 线段覆盖
//#include <iostream>
//
//#include <algorithm>
//
//using namespace std;
//int n;
//const int N=1e6+10;
//typedef pair<int,int> PII;
//PII a[N]; 
//int main()
//{
//	cin>>n;
//	for(int i=1;i<=n;i++)cin>>a[i].first>>a[i].second;
//	sort(a+1,a+1+n);
//	int ret=1;
//	int r=a[1].second;
//	for(int i=2;i<=n;i++)
//	{
//		if(a[i].first<r)
//		{
//			r=min(r,a[i].second);
//		}
//		else 
//		{
//			ret++;
//			r=a[i].second;
//		}
//	}
//	cout<<ret;
//	return 0;
//}
