//P1842 [USACO05NOV] 奶牛玩杂技
#include <iostream>
#include <algorithm>

using namespace std;
const int N=1e6;
struct node{
	int w;
	int s;
}a[N];
bool cmp(node&x,node&y)
{
	return x.w-y.s<y.w-x.s;
}
int main()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].w>>a[i].s;
	sort(a+1,a+1+n,cmp);
	int ret=-1e9-10;
	int sum=0;
	for(int i=1;i<=n;i++)//从第一个开始，为负数但其他力量远大于体重和，取第一位； 
	{
		ret=max(sum-a[i].s,ret);
		sum+=a[i].w;
	}
	cout<<ret;
	return 0;
}
////P2878 [USACO07JAN] Protecting the Flowers S
//
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//const int N=1e5+10;
//struct node{
//	int t;
//	int d;
//}a[N];
//bool cmp(node&x,node&y)
//{
//	return x.t * y.d < y.t * x.d;
//}
//int main()
//{
//	int n;cin>>n;
//	for(int i=1;i<=n;i++) cin>>a[i].t>>a[i].d;
//	sort(a+1,a+1+n,cmp);
//	long long time=a[1].t*2;
//	long long ret=0;
//	for(int i=2;i<=n;i++)
//	{
//		
//		ret+=a[i].d*time;
//		time+=a[i].t*2;
//	}
//	cout<<ret;
//	return 0;
//	
//}

////P1012 [NOIP 1998 提高组] 拼数
//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//string a[30];
//int n;
//bool comp(string x,string y)
//{
//	//32与321， 321>32而最大为32 321 
//	return x+y>y+x;
//}
//int main()
//{
//	cin>>n;
//	for(int i=1;i<=n;i++)
//	{
//		cin>>a[i];
//	}
//	sort(a+1,a+1+n,comp);
//	for(int i=1;i<=n;i++)cout<<a[i];
//	
//	return 0;
//}




////矩阵消除游戏
//
//#include <iostream>
//#include <cstring>
//#include<algorithm>
//using namespace std;
//int a[20][20];
//int row[20],col[20];
//int n,m,k;
//bool comp(int x,int y)
//{
//	return x>y;
// } 
// //求选择行数 
// int time(int x)
// {
// 	int ret=0;
// 	while(x)
// 	{
// 		ret++;
// 		x&=(x-1);
//	 }
//	 return ret;
// }
//int main()
//{
//	cin>>n>>m>>k;
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		{
//			cin>>a[i][j];
//			//处理行和 
//			row[i]+=a[i][j];
//		}
//		}
////			//求列和 
////		for(int i=1;i<=m;i++)
////	{
////		for(int j=1;j<=n;j++)
////		{
////			col[i]+=a[j][i];
////		}
////	} 
//		int ret=0;
//	//枚举选择行
//	for(int i=0;i<=(1<<n)-1;i++)
//	{
//		//记录行数
//		int num=time(i); 
//		if(num>k)continue; 
//		int sum=0;
//		//每一次需要修改列和 
//		memset(col,0,sizeof col);
//			for(int j=0;j<n;j++)
//		{
//			if((i>>j)&1==1)
//			{
//				sum+=row[j+1];
////				//修改数据
////				
////				for(int x=1;x<=m;x++)
////				{
////					col1[x]-=a[j+1][x];
////				}
//			}
//			else 
//			{
//				for(int x=1;x<=m;x++)
//				{
//					col[x]+=a[j+1][x];
//				}
//			}
//		}
//	//从大到小排序 
//	int t=min(m,k-num);//防止越界，可以将col大小设置更大 
//	sort(col+1,col+1+m,comp);
//	for(int y=1;y<=t;y++)
//	sum+=col[y];
//	ret=max(sum,ret); 
//	 	} 
//	cout<<ret;
//	return 0;
// } 
