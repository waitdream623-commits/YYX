////P15968 电梯接客
#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
typedef pair<int,int>PII;
vector<PII>f;
bool cmp(PII a,PII b)
{
	return a.first<b.first;
}
signed main()
{
	ios::sync_with_stdio(false) ;
	cin.tie(0);
	int n,x,y,w;
	cin>>n>>x>>y>>w;//x为起始位置，y为目标位置，w为载重；
	f.push_back({-1,-1}); 
	for(int i=1;i<=n;i++)
	{
		int a,b;cin>>a>>b;
		f.push_back({a,b});
	}
	
	sort(f.begin(),f.end(),cmp);
    long long ret=0;
   //处理完整的
   for(int i=2;i<=n;i++)//起初电梯位置不确定，单独拿出1
   {
   	    int k=f[i].second/w;
        f[i].second%=w;
        ret+=(abs(y-f[i].first)+y-f[i].first)*k;
    
        
   }
	int j=1;
	while(j<=n)
	{
		//来到最低层和回去
         
            
    		ret+=(abs(x-f[j].first)+y-f[j].first);
    		int cap=w;
    		//路上尽可能接更多人 
    		while(cap-f[j].second>=0&&j<=n)
    		{
                cap-=f[j++].second;
    
    		}
        	if(j<=n)
            f[j].second -= cap;
        
    		x=y;
	 } 
	 cout<<ret;
	return 0;
}
////P15968 电梯接客
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#define int long long
//using namespace std;
//typedef pair<int,int>PII;
//vector<PII>f;
//bool cmp(PII a,PII b)
//{
//	return a.first<b.first;
//}
//signed main()
//{
//	ios::sync_with_stdio(false) ;
//	cin.tie(0);
//	int n,x,y,w;
//	cin>>n>>x>>y>>w;//x为起始位置，y为目标位置，w为载重；
//	f.push_back({-1,-1}); 
//	for(int i=1;i<=n;i++)
//	{
//		int a,b;cin>>a>>b;
//		f.push_back({a,b});
//	}
//	
//	sort(f.begin(),f.end(),cmp);
//    long long ret=0;
//	ret=abs(f[1].first-x);
//	int j=1; 
//	while(j<=n)
//	{
//		if(f[j].second>=w)
//		{
//            int k=f[j].second/w;
//			f[j].second-=w*k;
//            //回到y和来到j这层
//			ret+=(y-f[j].first)*2*k;
//            if(f[j].second==0)
//            {
//            	ret-=y-f[j].first;
//            	j++;
//            	//来到新j这层
//				ret+=y-f[j].first; 
//			}
//               
//		}
//		else
//		{
//			int a=w-f[j].second;//剩余空座 
//			//回到y
//            ret+=y-f[j].first;
//			j++;
//            while(a>=f[j].second&&j<=n)
//            {
//            	a-=f[j].second;
//            	j++;
//			}
//            //已经能一次运完不用加上返回消耗
//			if(j>n)
//			break; 
//			
//			f[j].second-=a;
//			//来到没拉完层数
//			ret+=y-f[j].first; 
//		}
//		
//	 } 
//	 cout<<ret;
//	return 0;
//}
