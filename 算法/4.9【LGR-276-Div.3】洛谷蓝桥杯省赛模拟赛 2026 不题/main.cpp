#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;   // 避免宏

const ll N = 1e5 + 10;
ll a[N], v[N];
ll sum[N];

int main() {
    ios::sync_with_stdio(false);
    ll n, m, k;
    cin >> n >> m >> k;
    for (ll i = 2; i <= n ; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
        
    }
    for(int i=1;i<=n;i++)
    {
    	cin>>v[i];
	}
priority_queue<ll, vector<ll>, greater<ll>> q;
    ll ret = 0;
    ll mx = 0;
    for (ll i = 1; i <= n; i++) {
    	
        
        	mx+=v[i];
            q.push(v[i]);
            while ((ll)q.size() > k) {
            	int t=q.top();q.pop();
            	mx-=t;
			}
			if(mx>=m)break;
        
       
        ll x = m - sum[i];
        if (x >= mx) ret = max(ret, mx);
        else ret = max(ret, x);
    }
    cout << ret;
    return 0;
}
////P15966 合成西瓜
////#include <bits/stdc++.h>
////using namespace std;
////#define int long long
////const int mod = 998244353;
////inline int qmi(int a, int b) {
////	int res = 1;
////	while (b) {
////		if (b & 1) {
////			res = res * a % mod;
////		}
////		a = a * a % mod;
////		b >>= 1;
////	}
////	return res;
////}
////signed main() {
////	ios::sync_with_stdio(false);
////	ios_base::sync_with_stdio(false);
////	cin.tie(0), cout.tie(0);
////	//f(n) = y + 1, f(n + 1) = f(n) + n = 2n, f(n + 2) = f(n + 1) + f(n) + n = 2n + n + n = 4n, f(n + 3) = f(n + 2) + f(n + 1) + f(n) + n = 4n +2n + 2n = 8n
////	int T;
////	cin >> T;
////	while (T--) {
////		int x, y;
////		cin >> x >> y;
////		if (x <= y) {
////			cout << "1\n";
////		} else {
////			cout << qmi(2, x - y - 1) * (y + 1) % mod << "\n";
////		}
////	}
////	return 0;
////}
//#include <iostream>
//#include <algorithm>
//#define int long long
//using namespace std;
//const int N=998244353;
//int qpow(int a,int b)//a^b;
//{
//	int t=1;
//	while(b)
//	{
//		if(b&1)
//		t=(t*a)%N;
//		a=(a*a)%N;
//		b>>=1;
//	}
//	return t%N;
//}
//signed main()
//{
//	ios::sync_with_stdio(0);
//	int T;cin>>T;
//	while(T--)
//	{
//		int x,y;cin>>x>>y;
//		if(y>=x)cout<<1<<endl;
//		else
//		{
//			cout<<((y+1)*qpow(2,x-y-1))%N<<endl;
//		}
//	}
//	
//	return 0;
//}
////P15964 编程比赛
//#include<iostream>
//#define int long long
//using namespace std;
//
//signed main()
//{
//	long long ret=0;
//	for(int i=1;i<=901234;i++)
//	{
//		long long x=789456+(i-1)*567890;//打完第一场
//		long long t=x-654321;//中间差的 
//			t/=876543;
//			t++;
//			x=500001-t;
//			if(x<=0)break;
//			else
//			ret+=x;
//		 
//	}
//	cout<<ret;
//	return 0;
//}

////P15963 日期统计
//#include <iostream>
//#include <map>
//using namespace std;
//int ret;
////月份
//int d[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
////2239 9 9到2239 12 31不可能存在 
////判断闰年
//bool is_leap(int x)
//{
//	if((x%4==0&&x%100!=0)||x%400==0)
//	return 1;
//	else
//	return 0;
// } 
// map<int,int>mp;
// //记录
// void m(int x)
// {
// 	while(x)
// 	{
// 		mp[x%10]++;
// 		x/=10;
//	 }
//  } 
//  //判断
//  bool cheack()
//  {
//  	int t=-1;
//  	
//  	
//	   
//  	for(auto e:mp)
//  	{
//  		if(t==-1)t=e.second;
//  		else
//  		if(t!=e.second)return 0;
//	  }
//	   return 1;
//   } 
//int main()
//{
//	
//	for(int y=2240;y<=9875;y++)
//	{
//		
//		if(is_leap(y))d[2]=29;
//		else d[2]=28; 
//		
//		for(int i=1;i<=12;i++)
//		{
//			
//			for(int j=1;j<=d[i];j++)
//            {
//                m(y);
//        		m(i);
//				m(j);
//			if(	cheack())ret++;
//				mp.clear();
//			}
//		 } 
//	}
//	cout<<ret;
//	return 0;
// } 
