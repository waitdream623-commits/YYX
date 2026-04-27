#include<iostream>
#include<set>

using namespace std;
int a[]={90,30,50,40,10,20,70,60,80};
int main()
{
	set<int>mp;
	//≤Â»Î 
	for(auto e:a)
	{
		mp.insert(e);
	}
	for(auto e:mp)
	{
		cout<<e<<' '; 
	}
	cout<<endl;
	//≤È’“
	if(mp.count(10))cout<<10<<endl; 
	//…æ≥˝
	mp.erase(10);
	
	for(auto e:mp)
	{
		cout<<e<<' ';
	}
	cout<<endl;
	 
	 auto x=mp.lower_bound(20);
	 cout<<*x<<endl;
	return 0;
 } 
