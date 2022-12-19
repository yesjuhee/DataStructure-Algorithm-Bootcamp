// 백준 8958번
// ox 퀴즈

#include <stdio.h>
#include <string.h>

int main(void)
{
    int n = 0;
    char ox_string[81] = {0};

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%s", ox_string);

        int count = strlen(ox_string);
        int sum = 0;
        int consecutive_num = 0;

        for (int j = 0; j < count; j++)
        {
            if (ox_string[j] == 'O')
            {
                consecutive_num += 1;
                sum += consecutive_num;
            }
            else
            { // ox_string[j] == 'X'
                consecutive_num = 0;
            }
        }

        printf("%d\n", sum);
    }

    return 0;
}

/*
 // 강사님 풀이

#include <stdio.h>
#include <string.h>

int main(void)
{
    int i, j, n, score, sum;
    char str[80];

    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        sum = 0;
        score = 1;
        scanf("%s", str);

        for(j = 0; str[j]; j++)
        {
            if(str[j] == 'O')
            {
                sum += score++;
            }
            else
            {
                score = 1;
            }
        }
        printf("%d\n", sum);
    }
}

 */