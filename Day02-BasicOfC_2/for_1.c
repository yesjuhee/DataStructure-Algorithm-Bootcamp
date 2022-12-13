// 1부터 n까지 더한 합을 구하기

#include <stdio.h>

int main()
{
    int sum = 0;
    int i;
    int num;

    printf("값 입력 : ");
    scanf("%d", &num);

    for (i = 1; i <= num; i++)
    {
        sum = sum + i;
    }

    printf("1에서 %d까지의 합 : %d\n", num, sum);

    return 0;
}