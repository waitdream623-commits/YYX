#include<iostream>
using namespace std;
const int N=110;
int a[N];
int fa[N];
int road[N];//标记经过位置
//向上访问，找到第一个重复访问节点
void dfs(int father,int&i)
{
    if(a[i]==0)
    {
        i++;
        return;
    }
    
    while(a[i])
        {
        	
            fa[a[i]]=father;
            i++;
            dfs(a[i-1],i);
        }
        //while退出返回需要i++； 
        i++;
    return;
    
}
int main()
{
    int T;cin>>T;
    while(T--)
        {
            int x,y;
            int i=1;
            while(cin>>x>>y&&(x||y))
                {
                    a[i]=x;a[i+1]=y;
                    i+=2;
                }
               // a[i]=0;a[i+1]=0;默认是0
                //少输入一个 说明输入得优化；
                //最后三个0，两个就会跳出
                cin>>x;
        //如何存储
            int j=1;//遍历数组
            dfs(0,j);
            int c,b;
            cin>>c>>b;
            //c向上访问标记经过路径
            while(fa[c])
            {
                road[fa[c]]=1;
                c=fa[c];
            }
            //b向上
            while(fa[b]&&road[fa[b]]==0)
            {
                b=fa[b];
            }
            cout<<fa[b]<<endl;
           
        }

    return 0;
}
