#include <iostream>

using namespace std;
const int N=1e5+10;
int n;
int a[N];
int tmp[N]; 
void merge_sort(int left,int right)
{
	int mid=(right-left)/2+left;//取中间元素分两边，偶数个为前一个
	if(right<=left) return;
	merge_sort(left,mid);
	merge_sort(mid+1,right);
//	//分为左右两边，最后为一个或者没有，合并为有序，后续每个部分均有序
//	int i=mid,r=right,l=left;
//	while(r>=left){
//		if(a[i]>a[r])swap(a[i],a[r--]);
//		else if(a[r]>a[i])r--;
//		else i--; 
//	}
	//利用辅助数组 
	int cur1=left,cur2=mid+1,i=left;
	while(cur1<=mid&&cur2<=right)
	{
		if(a[cur1]<=a[cur2]) tmp[i++]=a[cur1++];
		else tmp[i++]=a[cur2++];
	}
	while(cur1<=mid) tmp[i++]=a[cur1++];
	while(cur2<=right) tmp[i++]=a[cur2++];
	//传回原数组
	for(int j=left;j<=right;j++)
	{
		a[j]=tmp[j];
	 } 
	
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	
	merge_sort(1,n);
	for(int i=1;i<=n;i++)cout<<a[i]<<' ';
	return 0;
}

