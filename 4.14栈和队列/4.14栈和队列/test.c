#define _CRT_SECURE_NO_WARNINGS
//6 算术表达式求值（栈）
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//运算符数组和运算符优先关系：
char op[7] = { '+', '-', '*', '/', '(', ')', '#' };
char cmp[7][7] = { {'>', '>', '<', '<', '<', '>', '>'},
    {'>', '>', '<', '<', '<', '>', '>'}, {'>', '>', '>', '>', '<', '>', '>'},
    {'>', '>', '>', '>', '<', '>', '>'}, {'<', '<', '<', '<', '<', '=', '-'},
    {'>', '>', '>', '>', '-', '>', '>'}, {'<', '<', '<', '<', '<', '-', '='}
};
//定义栈：运算符栈是字符型，操作数栈是整型。
#define MAXSIZE 100

typedef struct//运算符栈

{
    char data[MAXSIZE];

    int top;
} StackR;

typedef struct//操作数栈
{
    int data[MAXSIZE];

    int top;
} StackD;
//栈的初始化
void InitStackR(StackR* S);//运算符栈
void InitStackD(StackD* S);//操作数栈
//进栈
void PushR(StackR* S, char e);//运算符栈
void PushD(StackD* S, int e);//操作数栈
//出栈
void PopR(StackR* S, char* e);//运算符栈
void PopD(StackD* S, int* e);//操作数栈
//取栈顶元素
char GetTopR(StackR S);//运算符栈
int GetTopD(StackD S);//操作数栈
void InitStackR(StackR* S)
{
    S->top = 0;
    return;
}
void InitStackD(StackD* S)
{
    S->top = 0;
    return;
}
void PushR(StackR* S, char e)
{
    S->top++;
    S->data[S->top] = e;
}
void PushD(StackD* S, int e)
{
    S->top++;
    S->data[S->top] = e;
}
void PopR(StackR* S, char* e)
{
    *e = S->data[S->top];
    S->top--;
}
void PopD(StackD* S, int* e)//传过来的是e的地址，仅可以改变e存的值，改变地址需要变为int**e
{
    *e = S->data[S->top];
    S->top--;
}
char GetTopR(StackR S)//非指针用.访问
{
    return S.data[S.top];
}
int GetTopD(StackD S)
{
    return S.data[S.top];
}
//如果ch是运算符，返回它在运算符数组中的位置，否则返回-1
int IsOperator(char ch)
{
    for (int i = 0; i < 7; i++)
    {
        if (ch == op[i])
            return i;
    }
    return -1;
}
//如果两个字符都是运算符，返回它们的优先关系，否则返回'-'
char Compare(char theta1, char theta2)
{
    int m, n;
    m = IsOperator(theta1);
    n = IsOperator(theta2);
    if (m != -1 && n != -1) return cmp[m][n];
    return '-';
}
//返回 a θ b 的运算结果
int Execute(int a, char theta, int b)
{
    int result;
    switch (theta)
    {
    case '+':
        result = a + b;
        break;
    case '-':
        result = a - b;
        break;
    case '*':
        result = a * b;
        break;
    case '/':
        result = a / b;
        break;
    }
    return result;
}
//s 是字符串，pos 是数字字符的起始位置
int StrTopNum(char* s, int* pos)
{
    int x = 0;
    while (s[*pos] != '\0' && s[*pos] >= '0' && s[*pos] <= '9')
    {
        x = x * 10 + s[*pos] - '0';
        (*pos)++;
    }
    return x;
}
int EvaluateEsp(char* s)
{
    StackR OPTR;//运算符栈
    StackD OPND;//操作数栈
    InitStackR(&OPTR);
    InitStackD(&OPND);
    PushR(&OPTR, '#');//表达式起始符进栈
    int a, b;//操作数
    char theta1, theta2, theta;//运算符
    int k = 0;
    char ch = s[0];//从表达式中取一个字符
    while (ch != '#' || GetTopR(OPTR) != '#')
    {
        if (ch >= '0' && ch <= '9')
            PushD(&OPND, StrTopNum(s, &k));
        else
        {
            theta1 = GetTopR(OPTR);
            theta2 = ch;
            switch (Compare(theta1, theta2))
            {
            case '<':
                PushR(&OPTR, theta2);
                k++;
                break;

            case '=':
                PopR(&OPTR, &ch);
                k++;
                break;
            case '>':
                PopR(&OPTR, &theta);
                PopD(&OPND, &b);
                PopD(&OPND, &a);
                PushD(&OPND, Execute(a, theta, b));
                break;
            }
        }
        ch = s[k];
    }
    return GetTopD(OPND);
}
int main()
{
    char s[100];
    gets(s);//输入表达式串，以#结束
    printf("%d\n", EvaluateEsp(s));//输出表达式的计算结果
    return 0;
}
//2*(35-10)+5#
//55
