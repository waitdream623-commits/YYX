## 分解质因数

### 对于阶乘分解质因数
- 对于每个数单独分解
- ![alt text](image-4.png)
- 对于每一个质数，找有多少个包含这个数
![alt text](image.png)
![alt text](7e533c8e2a3b02f802672752a829d3e1.png)
假如n=10
10/2=5；去掉第一个2，10/4，去掉第二个2；
4=2*2需要筛两遍，10/2筛掉第一个2，10/4筛掉第二个2

## 约数个数与约数之和
![alt text](image-2.png)
![alt text](image-3.png)
### 注意
- 约数总是成对存在，d|n,同时n/d|n，如果d与d/n不同即为两个  约数之和优化
- ⼀个整数 n 的约数个数的上限为 2$\sqrt{n}$
- 试除法
  - 复杂度O($\sqrt{n}$) 
  - 单独求一个数约数
- 倍数法
![](image-1.png)

## 求解约数个数和
![alt text](image-5.png)

## 欧拉函数
- 试除法求解一个
~~~cpp
  ll getphi(int x)
{
  ll ret=x;
  for(int i=2;i<=x;i++)
  {
    if(x%i==0)
    {
      ret=ret/i*(i-1);
      while (x%i==0)
      {
        x/=i;
      }
      
    }
  }
  if(x>1)ret=ret/x*(x-1);
  return ret;
}
~~~
- 求解1~n
~~~cpp
void getphi()
{
  phi[1]=1;
  for(int i=2;i<=n;i++)
  {
    if(!st[i])
    {
        phi[i]=i-1;
        p[++cnt]=i;
    }
    for(int j=1;1ll*i*p[j]<=n;j++)
    {
      int x=i*p[j];
      st[x]=true;
      if(i%p[j]==0)
      {
        phi[x]=p[j]*phi[i];
        break;

      }
      else
      {
        phi[x]=phi[p[j]]*phi[i];
      }
    }
  }
}
~~~
## 求逆元
- 快速幂p11465，序列求和

## 欧拉定理与扩展
- 欧拉降幂与秦九韶算法p5091与p4139