//P1379 八数码难题
#include <iostream>
#include <queue>
#include <cstring>
#include <unordered_map>

using namespace std;
string s;
string aim="123804765";
unordered_map<string,int>disc;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int  bfs()
{
	 if (s == aim) return 0; // 初始状态即目标
	queue<string>q;
	q.push(s);
	disc[s]=0;
	while(q.size())
	{
		string t=q.front();q.pop();
		int pos=0;//寻找o位置；
		while(t[pos]!='0')pos++;
		int x=pos/3,y=pos%3;
		for(int k=0;k<4;k++)
		{
			int a=x+dx[k],b=y+dy[k];
			if(a>=0&&a<3&&b>=0&&b<3)
			{
				int p=a*3+b;
				string tmp=t;
				swap(tmp[p],tmp[pos]);
				if(disc.count(tmp))continue;
				disc[tmp]=disc[t]+1;
				q.push(tmp);
				if(tmp==aim)return disc[tmp];
			}
		}
		
	}
}
int main()
{
	cin>>s;
	cout<<bfs();
//	cout<<disc[aim];
	return 0;
}

////P1588 [USACO07OPEN] Catch That Cow S
//
//#include <iostream>
//#include <queue>
//#include <cstring>
//
//using namespace std;
//
//const int N=1e6+10;
//int x,y;
//int disc[N];
//void bfs()
//{
//	queue<int>q;
//	q.push(x);
//	disc[x]=0;
//	while(q.size())
//	{
//		int t=q.front();q.pop();
//		int a=t-1,b=t+1,c=t*2;
//		if(a==y||b==y||c==y)
//		{
//			disc[y]=disc[t]+1;
//			return;
//		}
//		if(a<=N&&disc[a]==-1)
//		{
//			q.push(a);
//			disc[a]=disc[t]+1;
//		}
//		if(b>0&&disc[b]==-1)
//		{
//			q.push(b);
//			disc[b]=disc[t]+1;
//		}
//		if(c<=N*2&&disc[c]==-1)
//		{
//			q.push(c);
//			disc[c]=disc[t]+1;
//		}
//	}
//	
//}
//int main()
//{
//	int t;cin>>t;
//	while(t--)
//	{
//		memset(disc,-1,sizeof disc);
//		cin>>x>>y;
//		bfs();
//		cout<<disc[y];
//		
//	}
//	return 0;
//}
