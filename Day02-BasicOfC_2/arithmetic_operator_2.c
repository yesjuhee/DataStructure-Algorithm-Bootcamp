// 연산자 우선순위 및 형번환

#include <stdio.h>

int main()
{
    int a = 2, b = 3, c = 4;
    int result1, quotient, division;
    float result2;

    result1 = a + b - c;
    printf("%d + %d - %d = %d\n", a, b, c, result1);

    result1 = a + b * c;
    printf("%d + %d * %d = %d\n", a, b, c, result1);

    result2 = a * b / (float)c;
    printf("%d * %d / %d = %f\n", a, b, c, result2);

    quotient = c / b;
    printf("%d / %d 의 몫은 %d \n", c, b, quotient);

    division = c % b;
    printf("%d / %d의 나머지는 %d \n", c, b, division);

    return 0;
}