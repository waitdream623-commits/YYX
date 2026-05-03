//前缀哈希思想求，对每个区间任意字符串返回哈希
#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e6 + 10;
ull h[N];
ull p[N];//次方求解区间时快速返回p^i次方
string s;
int P=1331;
void init_hash()
{
  p[0]=1;
  for(int i=1;i<=s.size();i++)
  {
    h[i]=h[i-1]*P+s[i-1];
    p[i]=p[i-1]*P;
  }

}
ull gethash(int l,int r)
{
  return h[r]-h[l-1]*p[r-l+1];
}
void issame(int l1,int r1,int l2,int r2)
{
  if(gethash(l1,r1)==gethash(l2,r2))
  cout<<"Yes"<<endl;
  else
  cout<<"No"<<endl;
}
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>s;
  init_hash();
  int m;cin>>m;
  while(m--)
  {
    int l1,r1,l2,r2;cin>>l1>>r1>>l2>>r2;
    issame(l1,r1,l2,r2);
  }
  return 0;
}
