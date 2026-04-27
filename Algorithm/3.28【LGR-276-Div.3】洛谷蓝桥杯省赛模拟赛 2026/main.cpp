////T618438 电梯接客
//#include<iostream>
//#incldue <vector>
//using namespace std;
//int n,x,y,w;
//pair<int,int>a[];
//int main()
//{
//	cin>>n>>x>>y>>w;
//	for(int i=1;i<=n;i++)
//	{
//		int a,b;cin>>a>>b;
//		q.push_back({a,b});
//	}
//	int ret=0;
//	sort(q.begin(),q.end());
//	
//	
//	return 0;
//}


//////T632594 采矿文明
//#include<iostream>
//
//using namespace std;
//const int N=1e5+10;
//int f[N];
//int a[N];
//int ret;
//int n,m,k,sum;
//void dfs(int begin,int path)
//{
//	
//	if(path>k)
//	{
//		ret=max(ret,sum);
//		return;
//	} 
//	if(f[begin]+sum+a[begin]<m)
//		{
//			sum+=a[begin];
//		
//		} 
//		//不能再往下走 
//		 else//此时返回上一层如何复原 
//		{
////	 	sum+=m-f[begin]-sum;
////	 	ret=max(sum,ret);
//		sum+=a[begin];
//		ret=max(ret,m-f[begin]); 
//	 	return;
//	 	}
//		
//	  
//	for(int i=begin+1;i<=n;i++)
//	{
//		dfs(i,path+1);
//		//复原，下一层dfs加上的a[i+1] 
//		sum-=a[i];
//	}
//	//退出时计算路费
//
//
//}
//int main()
//{
//	cin>>n>>m>>k;
//	//组合，费用使用前缀和
//	 for(int i=2;i<=n;i++)
//	 {
//	 	int x;cin>>x;
//	 	f[i]=f[i-1]+x;
//	  } 
//	  for(int i=1;i<=n;i++)
//	  {
//	  	cin>>a[i];
//	  }
//	  //选择k个，返回矿石数量 
//	dfs(1,1); 
//	cout<<ret;
//	return 0;
//}


////T575086 合成西瓜
//#include<iostream>
//
//using namespace std;
//int mod=998244353;
//int main()
//{
//	int T;cin>>T;
//	int ret=0;
//	while(T--)
//	{
//		int x,y;cin>>x>>y;
//		ret=y+1;
//		for(int i=y+1;i<x;i++)
//		{
//			ret+=i%mod;
//		}
//		cout<<ret%mod<<endl;
//	}
//	
//	return 0;
//}


////T623315 跳柱文明
//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	int T;cin>>T;
//	while(T--)
//	{
//		int n,x;cin>>n>>x;
//		int pre;cin>>pre;
//		int flag=1;
//		for(int i=2;i<=n;i++)
//		{
//			int t;cin>>t;
//			if(t>=pre)
//			{
//				if(t-pre<=1)pre=t;
//				else if(flag)cout<<"Lose",flag=0;
//			}
//			else {
//				if(pre-t<=x)
//				{
//					pre=t;
//				}
//				else if(flag)
//				{
//					cout<<"Lose";
//					flag=0; 
//				}
//				
//			}
//		}
//		if(flag)cout<<"Win";
//		cout<<endl;
//	 } 
//	
//	return 0;
//}


////T735807 日期统计
//#include<iostream>
//#include <map>
//using namespace std;
//int d[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
//bool is_year(int x)
//{
//	if(x%4==0&&x%100!=0)
//	return true;
//	if(x%400==0)return true;
//	
//	return false; 
// } 
//int main()
//{
//	int ret=0;
//		for(int i=2239;i<=2239;i++)
//	{
//		
//	
//		if(is_year(i))d[2]=29;
//		else d[2]=28;
//		for(int j=9;j<=12;j++)
//		{
//			
//			for(int k=9;k<=d[j];k++)
//			{
//				int flag=1;
//			map<int,int>mp;
//			int x=i;
//			while(x)
//			{
//			mp[x%10]++;
//			x/=10;
//			}	
//			int a=j;
//			while(a)
//			{
//			mp[a%10]++;
//			a/=10;
//			}	
//			int t=j;
//			while(t)
//			{
//			mp[t%10]++;
//			t/=10;
//			}
//			int tmp=mp[j%10];
//			for(int p=1;p<=9;p++)
//			{
//				if(mp[p]!=0)
//				if(tmp!=mp[p])
//				{
//					flag=0;break;
//				}
//				
//			}
//				if(flag)ret++; 
//			} 
//		}
//	}
//	
//	
//	
//	for(int i=2240;i<=9876;i++)
//	{
//		
//	
//		if(is_year(i))d[2]=29;
//		else d[2]=28;
//		for(int j=1;j<=12;j++)
//		{
//			
//			for(int k=1;k<=d[j];k++)
//			{
//				int flag=1;
//			map<int,int>mp;
//			int x=i;
//			while(x)
//			{
//			mp[x%10]++;
//			x/=10;
//			}	
//			int a=j;
//			while(a)
//			{
//			mp[a%10]++;
//			a/=10;
//			}	
//			int t=j;
//			while(t)
//			{
//			mp[t%10]++;
//			t/=10;
//			}
//			int tmp=mp[j%10];
//			for(int p=1;p<=9;p++)
//			{
//				if(mp[p]!=0)
//				if(tmp!=mp[p])
//				{
//					flag=0;break;
//				}
//				
//			}
//				if(flag)ret++; 
//			} 
//		}
//	}
//	cout<<ret;
//	return 0;
//}
////

