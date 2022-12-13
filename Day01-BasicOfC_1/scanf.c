// scanf로부터 값을 입력받고 출력

#include <stdio.h>

int main(void)
{

    int a, b;
    int result;

    printf("첫 번째 계산할 값을 입력하세요 ==> ");
    scanf("%d", &a);

    printf("두 번째 계산할 값을 입력하세요 ==> ");
    scanf("%d", &b);

    result = a + b;
    printf(" %d + %d = %d \n", a, b, result);

    result = a - b;
    printf(" %d - %d = %d \n", a, b, result);

    result = a * b;
    printf(" %d * %d = %d \n", a, b, result);

    result = a / b;
    printf(" %d / %d = %d \n", a, b, result);

    return 0;
}