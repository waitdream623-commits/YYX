////P3406 海底高铁
//#include <iostream>
//
//using namespace std;
//const int N=1e5+10;
//
//int a[N];
//int f[N][3];
//int main()
//{
//	int n,m;cin>>n>>m;
//	int x;cin>>x;
//	for(int g=1;g<m;g++)
//	{
//		//计算需要通过各个段的次数
//		int n;cin>>n;
//		//一段加加，利用差分数组
//		if(x>n)
//		{
//			a[n]+=1;
//			a[x]-=1;
//		 } 
//		 else
//		 {
//		 	a[x]+=1;
//		 	a[n]-=1;
//		 }
////		if(x>n)
////		{
////			for(int i=n;i<x;i++)
////			{
////				a[i]++;
////			}
////		}
////		else 
////		{
////			for(int i=x;i<n;i++)
////			{
////				a[i]++;
////			}
////		}
////		x=n;
//	}
//	//存储费用
//	long long sum=0; 
//	for(int i=1;i<n;i++)
//	{
//		cin>>f[i][1]>>f[i][2]>>f[i][3];
//		//并计算谁更优惠
//		a[i]=a[i]+a[i-1];//差分数组求出原结果 
//		sum+=min(a[i]*f[i][1],a[i]*f[i][2]+f[i][3]);
//	 } 
//	cout<<sum;
//	return 0;
//}

////【模板】差分
//#include<iostream>
//
//using  namespace std;
//typedef long long LL;
//const int N=1e5+10;
//LL a[N];
//LL f[N];//差分存储 
//int main()
//{
//	int n,m;cin>>n>>m;
//	for(int i=1;i<=n;i++)
//	{
////		cin>>a[i];
////		f[i]=a[i]-a[i-1];
//		int x;cin>>x;
//		f[i]+=x;
//		f[i+1]-=x;
//	}
//	while(m--)
//	{
//		int l,r,m;
//		cin>>l>>r>>m;
//		f[l]+=m;
//		f[r+1]-=m;
//	}
//	//输出最后结果
////	LL sum=0;
//	for(int i=1;i<=n;i++)
//	{
////		sum+=f[i];
////		cout<<sum<<' ';
//	f[i]=f[i]+f[i-1];
//	cout<<f[i]<<' ';
//	 } 
//	return 0;
// } 
