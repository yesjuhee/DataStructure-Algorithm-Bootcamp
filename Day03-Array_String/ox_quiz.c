// 백준 8958번
// ox 퀴즈

#include <stdio.h>

int main(void)
{
    int n = 0;
    char ox_string[81] = {0};

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%s", ox_string);

        int count = sizeof(ox_string) / sizeof(char);
        int sum = 0;
        int consecutive_num = 0;

        for (int j = 0; j < count; j++)
        {
            if (ox_string[j] == 'O')
            {
                consecutive_num += 1;
                sum += consecutive_num;
                // printf("j:%d, consec: %d, sum: %d\n", j, consecutive_num, sum);
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