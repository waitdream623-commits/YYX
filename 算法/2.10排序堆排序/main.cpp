#include<iostream>

using namespace std;
const int N=1e5+10;
int heap[N];
int n;
//
void down(int parent,int len)//堆长度会变化，已经执行一次排序，最后一个已经为最大 
{
	int child=parent*2;
	while(child<=len)//没有左孩子肯定没有右孩子 
	{
		if(child+1<=len&&heap[child+1]>heap[child]) child++;//找到最大孩子 
		if(heap[parent]>=heap[child])return;
		swap(heap[parent],heap[child]);
		parent=child;
		child*=2;
	}
}
void heap_sort()
{
	//建堆
	for(int i=n/2;i>=1;i--)//从第一个未叶根节点向上，向下调整 
	{
		down(i,n);
	 } 
	//排序
	for(int i=n;i>=1;i--)//依次枚举，将最后一个与第一个交换，将其放在最后即最大位置
	{
		swap(heap[1],heap[i]);
		down(1,i-1) ;//最后一个已经为大 
	 } 
 } 
int main()
{
	cin>>n;;
	for(int i=1;i<=n;i++)
	{
		cin>>heap[i];
	}
	heap_sort();
	for(int i=1;i<=n;i++)
	{
		cout<<heap[i]<<' ';
	}
 } 
