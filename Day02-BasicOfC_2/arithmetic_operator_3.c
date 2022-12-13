// 전위, 후위 연산

#include <stdio.h>

int main()
{
    int num1 = 2;
    int num2;
    int num3;
    int num4 = 2, num5 = 2;

    num2 = num1++;
    num3 = ++num1;

    printf("%d %d %d\n", num1, num2, num3);
    printf("%d %d\n", num4++, ++num5);
    printf("%d %d\n", num4, num5);
    return 0;
}