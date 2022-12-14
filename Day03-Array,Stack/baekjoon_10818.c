// malloc 실습
// 최소, 최대

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main(void)
{
    int n, i, min, max;
    int *arr;

    // n 입력
    scanf("%d", &n);

    // 동적 할당
    arr = (int *)malloc(sizeof(int) * n);

    // 배열 입력
    for (i = 0; i < n; i++)
    {
        scanf(" %d", &arr[i]);
    }

    min = arr[0];
    max = arr[0];
    // 최대, 최소 조사
    for (i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        else if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    // 출력
    printf("%d %d", min, max);

    return 0;
}