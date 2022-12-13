// 삼항 연산자 예시

#include <stdio.h>

int main()
{
    int a = 200, b = 100, max = 0;

    if (a >= b)
    {
        max = a;
    }
    else
    {
        max = b;
    }
    printf("max = %d\n", max);

    max = 0;
    max = a > b ? a : b;
    printf("max = %d\n", max);

    return 0;
}