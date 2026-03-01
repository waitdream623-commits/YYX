//小红的路径
#include <iostream>

using namespace std;
int d[4]={1,-1,-1,1};//上下左右 
int main()
{
	
	return 0;
 } 


////小红的异或分组
//#include<iostream>
//using namespace std;
//const int N=1e6+10;
//int a[N];
//int main()
//{
//	
//	int n;cin>>n;
//	int y;
//	for(int i=1;i<=n;i++)
//	{
//		cin>>a[i];
//		y^=a[i];
//	}
//	int l=1,r=n,i=1;
//	int ret=0;
//	y^=a[n];
//	//控制中间数组不为空 
//	int z;
//	z^=a[n];
//		while(r>2)
//		{
//			int x=0;
//			int m=y;
//			for(int j=1;j<r;j++)
//		{
//			x^=a[j];
//			m^=a[j];
//			if(x==m&&m==z)ret++;
//		}
//		r--;
//		z^=a[r];	
//		}
//		cout<<ret;
//}



////小红的数字查找
//#include<iostream>
//#include<cmath>
//using namespace std;
//
//int main()
//{
//    int x,l,r;cin>>x>>l>>r;
//    int ret=-1;
//    for(int i=l;i<=r;i++)
//    {
//        int mu=x*i;
//        int s=sqrt(mu); 
//        if(s*s==mu){
//            ret=i;
//        }
//    }
//    cout<<ret;
//    return 0;
//}
