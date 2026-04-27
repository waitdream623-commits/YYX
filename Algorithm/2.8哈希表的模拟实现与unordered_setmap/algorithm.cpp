//P3405 [USACO16DEC] Cities and States S
//只需要存储前两个字母
#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

unordered_map<string,int>mp;
int main()
{
	int n;cin>>n;
		int ret=0;
	while(n--)
	{
		string s1,s2;
		cin>>s1>>s2;
		s1.resize(2);
		if(s1==s2)continue;//处理同一个州 
		ret+=mp[s2+s1];//不会重复统计，有就加， 
		mp[s1+s2]++;
	}


	cout<<ret<<endl; 

 } 


////P1102 A-B 数对
//
//#include<iostream>
//#include<unordered_map>
//
//using namespace std;
//const int N=2*1e5+10;
//int a[N];
//unordered_map<int,int>mp;//第一个存数，第二个存出现次数 
//int main()
//{
//	int n,c;cin>>n>>c;
//	for(int i=1;i<=n;i++)
//	{
//		int x;cin>>a[i];
//		mp[a[i]]++;
//	 } 
//	 long long ret=0;//必须为longlong
//	 for(int i=1;i<=n;i++)
//	 {
//	 	ret+=mp[c+a[i]];//与之前相比，不需要遍历重复数 
//	 }
//	 cout<<ret;
//	return 0;
// } 
//////超时 
//#include<iostream>
//#include<unordered_set>
//
//using namespace std;
//unordered_multiset<int>mp;//方便后续查找，并且可以存储相同元素 
//int main()
//{
//	int n,c;
//	cin>>n>>c;
//	
//	while(n--)
//	{
//		int x;
//		scanf("%d",&x);
//		mp.insert(x);
//	}
//	int match=0;
//	for(auto e:mp)
//	{
//		match+=mp.count(e+c);
//	}
//	cout<<match;
//	return 0;
//}


////P3879 [TJOI2010] 阅读理解
////使用<string,vector<int>>存储
//#include<iostream>
//#include<unordered_map>
//#include<vector>
//#include<string> 
//using namespace std;
//
//unordered_map<string,vector<int>>mp; 
//
//int main()
//{
//	ios::sync_with_stdio(false);
//    cin.tie(0);
//	int q;cin>>q;
//	
//	for(int i=1;i<=q;i++)
//	{
//		int n;cin>>n;
//		string s;
//		while(n--)
//		{
//			cin>>s;
//			//可能插入多个1，2，3.....
//			if(mp[s].size()) //判断是否为空 
//			{
//				if(mp[s].back()!=i)//第一次操作位空vector未定义行为 
//			mp[s].push_back(i);
//			}
//			else
//			mp[s].push_back(i);
//// // 简化插入逻辑
////             if(mp[s].empty() || mp[s].back() != i)
////                 mp[s].push_back(i);	
//        }
//	}
//	//输出
//	int m;cin>>m;
//	while(m--)
//	{
//		string qus;
//		cin>>qus;
//		if(mp.count(qus))
//		{
//			cout<<mp[qus].front();//先输出第一个 
//			for(auto e=mp[qus].begin()+1;e!=mp[qus].end();e++)
//			{
//				cout<<' '<<*e;
//			}
//			cout<<endl;
//		}
//		else
//		cout<<endl;//没有输出空行 
//        //puts("");//格式报错
//	 } 
//	 return 0;
//}
////P4305 [JLOI2011] 不重复数字
//#include<iostream>
//#include<unordered_set>//使用哈希表，无序
//using namespace std;
//unordered_set<int>mp;
//
//int main()
//{
//	int q;cin>>q;
//	while(q--)
//	{
//		unordered_set<int>mp;
//		int n;cin>>n;
//		for(int i=0;i<n;i++)
//		{
//			int x;
//			scanf("%d",&x) ;
//			//cin>>x;
//			if(mp.count(x)==0)printf("%d ",x);//cout<<x<<' ';
//			mp.insert(x);
//		}
////		for(auto e:mp)
////		{
////			cout<<e<<' ';
////		}
//		//输出
//		 puts("");//输出字符串后自动换行 
//		 
//	}
//	
//	return 0;
// } 
// 



////P5266 【深基17.例6】学籍管理
//
//#include<iostream>
//#include<unordered_map>
//
//using namespace std;
//
//unordered_map<string,int>mp;
//
//int main()
//{
//	int q;cin>>q;
//	while(q--)
//	{
//		int op;cin>>op;
//		string name;
//		switch(op)
//		{
//			case 1:
//				cin>>name;
//				int score;cin>>score;
//				if(mp.count(name))mp[name]=score;
//				else mp.insert({name,score});
//				cout<<"OK"<<endl;
//				break;
//			case 2:
//				cin>>name;
//				if(mp.count(name))cout<<mp[name]<<endl;
//				else cout<<"Not found"<<endl;
//				break;
//			case 3:
//				cin>>name;
//				if(mp.count(name))
//				{
//					mp.erase(name);
//				 cout<<"Deleted successfully"<<endl;
//				}
//				else cout<<"Not found"<<endl;
//				break;
//				
//			case 4:
//				cout<<mp.size()<<endl;
//				break;
//		}
//	}
//	return 0;
// } 
