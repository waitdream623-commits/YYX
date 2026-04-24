#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//¥Ú”°Õº∞∏
int main()
{
    int len = 0;
    while (scanf("%d", &len) != EOF)
    {
        for (int i = 0; i < len; i++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}