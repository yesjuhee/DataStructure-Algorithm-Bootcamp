// and, or, not 연산자

#include <stdio.h>

int main()
{
    int a = 99;

    printf("AND 연산 : %d \n", (a >= 100) && (a <= 200));
    printf("OR 연산 : %d \n", (a >= 100) || (a <= 200));
    printf("NOT 연산 : %d \n", !(a == 100));

    return 0;
}