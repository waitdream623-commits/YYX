#include <deque>
#include <iostream>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
int a[N];
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,k;cin>>n>>k;
  for(int i=1;i<=n;i++)cin>>a[i];
  deque<int>q;
  //找区间最小值，单调递增队列
   for(int i=1;i<=n;i++)
  {
    while(q.size()&&a[q.back()]>=a[i])q.pop_back();
    q.push_back(i);
    //判断是否满足窗口长度,多余说明头出去

    if(q.back()-q.front()+1>k)q.pop_front();
    //找到第一个区间
    if(i>=k)
    cout<<a[q.front()]<<' ';
  }
  cout<<endl;
  q.clear();
  //找区间最大值，单调递减队列,存下标
  
  for(int i=1;i<=n;i++)
  {
    while(q.size()&&a[q.back()]<=a[i])q.pop_back();
    q.push_back(i);
    //判断是否满足窗口长度,多余说明头出去

    if(q.back()-q.front()+1>k)q.pop_front();
    if(i>=k)
    cout<<a[q.front()]<<' ';
  }
  
  return 0;
}
