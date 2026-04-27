//T745284 选课
#include<iostream>
#include<vector>
using namespace std;
vector<int>v[1100];
int st[1100][2];//课程是否被选，是否通过 
int a[1100][300];
int main()
{
	int n,T;cin>>n>>T;
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
		for(int j=1;j<=x;j++)
		{
			int t;cin>>t,v[i].push_back(t);
		}
	}
	for(int k=1;k<=T;k++)
	{
		int x;cin>>x;
		int flag=0;
		for(int i=1;i<=x;i++)
		{
			
			int r;cin>>r;a[k][i]=r;//保存科目后续存分数 
			if(v[r].size()==0)
			{
				st[r][0]=1;
			}
			for(auto e:v[r])
			{
				if(st[e][0]&&st[e][1])continue;
				else 
				{
					if(flag==0)
				{
					cout<<"Error";
					flag=1;
				}
				}
			}
		}
        int tmp[310];
        //判断读入成绩是否合法
        for(int i=1;i<=x;i++)
        {
            int t;cin>>t;tmp[a[k][i]]=t;
            //所选科目必须是未选或者挂科
            if(flag==0&&st[a[k][i]][1]>=60)
            {
                cout<<"Error";
                flag=1;
            }
            
        }
		for(int i=1;i<=x;i++)
		{ 
            
            
			if(flag==0)
			{
				if(tmp[a[k][i]]>=60)cout<<'P',st[a[k][i]][1]=tmp[a[k][i]];
			else cout<<'F',st[a[k][i]][1]=0;//表示未通过
			}
			
		}
		cout<<endl;
	}
	return 0;
}


////T745283 英语作文
//#include<iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//	string s;cin>>s;
//	if(s[0]>='a'&&s[0]<='z')s[0]=s[0]-32;
//	int n=s.size();
//	for(int i=1;i<s.size();i++)
//	{
//		if(s[i]>='A'&&s[i]<='Z'&&s[i-1]!='.')//去掉第一位 
//		s.insert(i,"."),i++;
//		if(s[i]=='.')
//		if(s[i+1]>='a'&&s[i+1]<='z')s[i+1]=s[i+1]-32;
//	}
//	if(s[s.size()-1]!='.')s+='.';
//	cout<<s;
//	return 0;
//}
////T745282 网格图
//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	int n,m;cin>>n>>m;
//	for(int i=1;i<=2*n+1;i++)
//	{
//		for(int j=1;j<=2*m+1;j++)
//		{
//			if(i%2==1&&j%2==1)cout<<'+';
//			else if(i%2==1&&j%2==0)cout<<'-';
//			else if(i%2==0&&j%2==1)cout<<'|';
//			else cout<<' ';
//		}
//		cout<<endl;
//	 } 
//	
//	return 0;
//}

////T745281 课堂点名
//#include<iostream>
//
//using namespace std;
//int a[1100][1100];
//int main()
//{
//	int n,m,x,y;cin>>n>>m>>x>>y;
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		cin>>a[i][j];
//	}
//	int cnt=0;
//	for(int i=n;i>x;i--)
//	{
//		for(int j=1;j<=m;j++)
//		if(a[i][j]==1)
//		cnt++;
//	}
//	cout<<cnt+1<<' ';
//	for(int j=1;j<=m;j++)
//	{
//		if(a[x][j]==1)
//		cnt++;
//	}
//	cout<<cnt;
//	return 0;
//}


////T745280 学习小组
//#include<iostream>
//
//using namespace std;
//const int N=2*1e5+10;
//int a[N],b[N],c[N];
//int flag[N];
//int main()
//{
//	int n;cin>>n;
//	for(int i=1;i<=2*n;i++)
//	{
//		int x;cin>>x;
//		c[i]=x; 
//		if(a[x])
//		{
//			b[x]=i ;
//		}
//		else
//		a[x]=i;
//	}
//	for(int i=1;i<=2*n;i++)
//	{
//		if(flag[c[i]]==0)
//		cout<<b[c[i]]<<' ',flag[c[i]]=1;
//		else
//		cout<<a[c[i]]<<' ';
//	}
//	return 0;
//}

////T745279 果园
//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	int n,k;cin>>n>>k;
//	int x;int ret=0;
//	int flag=1;
//	for(int i=1;i<=n;i++)
//	{
//		cin>>x;
//		if(i<=k)
//		{
//			ret=max(ret,x);
//		 } 
//		 else if(flag&&x>ret)
//		 {
//		 	ret=x;
//		 	flag=0;
//		 }
//		 if(i==n&&flag)
//		 ret=x;
//	}
//	cout<<ret;
//	return 0;
//}

////T745278 优惠票
//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	int a,b;
//	cin>>a>>b;
//	if(a<4&&b)cout<<"Yes";
//	else cout<<"No"; 
//	
//	return 0;
//}

///T745277 校园跑
//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	int n,a,b,c,d;
//	cin>>n>>a>>b>>c>>d;
//	cout<<n-a-b-c-d; 
//	
//	return 0;
//}
