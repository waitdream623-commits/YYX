//P1878 舞蹈课
//1.存储性别2.双链表存储技术分数3.用小根堆存储分数差绝对值 
//标记数组已经配对的（因为存入堆有重复塔子）

#include<iostream>
#include<queue>
#include<vector>
using namespace std;
const int N = 2 * 1e5 + 10;
bool sex[N];
int flag[N];//标记数组已经配对和顺序 
//双链表
int e[N], pre[N], ne[N];
struct node {
	int sc, i, j;//分数，左配，右配

	bool operator<(const node& x)const//指针引用变量用-> 
	{
		//需要处理分数相等
		if (sc != x.sc)return sc > x.sc;
		else if (i != x.i) return i > x.i;
		else return j > x.j;
	}
};
priority_queue<node>heap;
vector<node>ret;//存储配对成功信息
int main()
{
	int n; cin >> n;
	//存入数据
	string s;
	cin >> s;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'B')sex[i + 1] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> e[i];
		ne[i] = i + 1;
		pre[i] = i - 1;
	}
	ne[n] = 0;//处理最后一个
	//第一次入堆
	for (int i = 1; i < n; i++)
	{
		if (sex[i] != sex[i + 1])
		{
			heap.push({ abs(e[i] - e[i + 1]),i,i + 1 });
		}
	}
	//差最小在堆顶，pop并标记顺序，计算队数
	
	while (heap.size())
	{
		auto t = heap.top(); heap.pop();
		if (flag[t.i] == 0 && flag[t.j] == 0)//未曾标记，即可配对 
		{
			flag[t.i] = 1;
			flag[t.j] = 1;
			ret.push_back(t);
			//有效配对 有效pop 
		 //连接剩下成员，并再次进堆
			ne[pre[t.i]] = ne[t.j];
			pre[ne[t.j]] = pre[t.i];
			while (pre[t.i] && ne[t.j] && sex[pre[t.i]] != sex[ne[t.j]])
			{
				heap.push({ abs(e[pre[t.i]] - e[ne[t.j]]),pre[t.i] ,ne[t.j] });
			}
			//效率低：每次配对后都要遍历整个链表，而实际上只有新形成的相邻对可能被加入堆中，
			//原来已经在堆中的对（除了当前被移除的两个人形成的对）仍然在堆中，但有些可能已经不再相邻（因为链表结构改变了）。
			//不过，我们在从堆中取出时已经检查了相邻性，所以原来在堆中的无效对会在取出时被跳过。
			//重复入堆：原来已经在堆中的对（除了当前被移除的两个人形成的对）我们并没有从堆中删除，
			//而再次入堆会导致堆中有重复的节点，增加堆的大小。
			//for (int i = ne[0]; i; i = ne[i])
			//{
			//	if (ne[i] == 0)break;//没有下一个 
			//	if (sex[i] != sex[ne[i]])
			//		heap.push({ abs(e[i] - e[ne[i]]),i,ne[i] });
			//}
		}
	}
	//输出配对编号，后进先出vector
	cout << ret.size() << endl;
	for (auto e : ret)
	{
		cout << e.i << ' ' << e.j << endl;
	}
	return 0;
}


////P1631 序列合并
//#include<iostream>
//#include<queue>
//
//using namespace std;
//const int N=1e5+10; 
//int a[N],b[N];
//struct node{
//	int ap;//a数组中位置
//	int bp;//b数组中位置
//	int s;//所加和 
//	bool operator<(const node&x)const
//	{
//		return s>x.s;//小根堆 
//	 } 
//};
//priority_queue<node>heap;
//int main()
//{
//	int n;cin>>n;
//	//存数 
//	for(int i=1;i<=n;i++)
//	{
//		cin>>a[i];
//	 } 
//	 for(int i=1;i<=n;i++)
//	{
//		cin>>b[i];
//	 } 
//	//将a数组每个加b[1]存入堆
//	for(int i=1;i<=n;i++)
//	{
//		heap.push({i,1,a[i]+b[1]});
//	 } 
//	 //输出
//	 for(int i=1;i<=n;i++)
//	 {
//	 	//将堆顶输出，并将堆顶a[i]加上下一个b入堆 
//	 	auto tmp=heap.top();heap.pop();
//		 int ap=tmp.ap;int bp=tmp.bp+1;int s=a[ap]+b[bp]; 
//	 	cout<<tmp.s<<' ';
//	 	if(bp+1<=n)heap.push({ap,bp,s});//以防b数组越界 
//	  } 
//	return 0;
//}



////P2085 最小函数值
////方式2
////使用小根堆，第1次将x=1时的函数求解放入堆中，当最小数被输出时（输出mci），再次计算对应
////函数的下一个i+1值 ，再次push小根堆，直到输出完成 
//
//#include<iostream>
//#include<queue>
//
//using namespace std;
//struct node{
//	int s,f,num;//函数值，函数编号，函数自变量
//	//使用结构体的堆重载<号
//	bool operator<(const node&k)const
//	{
//		return s>k.s;//小根堆 
//	 } 
//};
//priority_queue<node>heap;
//int a[10010][6];//存储函数系数与常数 
//int main()
//{
//	int n,m;cin>>n>>m;
//	//存入函数 
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=3;j++)
//		{
//			cin>>a[i][j];
//		}
//	 } 
//	//第一次入堆
//	for(int i=1;i<=n;i++)
//	{
//		//自变量==1;
//		int s1=a[i][1]+a[i][2]+a[i][3];
//		heap.push({s1,i,1});
//	 }
//	 //输出m次
//	 while(m--)
//	 {
//	 	auto tmp=heap.top();heap.pop();
//	 	cout<<tmp.s<<' ';
//		 int h=tmp.f;
//		 int x=tmp.num+1;//自变量加一 
//		 //入堆出去的下一个
//		 int s=a[h][1]*x*x+a[h][2]*x+a[h][3];
//		 heap.push({s,h,x}); 
//	  } 
//	return 0;
//}
//
//////超时 m*n最多1e8 
//////使用大根存储，存储m个数，多的最大数pop，最后输出m次
//////因为ABC均为正数，函数必定单增，m个数仅需要每行输出10个
////#include<iostream>
////#include<queue>
////
////using namespace std;
////int n,m;
////priority_queue<int>heap;
////void dfs()
////{
////	int x=heap.top();heap.pop();
////	if(heap.size())dfs();//先将堆顶存起来，找到堆地输出再返回 
////	cout<<x<<' ';
////	
////}
////int main()
////{
////	cin>>n>>m;
////	while(n--)//不能再次使用，如果需要后续使用使用for 
////	{
////		int a,b,c;cin>>a>>b>>c;
////		
////			for(int i=1;i<=m;i++)
////			{
////				heap.push(a*i*i+b*i+c);
////				if(heap.size()>m)heap.pop();
////			}
////		
////	}
////	//输出//大根存储需要先输出最小值 使用dfs 
////	dfs(); 
////	return 0;
////}


////除2！
////大根堆存储（只存储偶数）
////找出最大的偶数，把他pop，除二后加入堆
////如何求和：读入数据时即求和，处理时减去减小的
//#include<iostream>
//#include<queue>
//
//using namespace std;//默认大根存储
//priority_queue<int>heap;
//int main()
//{
//    int n,k;cin>>n>>k;
//    long long sum=0;//可能超数据范围
//    for(int i=0;i<n;i++)
//    {
//        int x;cin>>x;
//        sum+=x;
//        if(x%2==0)heap.push(x);
//    }
//    while(k--&&heap.size())//需要保证堆不为空
//    {
//        int t=heap.top();//为空非法操作
//        t/=2;
//        sum-=t;
//        //如果t不再是偶数不再存入堆 
//        heap.pop();
//        if(t%2==0)heap.push(t);
//        
//    }
//    cout<<sum;
//    return 0;
//}


////第 k 小
//#include<iostream>
//#include<queue>
//
//using namespace std;
//int n,m,k;
//priority_queue<int>heap;//默认大根堆，维护k个数据的堆，堆顶即
//						//第k小 
//
//int main()
//{
//	cin>>n>>m>>k;
//	for(int i=0;i<n;i++)
//	{
//		int x;cin>>x;
//		heap.push(x);
//		if(heap.size()>k)heap.pop();
//	 } 
//	 while(m--)
//	 {
//	 	int op;cin>>op;
//	 	if(op==1)
//	 	{
//	 		int x;
//	 		cin>>x;
//	 		heap.push(x);
//	 		if(heap.size()>k)heap.pop();
//	 		
//		 }
//		 else
//		 {
//		 	if(heap.size()==k)cout<<heap.top()<<endl;
//		 	else cout<<-1<<endl;
//		 }
//	 }
//}
//


////P3378 【模板】堆
//#include<iostream>
//#include<queue>
//
//using namespace std;
////模拟实现
//int n;
//const int N = 1e6 + 10;
//int heap[N];
////小根堆
////向上调整法 用于插入 
//void up(int child)//传入下标
//{
//	int father = child / 2;
//	while (father >= 1 && heap[child] < heap[father])
//	{
//		swap(heap[child], heap[father]);
//		//向上走
//		child = father;
//		father /= 2;
//	}
//}
////向下调整法 用于删除 
//void down(int father)
//{
//	int child = father * 2;
//	while (child <= n)//&&heap[father]>heap[child])可能father小于大的那个孩子//将大的换到根节点，用向下调整使堆合法
//	{
//		//找到最小的child
//		if (child + 1 <= n && heap[child + 1] < heap[child])child++;
//		if (heap[father] < heap[child]) break;
//		swap(heap[child], heap[father]);
//		//向下走
//		father = child;
//		child *= 2;
//	}
//}
////加入
//void push(int x)
//{
//	heap[++n] = x;
//	up(n);
//}
////删除堆顶
//void pop()
//{
//	swap(heap[1], heap[n]);
//
//	n--;//防止向下调整访问到已经删除 
//	down(1);
//
//}
////输出堆顶
//int top()
//{
//	return heap[1];
//}
//int main()
//{
//	int q; cin >> q;//切勿使用重复变量名
//	while (q--)
//	{
//		int op, x;cin >> op;
//		switch (op)
//		{
//		case 1:
//			cin >> x;
//			push(x);
//			break;
//		case 2:
//			cout << top() << endl;
//			break;
//		case 3:
//			pop();
//			break;
//
//		}
//	}
//
//	return 0;
//}
