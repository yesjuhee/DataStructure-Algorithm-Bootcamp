// 비트 연산

#include <stdio.h>

int main()
{
    char a = 10;                     // 0000 1010
    printf("a << 1 = %d\n", a << 1); // 0001 0100 (==20)
    printf("a << 2 = %d\n", a << 2); // 0010 1000 (==40)
    printf("a >> 1 = %d\n", a >> 1); // 0000 0101 (==5)
    printf("a >> 2 = %d\n", a >> 2); // 0000 0010 (==2)

    return 0;
}