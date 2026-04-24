#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//int main()
//{
//    int a, b;
//        printf("输入两个整数相除：\n");
//    scanf("%d",&a);
//    scanf("%d",&b);
//        printf("结果是:商%d余%d\n", a / b, a % b);
//
//    return 0;
//}
//#include<stdio.h>
//int main()
//{
//    int iq;
//    scanf("%d", &iq);
//    printf("Genius");
//
//
//    return 0;
//比较大小
//#include <stdio.h>
//int main()
//{
//    int a, b;
//    scanf("%d,%d",&a,&b);
//    if (a == b) {
//        printf("%d=%d",a,b);
//    }
//    if (a > b) {
//        printf("%d>%d",a,b);
//    }
//    if (a < b) {
//        printf("%d<%d",a,b);
//    
//    return 0;
// }
//#include <stdio.h>
//int main()
//{
//    int a, b;
//    while (scanf("%d %d", &a, &b)!= EOF) // 改为空格分隔
//    {
//    if (a == b) {
//        printf("%d=%d\n",a,b);
//    }
//    if (a > b) {
//        printf("%d>%d\n",a,b);
//    }
//    if (a < b) {
//        printf("%d<%d\n",a,b);
//    }
//    }
//    return 0;
//}
//验证是否整除5 是输出YES，否则输出NO。
#include<stdio.h>
int main()
{
    int a;
    scanf("%d", &a);
    if (a % 5 == 0) {
        printf("YES");
    }
    else {
        printf("NO");
    }



    return 0;
}
