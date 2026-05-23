#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
#define int long long
const int N = 1e6 + 10;
int exgcd(int a,int b,int&x,int&y)
{
  if(b==0)
  {
    x=1,y=0;
    return a;
  }
  int x1,y1;
  int d=exgcd(b,a%b,x1,y1);
  x=y1,y=x1-a/b*y1;
  return d;
}
signed main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;cin>>t;
  while (t--)
  {
    int a,b;
    cin>>a>>b;
    int x,y;

    int d=exgcd(a,b,x,y);
    //对x取最小正整数
    int dx=b/d;
    x=((x%dx)+dx)%dx;
    if(d==1)cout<<x<<endl;
    else
    cout<<-1<<endl;
  }
  
}
