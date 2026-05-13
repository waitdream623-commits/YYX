//只能交换相邻，冒泡排序(超时)
//先用sort排序，找每个数据相对位置；不行，多算了，
// #include <algorithm>
// #include <cstdlib>
// #include <iostream>
// #include <map>
// #include <utility>
// using namespace std;
// typedef long long ll;
// typedef unsigned long long ull;
// typedef pair<int,int>PII;
// int INF=0x3f3f3f3f;
// const int N = 1e6 + 10;
// int a[N];
// int main() {

//   ios::sync_with_stdio(false);
//   cin.tie(nullptr);
//   int n;cin>>n;
//   map<int, int>mp;//记录原先下标
//   for(int i=1;i<=n;i++)
//   {
//     cin>>a[i];
//     mp[a[i]]=i;
//   }
//   sort(a+1,a+1+n);
//   int ans=0;
//   for(int i=1;i<=n;i++)
//   {
//     ans+=abs(mp[a[i]]-i);
//   }
//   cout<<ans/2;
//   return 0;
// }

// int main() {

//   ios::sync_with_stdio(false);
//   cin.tie(nullptr);
//   int n;cin>>n;
//   for(int i=1;i<=n;i++)
//   {
//     cin>>a[i];
//   }
//   //冒泡排序
// ll ret=0;
  
//   for(int j=n;j>=2;j--)
//  {
//   int flag=1;
//   //单次
//    for(int i=2;i<=j;i++)
//   {
//     if(a[i]<a[i-1])
//     {
//       swap(a[i],a[i-1]);
//       flag=0;
//       ret++;
//       //此时最大的在最后
//     }
//   }
//   if(flag)//没有交换
//   break;
//  }
//  cout<<ret;
//   return 0;
// }
//P1908 逆序对

#include <iostream>

using namespace std;
const int N=5*1e5+10;
int n;
int a[N];
int tmp[N];
long long  dfs(int left,int right)
{
	if(right<=left) return 0;
	int mid=(left+right)>>1;
	long long ret=0;
	ret+=dfs(left,mid);
	ret+=dfs(mid+1,right);
	//逆序对分为左区间，右区间，一左一右边
	//一左一右
	int cur1=left,cur2=mid+1,i=left;
	//归并排序，计算逆序对 
	while(cur1<=mid&&cur2<=right)
	{
		if(a[cur1]<=a[cur2])tmp[i++]=a[cur1++] ;
		else 
		{
			tmp[i++]=a[cur2++];
			ret+=(mid-cur1+1);
		}
	 } 
	 while(cur1<=mid)tmp[i++]=a[cur1++]; 
	 while(cur2<=right)tmp[i++]=a[cur2++]; 
	 for(int j=left;j<=right;j++)a[j]=tmp[j];
	 return ret;
	
	
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	//利用分治，分为左右区间
	cout<<dfs(1,n); 
	return 0;
 } 