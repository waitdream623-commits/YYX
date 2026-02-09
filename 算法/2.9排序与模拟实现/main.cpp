

#include<iostream>

using namespace std;
const int N=1e5+10; 
int n;
int arr[N];//从1开始存储
////插入排序
void insert_sort1(int arr[],int sz)
{
	for(int i=1;i<sz;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(arr[i]<arr[j])//如果比i比j小，就吧i放在j位置出，j到i-1往后移一位 
			{
					int t=arr[i];//保存i的值，需要后移 
				for(int z=i;z>j;z--)//往后放 
				{
					arr[z]=arr[z-1];
					}
				arr[j]=t; 
			}
		}
	}
}
 
void insert_sort2()
{
	for(int i=2;i<=n;i++)//遍历待排序元素 
	{
		int key=arr[i];
		int j=i-1;
		while(j>=1&&arr[j]>key)//满足时向后移
		{
			arr[j+1]= arr[j];
			j--;
		 } 
		 //结束时说明arr[j]<key;arr[j+1]>key//此时j+1已经向后移;
		 arr[j+1]=key; 
	 } 
 } 
 //选择排序
 void slection_sort()
 {
 	for(int i=1;i<n;i++)//待排序元素的首位置 
 	{	
 		int pos=i;
		 for(int j=i+1;j<=n;j++) 
 		{
			if(arr[j]<arr[pos])
			{
				pos=j;
			}
		 }
		 //结束找到最小
		 swap(arr[pos],arr[i]); 
	 }
  } 
  //冒泡排序
  void bubble_sort()
  {
  	int q=n-1;
  	while(q)
  	{
  		int flag=1; 
  		for(int i=1;i<=q;i++)//第一趟 交换n-1次，第二趟n-2次，最后一个已经是最大的了； 
		  {						//当q=1 
		  	if(arr[i]>arr[i+1])
		  	{
		  		swap(arr[i],arr[i+1]); 
		  		flag=0;//发生了交换，如果最后依然为1说明已经有序 
			  }
		   } 
		   if(flag)break;
		   q--; 
	  }
   } 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>arr[i]; 
	bubble_sort(); 
	for(int i=1;i<=n;i++)
	{
		cout<<arr[i]<<' ';
	}
	return 0;
 } 
