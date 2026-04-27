//Sqrt Problem

#include <iostream>

#include <cmath>
#include <map>
using namespace std;

map<long long ,long long >mp;
int main()
{
	long long n,k,x,q;
	cin>>x>>q;
	while(q--)
	{
		cin>>n>>k;
		int y=0;
		y=pow(floor(sqrt(n)),2);
		if(mp[floor(sqrt(n)].count()==0)
		{
			mp[floor(sqrt(n)]=y;
		}
		long long  ret=0;
		while(1)
		{
			if(k==0)break;
			if(sqrt(n)==floor(sqrt(n)))
			{
				n=sqrt(n);
				k--;
				ret++;
			}
			else n=n+2,ret++;
		}
		cout<<ret<<endl;
	}
	
	return 0;
 } 
