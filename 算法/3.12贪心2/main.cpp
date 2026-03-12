//P1056 [NOIP 2008 普及组] 排座椅

#include <iostream>
#include <algorithm>
using namespace std;
const int N=1110;
struct node{
	int index;
	int cnt;
}row[N],col[N];
bool comp1(node&x,node&y)
{
	return x.cnt>y.cnt;
}
bool comp2(node&x,node&y)
{
	return x.index<y.index;
}
int main()
{
	int m,n,k,l,d;cin>>m>>n>>k>>l>>d;
	int x,y,p,q;
	for(int i=1;i<=d;i++)
	{
		cin>>x>>y>>p>>q;
		if(x==p)
		{
			col[min(y,q)].cnt++;
			col[min(y,q)].index=min(y,q);
		}
		else
		{
			row[min(x,p)].cnt++;
			row[min(x,p)].index=min(x,p); 
		}
		
	}
	//从大到小排序cnt 
	sort(row+1,row+1+m,comp1);
	sort(col+1,col+1+n,comp1);
	//从小到达排序下标
	sort(row+1,row+1+k,comp2);
	sort(col+1,col+1+l,comp2);
	for(int i=1;i<=k;i++)
	cout<<row[i].index<<" ";
	cout<<endl;
	for(int i=1;i<=l;i++)
	cout<<col[i].index<<" ";
	
	return 0;
 } 
