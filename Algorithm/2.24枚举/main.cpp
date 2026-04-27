#include <iostream>

using namespace std;

const int N=1e4+10;
int a[N],b[N],x[N],y[N];

int main()
{
	//输入 
	int q;cin>>q;
	for(int i=1;i<=q;i++)
	{
		cin>>a[i]>>b[i]>>x[i]>>y[i];
	 } 
	 int m,n;cin>>m>>n;
	 //逆序枚举，包含（m，n）即为最上方
	 int i=0;
	 for(i=q;i>0;i--)
	 {
	 	if(a[i]<=m&&b[i]<<n&&a[i]+x[i]>=m&&b[i]+y[i]>=n)
	 	break;
	  } 
	  if(i==0)
	  cout<<-1;
	  else
	  cout<<i;
	return 0;
 } 
