//默认大根堆
#include<iostream>
#include<algorithm>
using namespace std; 
const int N=1e6+10;

int n;
int heap[N];

//向上调整法，用于放置新节点 
void up(int child)//传入顺序存储下标
{
	int father=child/2;
	while(father>=1&&heap[father]<heap[child])
	{
		swap(heap[father],heap[child]);
		//孩子继续往上走
		child=father;
		father=child/2; 
	 } 
 } 
//向下调整法，用于删除根节点 
void down(int father)
{
	int child=father*2;
	//左孩子存在，否则为叶节点
	 
	

	while(child<=n&&heap[child]>heap[father])
	{
		//判断左右孩子谁大，先默认左孩子大，否则左加加序号变成右孩子序号
		if(child+1<=n&&heap[child+1]>heap[child])child++;
		swap(heap[child],heap[father]);
		//继续向下走
		father=child;
		child=father*2; 
	 } 
 } 
//插入
void push(int x)//传入的是数据
{
	heap[++n]=x;//heap[n+1]存放x，后加加n //存放的第一个位置为1 
	up(n);//将x放在合法位置 
 } 
//删除堆顶元素
void pop()
{
	swap(heap[1],heap[n]);
	n--;//删除交换之后的堆顶元素 
	down(1); 
 } 
//返回堆顶元素
int top()
{
	return heap[1];//注意合法性 
 } 
//返回大小
int size()
{
	return n;
 } 
 int main()
 {
 	int a[]={1,55,4,3,77,54,23,58,21,57};
 	for(int i=0;i<10;i++)
 	{
 		push(a[i]);
	 }
	 while(size())
	 {
	 	cout<<top()<<' ';
	 	pop();
	 }
 	return 0;
  } 
