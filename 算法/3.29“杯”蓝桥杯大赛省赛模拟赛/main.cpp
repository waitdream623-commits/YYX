//试题B:矩阵染色
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<queue>

using namespace std;
typedef pair<int,int>PII;
const int N=1e5+10;
int a[6][5]={1,1,2,1,1,
             1,1,1,2,1,
             2,1,2,1,1,
             1,2,1,1,2,
             1,1,1,2,1,
             1,1,1,1,1};//横着 
int b[5][6]={1,1,1,2,1,1,
			 1,2,2,1,2,2,
			 1,2,1,2,2,1,
			 1,1,2,2,1,2,
			 1,1,1,1,2,2};//竖着 
bool st1[100][100],st2[100][100];
int ret;
void dfs(int x,int y,int pos)
{
	if(pos>3)
	{
		ret++;
		return;
	}
	for(int i=x;i<=5;i++)
	{
		for(int j=y;j<=6;j++)
		{
			if(a[i][j]==1&&!st1[i][j])
			{
				st1[i][j]=1;
				dfs(i,j+1,pos+1);
				st1[i][j]=0;
				
			 } 
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); 
	dfs(1,1,1);
	cout<<ret;
	return 0;
}


////试题F:好段计数
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//#include<string>
//#include<cmath>
//#include<vector>
//#include<queue>
//
//using namespace std;
//typedef pair<int,int>PII;
//const int N=2e5+10;
//int a[N];
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	int T;cin>>T;
//	while(T--)
//	{
//		int ret=0;
//		int n;cin>>n;
//		for(int i=1;i<=n;i++)
//		{
//			cin>>a[i];
//		}
//		int l=1,r=n;
//		while(l<=n)
//		{
//			int mx=a[l];
//			int cnt=1;
//			for(int i=l;i<=n;i++)
//			{
//				
//				mx=max(a[i],mx);
//				if(mx==cnt)ret++;
//				cnt++;
//			}
//			l++;
//			
//		}
//		cout<<ret<<endl;
//	}
//	return 0;
//}
////试题H:双机器人
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//#include<string>
//#include<cmath>
//#include<vector>
//#include<queue>
//
//using namespace std;
//typedef pair<int,int>PII;
//const int N=1e5+10;
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	int T;cin>>T;
//	while(T--)
//	{
//		int n;cin>>n;
//		int a=0,b=0;
//		int ret=0;
//		for(int i=1;i<=n;i++)
//		{
//			int x;cin>>x;
//			if(abs(x-a)<=abs(x-b))
//			ret+=abs(x-a),a=x;
//			else
//			ret+=abs(x-b),b=x;
//				}
//				cout<<ret<<endl;		
//		
//	}
//	return 0;
//}

////小苯的擂台轮转
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//#include<string>
//#include<cmath>
//#include<vector>
//#include<queue>
//
//using namespace std;
//typedef pair<int,int>PII;
//const int N=1e5+10;
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	int T;cin>>T;
//	while(T--)
//	{
//		queue<int>q;
//		int n,k;cin>>n>>k;
//		for(int i=1;i<=n;i++)
//		{
//			int x;cin>>x;
//			q.push(x);
//		}
//		int top=q.front();
//		q.pop();
//		while(k--)
//		{
//			int t=q.front();
//			q.pop();
//			if(top>t)
//			{
//				q.push(t);
//			}
//			else 
//			{
//				q.push(top);
//				top=t;
//			}
//		}
//		cout<<top<<' ';
//		while(q.size())
//		{
//			cout<<q.front()<<' ';
//			q.pop();
//		}
//		cout<<endl;
//	}
//	return 0;
//}



//#define _CRT_SECURE_NO_WARNINGS
////试题D:卡牌合并
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//#include<string>
//#include<cmath>
//#include<queue>
//#include<vector>
//using namespace std;
//int main()
//{
//	int T; cin >> T;
//	while (T--)
//	{
//		int n; cin >> n;
//		queue<pair<int, int>>a;
//		a.push({ 1,n });
//		int size = 1;
//		while (1)
//		{
//			if (a.front().second <= 1)break;
//			int x = a.front().first, y = a.front().second;
//			if (y >= 2)
//				a.push({ 2 * x,y / 2 });
//			if (y % 2)
//			{
//				size++;
//				a.pop();
//			}
//			else
//				a.pop();
//
//		}
//		if (size== 1)cout << "Fang" << endl;
//		else cout << "Ben" << endl;
//
//	}
//
//	return 0;
//}



//#define _CRT_SECURE_NO_WARNINGS
////试题C:数字滚轮
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//#include<string>
//#include<cmath>
//#include<vector>
//using namespace std;
//const int N = 2e5 + 10;
//int a[N];
//int main()
//{
//	int T; cin >> T;
//	while (T--)
//	{
//		int n, q; cin >> n >> q;
//		for (int i = 1; i <= n; i++)
//		{
//			char x; cin >> x;
//			a[i] = x - '0';
//		}
//		string s; cin >> s;
//		int j = 1;
//		for (int i = 0; i < q; i++)
//		{
//			switch (s[i])
//			{
//			case 'L':
//				if (j > 1)
//					j--;
//				break;
//
//			case 'R':
//				if (j < n)
//					j++;
//				break;
//			case 'U':
//				a[j] = (++a[j]) % 10;
//				break;
//			default:
//				a[j] = ((--a[j]) % 10 + 10) % 10;
//				break;
//			}
//
//		}
//		for (int i = 1; i <= n; i++)
//		{
//			cout << a[i];
//		}
//		puts("");
//	}
//
//	return 0;
//}

