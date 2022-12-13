// continue로 일부 조건 skip

#include <stdio.h>

void main()
{
    int sum = 0;
    int i;

    for (i = 1; i <= 100; i++)
    {
        if (i % 3 == 0)
            continue;

        sum += i;
    }

    printf("1~100까지의 합(3의 배수 제외): %d\n", sum);
}