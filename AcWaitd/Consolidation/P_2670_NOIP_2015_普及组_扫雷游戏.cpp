#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
char a[110][110];
int n,m;
int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={1,0,-1,1,-1,1,0,-1};
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      cin>>a[i][j];
      
    }
  }
  
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      if(a[i][j]=='*')
      {
        cout<<"*";
        continue;

      }
      int cnt=0;
      for(int k=0;k<8;k++)
      {
        int x=i+dx[k],y=j+dy[k];
        if(a[x][y]=='*')
        cnt++;
      }
      cout<<cnt;
    }
    cout<<'\n';
  }
  return 0;
}
