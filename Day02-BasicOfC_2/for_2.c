// 중첩 for문

#include <stdio.h>

int main()
{
    int i, k;

    for (i = 0; i < 3; i++)
    {
        for (k = 0; k < 2; k++)
        {
            printf("중첩 for문입니다. (i값: %d, k값: %d)\n", i, k);
        }
    }

    return 0;
}