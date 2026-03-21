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
