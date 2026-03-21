//P1228 地毯填补问题
#include <iostream>

using namespace std;
int k,x,y;
void dfs(int a,int b,int len,int x,int y)
{
	
	//递归出口 
	if(len==1)return;
	//划分当长度为2，调用时len=1，直接返回 
	len/=2; 
	//左上
	if(x<a+len&&y<b+len)
	{
		cout<<a+len<<' '<<b+len<<' '<<1<<endl;
//		dfs(1,1,len,x,y);递归调用传入左上角坐标 
		dfs(a,b,len,x,y);
		dfs(a,b+len,len,a+len-1,b+len);
		dfs(a+len,b,len,a+len,b+len-1);
		dfs(a+len,b+len,len,a+len,b+len);
	 } 
	//右下
	else if(x>=a+len&&y>=b+len)
	{
		cout<<a+len-1<<' '<<b+len-1<<" "<<4<<endl;
		dfs(a,b,len,a+len-1,b+len-1);
		dfs(a,b+len,len,a+len-1,b+len);
		dfs(a+len,b,len,a+len,b+len-1);
		dfs(a+len,b+len,len,x,y);
	 } 
	 //左下 
	 else if(x>=a+len)
	 {
	 	cout<<a+len-1<<' '<<b+len<<' '<<3<<endl;
	 	dfs(a,b,len,a+len-1,b+len-1);
		dfs(a,b+len,len,a+len-1,b+len);
		dfs(a+len,b,len,x,y);
		dfs(a+len,b+len,len,a+len,b+len);
	 }
	 //右上 
	 else
	{
		cout<<a+len<<' '<<b+len-1<<' '<<2<<endl;
		dfs(a,b,len,a+len-1,b+len-1);
		dfs(a,b+len,len,x,y);
		dfs(a+len,b,len,a+len,b+len-1);
		dfs(a+len,b+len,len,a+len,b+len);
	}
 } 
int main()
{
	cin>>k>>x>>y;
	k=(1<<k);
	dfs(1,1,k,x,y);//左上角（1，1）长度为k，障碍（x，y） 
	
	return 0;
}


////P1115 最大子段和
//#include <iostream>
//#include <algorithm>
//using namespace std;
//const int N=2*1e5+10;
//int a[N];
//int n;
//int dfs(int l,int r)
//{
//	if(l==r)return a[l];
//	int mid=(l+r)/2;
//	int ret=max(dfs(l,mid),dfs(mid+1,r));
//	//一左一右
//	//左 
//	int sum=a[mid];int lmax=a[mid];
//	for(int i=mid-1;i>=l;i--)
//	{
//		
//		sum+=a[i];
//		 lmax=max(sum,lmax);
//	 } 
//	 //右 
//	 sum=a[mid+1];int rmax=a[mid+1];
//	 for(int i=mid+2;i<=r;i++)
//	{
//		sum+=a[i];
//	 rmax=max(sum,rmax);
//	 } 
//	ret=max(ret,lmax+rmax);
//	return ret;
//}
//int main()
//{
//	cin>>n;
//	for(int i=1;i<=n;i++)
//	{
//		cin>>a[i];
//	}
//	cout<<dfs(1,n);
//	return 0;
// } 

////P1923 【深基9.例4】求第 k 小的数
//
//#include <iostream>
//#include <ctime>
//using namespace std;
//const int N=5*1e6+10;
//int a[N];
//int n,m;
//int get_rand(int left,int right)
//{
//	return a[rand()%(right-left+1)+left];
//}
//int qchoose(int left,int right,int k)
//{
//	if(left>=right)return a[left];
//	int p=get_rand(left,right);
//	int l=left-1,i=left,r=right+1;
//	while(i<r)
//	{
//		if(a[i]<p)swap(a[i++],a[++l]);
//		else if(a[i]==p)i++;
//		else 
//		swap(a[i],a[--r]);
//	}
//	int x=l-left+1,b=r-1-l,c=right-r+1;
//	if(k<=x) return qchoose(left,l,k);
//	else if(k<=x+b)return p;
//	else return qchoose(r,right,k-x-b);
// } 
//int main()
//{
//    ios::sync_with_stdio(false);
//	srand(time(0));
//	cin>>n>>m;
//	for(int i=1;i<=n;i++)
//	{
//		cin>>a[i];
//	 } 
//	 //最小为第0小 
//	 cout<<qchoose(1,n,m+1);//在1到n区间选择第m小 
//	return 0;
// } 
