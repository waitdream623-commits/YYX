//map,trie,字符串哈希
//trie
#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 3e6 + 10;
int tree[N][62],p[N],e[N];
int index;
int c=0;
int get_num(char c)
{
  if(c>='a'&&c<='z')return c-'a';
  if(c>='A'&&c<='Z')return c-'A'+26;
  return c-'0'+52;
}
void pushs(string&s)
{
  int cur=0;//从顶层开始
  p[cur]++;
  for(auto e:s)
  {
    int path=get_num(e);
    if(tree[cur][path]==0)//说明没有存储e这个字符
    {
      tree[cur][path]=++index;//开辟空间
    }
    //往下一层走
    cur=tree[cur][path];
    //经过
    p[cur]++;

  }
  //到达最终
  e[cur]++;
}
//查询相同字符串是否存在
int& find(string&s)
{
  int cur=0;
  for(auto e:s)
  {
    int path = get_num(e);
    if(tree[cur][path]==0)return c;//没找到
    //找到了匹配字符，继续往下
    cur=tree[cur][path];
  }
  //最终,p存储的为通过此路个数，即相同前缀
  return e[cur];
}
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;cin>>n;
  string s;
  for(int i=1;i<=n;i++)
  {
      cin>>s;
      pushs(s);
  }
  //查询
  int m;cin>>m;
  while(m--)
  {
    cin>>s;
    int&a=find(s);
    if(a==0)cout<<"WRONG"<<endl;
    else if(a==1)
    {
      cout<<"OK"<<endl;
      a=-1;//已经点过
    }
    else
    cout<<"REPEAT"<<endl;
  }
  return 0;
}




//map
// #include <iostream>
// #include <unordered_map>
// using namespace std;
// typedef long long ll;
// typedef unsigned long long ull;
// const int N = 1e6 + 10;
// int main() {

//   ios::sync_with_stdio(false);
//   cin.tie(nullptr);
//   int n;cin>>n;
//   unordered_map<string, int>mp;
//   string s;
//   while(n--)
//   {
//       cin>>s;
//       mp[s]++;
//   }
//   int m;cin>>m;
//   while(m--)
//   {
//     cin>>s;
//     if(mp[s]==0)cout<<"WRONG"<<endl;
//     else if(mp[s]==1)
//     {
//       cout<<"OK"<<endl;
//       mp[s]++;
//     }
//     else
//     {
//       cout<<"REPEAT"<<endl;
//     }
//   }
//   return 0;
// }
