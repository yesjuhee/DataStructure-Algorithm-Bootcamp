#include <stdio.h>

int main()
{
    int n = 0;
    int arr1[16] = {0};
    int arr2[16] = {0};
    int map_arr[16] = {0};
    // char string_arr[17][17] = '0';
    int i = 0;

    // 입력
    printf("n: ");
    scanf("%d", &n);
    printf("arr1: ");
    for (i = 0; i < n; i++)
    {
        scanf(" %d", &arr1[i]);
    }
    printf("arr2: ");
    for (i = 0; i < n; i++)
    {
        scanf(" %d", &arr2[i]);
    }

    // 지도를 십진수 숫자로 표현
    for (i = 0; i < n; i++)
    {
        map_arr[i] = arr1[i] | arr2[i];
    }

    // 출력
    printf("[ ");
    i = 0;
    do
    {
        int decimal = map_arr[i];
        printf("\"");
        for (int j = n - 1; j >= 0; j--)
        {
            int binary = decimal >> j & 1;
            if (binary)
                printf("#");
            else
                printf(" ");
        }
        printf("\" ");
        i++;

    } while (i < n);
    printf("]");

    return 0;
}