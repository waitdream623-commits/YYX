//P2327 [SCOI2005] 扫雷
#include <iostream>
#include<cstring>
using namespace std;
const int N=1e5;
int a[N],b[N];
int n;
bool check1()
{
	//a[1]=0;无炸弹
	for(int i=2;i<=n;i++)
	{
		a[i]=b[i-1]-a[i-1]-a[i-2];
		if(a[i]!=0&&a[i]!=1)return 0;
	 } 
	 //应该判断到n+1 
		a[n+1]=b[n]-a[n]-a[n-1];
		if(a[n+1]!=0)return 0; 
	 return 1;
}
bool check2()
{
	memset(a,0,sizeof(a));//重置 
	a[1]=1;
	for(int i=2;i<=n;i++)
	{
		a[i]=b[i-1]-a[i-1]-a[i-2];
		if(a[i]!=0&&a[i]!=1)return 0;
	 } 
	 //应该判断到n+1 
		a[n+1]=b[n]-a[n]-a[n-1];
		if(a[n+1]!=0)return 0; 
	 return 1;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>b[i];
	int ret=0;
	//根据a[1]两种情况顺势推理
	if(check1())ret++;
	if(check2())ret++; 
	cout<<ret; 
	return 0;
 } 



////P2010 [NOIP 2016 普及组] 回文日期
////方案3：枚举所以月和日，构成回文，判断是否处于范围内
//#include <iostream>
//
//using namespace std;
//int d[]={0,31,29,31,30,31,30,31,31,30,31,30,31};//0229属于闰年 
//int main() 
//{
//	int a,b;cin>>a>>b;
//	int ret=0;
//	for(int i=1;i<13;i++)
//	{
//		for(int j=1;j<=d[i];j++)
//		{
//			//将1231转换成1321； 
//			int year=i/10+i%10*10+j/10*100+j%10*1000;
//			if(year*10000+i*100+j<=b&&year*10000+i*100+j>=a)
//			{
//				ret++;
//			}
//		}
//	 } 
//	cout<<ret;
//	return 0;
//}
//
// 
//////方案2：枚举范围内所以年份，每年最多对应一个回文
////
////#include<iostream>
////using namespace std;
////int mon,day;
//// //判断日期合法
//// int d[]={0,31,29,31,30,31,30,31,31,30,31,30,31} ;
////bool cor(int year)
////{
////	//判断是否为闰年
////	if((year%4==0&&year%100!=0)||year%400==0)
////	{
////		d[2]=29;
////	}
////	else
////	d[2]=28;
////	if(mon<=12&&day<=d[mon])
////	{
////		return 1;
////	}
////	else return 0;
////}
////int main()
////{
////	int a,b;cin>>a>>b;
////	int ay=a/10000,by=b/10000;
////	int ret=0;
////	for(int i=ay;i<=by;i++)
////	{
////		mon=i/10%10+i%10*10;
////		day=i/1000+i/100%10*10;
////		if(cor(i))
////		{
////			//该回文是否在a,b之间
////			int x=i*10000+mon*100+day;
////			if(x>=a&&x<=b) 
////			ret++;
////		}
////	}
////	cout<<ret;
////	return 0;
//// } 
// 
////方案1：枚举范围内所有数
////
////#include <iostream> 
////
////using namespace std;
////int mon,day,year;
////
//////判断回文
////bool reverse()
////{
////	if(year==mon/10+mon%10*10+day%10*1000+day/10*100)
////	{
////		return 1;
////	}
////	return 0;
//// } 
//// int d[]={0,31,29,31,30,31,30,31,31,30,31,30,31} ;
//// //判断日期合法
////bool cor()
////{
////	//判断是否为闰年
////	if((year%4==0&&year%100!=0)||year%400==0)
////	{
////		d[2]=29;
////	}
////	else
////	d[2]=28;
////	if(mon<=12&&day<=d[mon])
////	{
////		return 1;
////	}
////	else return 0;
////}
////int main()
////{
////	int a,b;cin>>a>>b;
////	int ret=0;
////	for(int i=a;i<=b;i++)
////	{
////		//获取月和日；
////		mon=i/100%100;
////		day=i%100; 
////		year=i/10000;
////		if(reverse()&&cor())
////		{
////			ret++;
////		}
////	}
////	cout<<ret;
////	return 0;
////}
