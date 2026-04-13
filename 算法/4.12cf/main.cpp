//B. The 67th 6-7 Integer Problem
#include<iostream>
#include<algorithm> 
#define int long long
using namespace std;

int a[8];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;cin>>T;
	while(T--)
	{
		for(int i=1;i<=7;i++)cin>>a[i];
		sort(a+1,a+8);
		int sum=0;
		for(int i=1;i<=7;i++)
		{
			if(i==7)sum+=a[i];
			else
			sum-=a[i];
		}
		cout<<sum<<endl;
	}
	
	return 0;
}



////A. The 67th Integer Problem
//
//#include<iostream>
//#define int long long
//using namespace std;
//
//
//signed main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	int T;
//	cin>>T;
//	while(T--)
//	{
//		int a;cin>>a;
//		if(a==67)
//		cout<<67<<endl;
//		else 
//		cout<<a+1<<endl;
//		
//	}
//	
//	return 0;
//}
