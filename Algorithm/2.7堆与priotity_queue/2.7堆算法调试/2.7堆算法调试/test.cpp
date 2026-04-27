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