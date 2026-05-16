#include <iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
int a[11];
int ch=30;
int m;
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  for(int i=1;i<=10;i++)
  cin>>a[i];
  sort(a+1,a+11);
  cin>>m;
  int ret=upper_bound(a+1,a+1+10,m+ch)-a-1;
  cout<<ret;
  return 0;
}
