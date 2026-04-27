//P16226 [À¶ÇÅ±­ 2026 Ê¡ A] À¹½Ø³ÌÐò
#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

int main()
{
	ll T;cin>>T;
	while(T--)
	{
		ll l,v,t;
		cin>>l>>v>>t;
		ll p1=v*t;
		ll p2=l-p1;
		ll x=(p1+p2)/2;
		ll ret=max(abs(x-p1),abs(p2-x));
		cout<<ret<<endl; 
	}
	
	return 0;
 } 
