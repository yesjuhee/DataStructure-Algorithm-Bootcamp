// 두 변수의 합을 구하는 함수

#include <stdio.h>

int plus(int v1, int v2)
{
    int result;
    result = v1 + v2;
    return result;
}

void main()
{
    int sum;

    sum = plus(100, 200);

    printf("100과 200의 plu() 함수 결과는 %d\n", sum);
}