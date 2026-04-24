#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 100; i++)
//		if (0 == i % 3)
//			printf("%d ", i);
//	return 0;
//}
//选出三个中最大的数（残次品）
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int MAX = 0;
//	scanf("%d %d %d", &a, &b, &c);
//	if (a > b && a > c)
//	{
//		printf("%d", a);
//		MAX = a;
//	}
//	else if (b > c && b > a)
//	{
//		printf("%d", b);
//		MAX = b;
//	}
//	else
//	{
//		printf("%d", c);
//		MAX = c;
//	}
//	return 0;
//}
//int main()
//{
//	int a, b, c,temp;
//	scanf("%d %d %d", &a, &b, &c);
//		if (a < b) {
//			temp = a;
//			a = b;
//			b = temp;
//		}
//		if (a < c) {
//		temp = a;
//		a = c;
//		c = temp;
//		}
//		if (b < c) {
//		temp = b;
//		b = c;
//		c = temp;	
//		}
//		printf("%d %d %d", a, b, c);
//	return 0;
//}
//#include <stdio.h>



int main()
{
    int a, b, c;
    while (scanf("%d %d %d", &a, &b, &c) != EOF)
    {
        if (a + b > c && a + c > b && b + c > a)
        {
            if (a == b && b == c)
                printf("Equilateral triangle!");
            else if (a == b || a == c || b == c)
                printf("Isosceles triangle!\n");
            else
                printf("Ordinary triangle!\n");


        }

        else
            printf("Not a triangle!");
    }
    return 0;
}
}