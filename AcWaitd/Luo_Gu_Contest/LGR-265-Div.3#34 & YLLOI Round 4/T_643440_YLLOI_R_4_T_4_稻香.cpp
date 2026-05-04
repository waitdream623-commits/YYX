#include <iostream>
#include <utility>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
const int N = 1e5 + 10;
int l[N],r[N];
void dfs1(int root,int& k)
{
  if(root==0)return;
  cout<<root<<' ';
  if(l[root]>r[root]&&k>0)
  {
    //不能直接交换，否则子树也会交换，
    k--;
    dfs1(r[root],k);
    dfs1(l[root],k);
  }
  else
  {
    dfs1(l[root],k);
    dfs1(r[root],k);
  }
 
}
void dfs2(int root,int& k)
{
  if(root==0)return;
  if(l[root]>r[root]&&k>0)
  {
    //不能直接交换，否则子树也会交换，
    k--;
    dfs1(r[root],k);
    cout<<root<<' ';

    dfs1(l[root],k);
  }
  else
  {
    dfs1(l[root],k);
    cout<<root<<' ';

    dfs1(r[root],k);
  }
 
}void dfs3(int root,int& k)
{
  if(root==0)return;
  cout<<root<<' ';
  if(l[root]>r[root]&&k>0)
  {
    //不能直接交换，否则子树也会交换，
    k--;
  dfs1(r[root],k);
  cout<<root<<' ';

  dfs1(l[root],k);
  }
  else
  {
    dfs1(l[root],k);
  cout<<root<<' ';

   dfs1(r[root],k);
  }
 
}
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  char op;cin>>op;
  int n,root,k;cin>>n>>root>>k;
  for(int i=1;i<=n;i++)
  {
      cin>>l[i]>>r[i];
  }
  //前序遍历
  int j=1;
  if(op=='A')
  dfs1(root,k);
  else if(op=='B')
  dfs2(root,k);
  else
  dfs3(root,k);


  return 0;
}
