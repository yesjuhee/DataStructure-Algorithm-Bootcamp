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

/*
// 강사님 리뷰

void printMap(int size, int *arr1, int *arr2)
{
    int i = 0, j = 0, row = 0, element = 0;

    for (i = 0; i < size; i++)
    {
        row = *(arr1 + i) | *(arr2 + i);

        for (j = size - 1; j >= 0; j--)
        {
            element = row >> j & 1; //쉬프트 & 마스킹
            if (element == 1)
                printf("#");
            else
                printf(" ");
        }
        printf("\n");
    }
}

void getArr(int *arr)
{
    int i = 0;
    char str1[1000] = "";
    char *tok;

    scanf("%s", str1);
    rewind(stdin);

    tok = strtok(str1, ",");
    while (tok != NULL)
    {
        *(arr + i++) = atoi(tok);   // atoi : char to integer
            // arr[i] = atoi(tok);
            // i++;
        tok = strtok(NULL, ",");
    }
}

int main(void)
{
    int n;
    int arr1[16] = {0};
    int arr2[16] = {0};

    scanf("%d", &n);
    rewind(stdin);

    getArr(arr1);
    getArr(arr2);

    printMap(n, arr1, arr2);

    return 0;
}
*/