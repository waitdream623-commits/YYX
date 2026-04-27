//P3740 [HAOI2014] 贴海报
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
int n,m;
const int N=1e3+10;
int a[N],b[N];
int pos; 
int disc[N*4];//离散 
int w[N*4];//模拟贴海拔
bool st[N*4];//标记数据是否出现，统计数据种类 
unordered_map<int,int>id;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i]>>b[i];
		//防止离散化之后区间缩小 
		disc[++pos]=a[i],disc[++pos]=a[i]+1;
		disc[++pos]=b[i],disc[++pos]=b[i]+1;
		
	}
	sort(disc+1,disc+1+pos);
	int r=0;
	//进行离散化，标记新序号 
	for(int i=1;i<=pos;i++)
	{
		int x=disc[i];
		if(id.count(x))continue;//去重
		 r++;
		 id[x]=r;
	 }
	 //进行模拟贴海报 
	 for(int i=1;i<=m;i++)
	 {
	 	int l=id[a[i]],r=id[b[i]];
		 for(int j=l;j<=r;j++)
		 {
		 	w[j]=i;
		  } 
	  } 
	  //查看w中有多少个不同的数
//	  int ret=unique(w+1,w+1+pos)-(w+1);
//	  cout<<ret;
	int ret=0;
	for(int i=1;i<=pos;i++)
	{
		int x=w[i];
		if(!x||st[x])continue;//x是零和st出现过 
		ret++;
		st[x]=1; 
	 } 
	 cout<<ret;
	return 0;
 } 
