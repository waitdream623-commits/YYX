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
  //求最差，即构建单调递增队列，队头即为结果
  deque<int>q;
  for(int i=1;i<=n;i++)
  {
	while(q.size()&&a[q.back()]>=a[i])q.pop_back();
	q.push_back(i);
	if(q.back()-q.front()+1>k)q.pop_front();
	if(i>=k)cout<<a[q.front()]<<endl;

  }
  return 0;
}
