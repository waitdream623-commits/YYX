//P1496 火烧赤壁
#include <iostream>
#include <algorithm>
#include <unordered_map> 
using namespace std;
const int N=1e5+10;
int n;
int a[N],b[N];
int pos;
int disc[N*2];
unordered_map<int,int>id;
int f[N*2];//差分数组 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		disc[++pos]=a[i],disc[++pos]=b[i];
	}
	sort(disc+1,disc+1+pos);
	//取重后续利用差分离散下标找到原来左右区间 
	pos=unique(disc+1,disc+1+pos)-(disc+1);
	for(int i=1;i<=pos;i++)
	{
		id[disc[i]]=i;
	 } 
	 //差分处理
	 for(int i=1;i<=n;i++)
	 {
	 	f[id[a[i]]]++;f[id[b[i]]]--;
	  }
	  //还原
	  for(int i=1;i<=pos;i++)
	  {
	  	f[i]+=f[i-1]; 
	   } 
	   //遍历求燃烧长度
	   int sum=0; 
	    for(int i=1;i<=pos;i++)
	    {
	    	if(f[i]<=0)continue;
	    	//找到第一个不是0 
	    	int j=i;
	    	while(j<=pos&&f[j]>0)j++;
	    	//j号的原位置存放在disc中
			int l=disc[i];int r=disc[j];
			// 累加长度的时候记得使用离散化之前的值
			sum+=r-l;
			i=j;
	    	
		}
		cout<<sum;
	
	return 0;
}


//离散化模板
//模板2
//#include <iostream>
//#include <algorithm>
//#include <unordered_map> 
//using namespace std;
//const int N=1e5+10;
//int a[N];
//int pos;
//int disc[N];//离散化数据顺序 
//unordered_map<int,int>id;
//int main()
//{
//	int n;cin>>n;
//	for(int i=1;i<=n;i++)
//	{
//		cin>>a[i];
//		disc[i]=a[i];
//	 } 
//	 sort(disc+1,disc+1+n);
//	 int index=0;
//	for(int i=1;i<=n;i++)
//	{
//		int x=disc[i];
//		if(id.count(x))continue;
//		index++;
//		id[x]=index;
//		
//	}
//	 for(int i=1;i<=n;i++)
//	 {
//	 	cout<<id[a[i]]<<endl;
//	 }
//	return 0;
// }  
//模板1
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//const int N=1e5+10;
//int a[N];
//int pos;
//int disc[N];//离散化数据顺序 
//int find(int x)//二分查找 
//{
//	int l=1,r=pos;
//	while(l<r)
//	{
//		int mid=(l+r+1)/2;
//		if(x>=disc[mid])l=mid;
//		else r=mid-1;
//	 } 
//	 return l;//返回序号 
//}
//int main()
//{
//	int n;cin>>n;
//	for(int i=1;i<=n;i++)
//	{
//		cin>>a[i];
//		disc[i]=a[i];
//	 } 
//	 sort(disc+1,disc+1+n);
//	 pos=unique(disc+1,disc+1+n)-disc-1;
//	 for(int i=1;i<=n;i++)
//	 {
//	 	cout<<find(a[i])<<endl;
//	 }
//	return 0;
// } 
