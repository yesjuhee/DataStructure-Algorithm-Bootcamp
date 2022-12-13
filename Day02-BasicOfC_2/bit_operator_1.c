// &, |, ^ 연산

#include <stdio.h>

int main()
{
    char a = 0x41;                 // 0100 0001 (==65)
    char b = 0x0F;                 // 0000 1111 (==15)
    printf("a & b = %d\n", a & b); // 0000 0001 (==1)
    printf("a | b = %d\n", a | b); // 0100 1111 (==79)
    printf("a ^ b = %d\n", a ^ b); // 0100 1110 (==78)
    printf("a: %d\n", a);
    printf("b: %d\n", b);

    return 0;
}