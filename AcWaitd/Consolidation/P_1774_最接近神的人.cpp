//只能交换相邻，冒泡排序(超时)
//先用sort排序，找每个数据相对位置；不行，多算了，
//归并排序，分治
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <utility>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
int a[N],tmp[N];
ll merge_sort(int l,int r)
{
	if(l>=r)return 0;
	ll ret=0;
	int mid=(l+r)/2;
	ret+=merge_sort(l,mid);
	ret+=merge_sort(mid+1,r);
	//处理合并后逆序对个数
	int cur1=l,cur2=mid+1;
	int pos=l;//起始为l，左区间
	while(cur1<=mid&&cur2<=r)
	{
		if(a[cur1]<=a[cur2])
		{
			tmp[pos++]=a[cur1++];
		}
		else
		{
			tmp[pos++]=a[cur2++];
			ret+=(mid-cur1+1);//这之间全是逆序对
		}
	}
	//处理剩下的		
	while(cur1<=mid)
	tmp[pos++]=a[cur1++];
	while(cur2<=r)
	tmp[pos++]=a[cur2++];
	for(int i=l;i<pos;i++)a[i]=tmp[i];//起始
	return ret;
}
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>a[i];
  }
 cout<<merge_sort(1,n);
  return 0;
}

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
