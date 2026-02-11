#include <iostream>
#include <ctime>//创造随机数
#include<utility>
using namespace std;
int n;
const int N=1e5+10;

int arr[N];

//选取随机基准元素
int get_rand(int left,int right)
{
	return arr[rand()%(right-left+1)+left];//返回随机数范围为[left,right] 
 } 
 
 void quick_sort(int left,int right)
 {
 	if(left>=right)return;//区间为1或者区间不存在
	 //选择基准点
	 int p=get_rand(left,right);//交换后，p位置大小改变 
	 //区间分三块
	 int l=left-1;int i=left;int r=right+1;
	 while(i<r)
	 {
	 	if(arr[i]<p)swap(arr[++l],arr[i++]);
	 	else if(arr[i]==p)i++;
	 	else swap(arr[i],arr[--r]);//i不能加，right位置交换过来元素未检查 
	  } 
	  //结束分为[left,l][l+1,r-1][r ,right]
	  quick_sort(left,l);
	  quick_sort(r,right);
 }
 
 int main()
 {
 	cin>>n;
 	srand(time(0));
 	for(int i=1;i<=n;i++)cin>>arr[i];
 	
 	quick_sort(1,n);
	 
	 for(int i=1;i<=n;i++)cout<<arr[i]<<' '; 
 	return 0;
 }
