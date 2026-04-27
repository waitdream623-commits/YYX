//P10387 [蓝桥杯 2024 省 A] 训练士兵
#include<iostream>
#include<map>
#include<vector>
#include <algorithm>
using namespace std;
typedef long long ll; 
const int N=1e6+10;
struct node{
	ll p,c;
}a[N]; 
ll sum[N];
bool cmp(node x,node y)
{
	return x.c<y.c;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,s;
	cin>>n>>s;
	ll cost=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].p>>a[i].c;//不能通过次数来寻找对应费用，会重复掉； 
		cost +=a[i].p;
	}
	sort(c+1,c+n+1,cmp);
	ll ret=0;
	ll cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(cost>s)
		{
			cnt=a[i].c;
		
			cost-=a[i].p;
		}
		else
		break;
	}
	ret=cnt*s;
	for(int i=1;i<=n;i++)
	{
		if(a[i].c<=cnt)continue;
		else
		ret+=(a[i].c-cnt)*a[i].p;
	}
	cout<<ret;
	return 0;
}
//#include<iostream>
//
//#include <map>
//using namespace std;
//long long d[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
//map<long long, long long> mp;
//
//long long cnt(long long x)
//{
//	long long t=0;
//	if(x<=9)
//	{
//		t+=mp[x]+mp[0];
//	}
//	else
//	{
//		while(x)
//		{
//			t+=mp[x%10];
//			x/=10;
//		}
//	}
//	return t;
//}
//signed main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	mp[0] = 13; mp[1] = 1; mp[2] = 2; mp[3] = 3; mp[4] = 5;
//mp[5] = 4; mp[6] = 4; mp[7] = 2; mp[8] = 2; mp[9] = 2;
//	long long ret=0;
//	long long flag=0;
//	for(long long y=2000;y<=2024;y++)
//	{
//		if((y%4==0&&y%100!=0)||y%400==0)d[2]=29;
//		else
//		d[2]=28;
//		for(long long m=1;m<=12;m++)
//		{
//			for(long long i=1;i<=d[m];i++)
//			{
//				if(flag)break;
//				if(y==2024&&m==4&&i==14)
//				{
//					flag=1;
//					break;
//				}
//				 int x=cnt(y)+cnt(m)+cnt(i);
//				if(x>50)ret++; 
//			}
//		}
//	}
//	cout<<ret;
//	return 0;
//}
