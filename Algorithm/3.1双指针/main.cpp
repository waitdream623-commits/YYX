//丢手绢
#include<iostream>

using namespace std;
typedef long long LL;
const int N=1e5+10;
int a[N];
int main()
{
	int n;cin>>n;
	LL sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	LL ret=0;
    LL x=0;
	for(int left=1,right=1;right<=n;right++)
	{
		
		x+=a[right];
        //找出顺逆最短
		while(x*2>=sum)
		{
			 
			ret=max(ret,sum-x);
			x-=a[left];
			left++;
		}
		ret=max(ret,x);
		
	}
	cout<<ret;
	return 0;
}


////字符串
//#include<iostream>
//
//using namespace std;
//int mp[128];
//int kind;
//int main()
//{
//	string s;
//	cin>>s;
//	int left=0,right=0;
//	int ret=0x3f3f3f3f;
//	while(right<s.size())
//	{
//		//进窗口
//		if(mp[s[right]]++==0)kind++;
//		while(kind==26)
//		{
//			ret=min(ret,right-left+1);
//			if(mp[s[left]]--==1)kind--;
//			left++;
//		 } 
//		 right++;
//	}
//	cout<<ret;
//	return 0;
// } 


////P1638 逛画展
//#include <iostream>
//#include <iostream>
//using namespace std;
//const int N=1e6+10;
//int a[N],p[N][2];
//
//int mp[N];
//int kind; 
//int main()
//{
//	int n,m;cin>>n>>m;
//	for(int i=1;i<=n;i++)cin>>a[i];
//	int left=1,right=1;
//	int ret=0x3f3f3f3f;
//	int begin=1,end=1;
//	while(right<=n)
//	{
//		//进入窗口
//		if(mp[a[right]]==0)kind++;
//		mp[a[right]]++;
//		while(kind==m)
//		{
//			//出窗口 
//			if(ret>right-left+1)//相同时不改变，前面小 
//			{
//				ret=right-left+1;
//				begin=left;end=right;
//			}
//			if(mp[a[left]]==1)kind--;
//			mp[a[left]]--;
//			left++;
//		}
//		right++;
//	}
//	cout<<begin<<' '<<end; 
//	return 0;
//}

////UVA11572 唯一的雪花 Unique Snowflakes
//#include <iostream>
//#include <unordered_map>
//using namespace std;
//const int N=1e6+10;
//int a[N];
//int main()
//{
//	int q;cin>>q;
//	while(q--)
//	{
//		int ret=0;
//		int n;cin>>n;
//		for(int i=1;i<=n;i++)cin>>a[i];
//		//双指针
//		int l=1,r=1;
//		unordered_map<int,int>mp;
//		while(r<=n)
//		{
//			//进窗口 
//			mp[a[r]]++;
//			//判断 
//			while(mp[a[r]]>1)
//			{
//				//出窗口
//				mp[a[l]]--;
//				l++; 
//				
//			}
//			
//			ret=max(ret,r-l+1);
//			r++;
//		 } 
//		 cout<<ret<<endl;
//	}
//	return 0;
//}

