#include <stdio.h>
#include <string.h>

int main(void)
{
    int t;
    char string[51];

    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        int stack_top = -1;
        int is_right_over = 0;
        // 입력
        scanf("%s", string);

        // 하나씩 체크
        for (int j = 0; j < strlen(string); j++)
        {

            if (string[j] == '(')
            {
                // push
                stack_top++;
                continue;
            }

            // string[j] == ')'
            if (stack_top == -1)
            {
                // 스택이 비었으면
                is_right_over = 1;
                break;
            }
            else
            {
                // 스택에 '('가 있으면 -> full
                stack_top--;
            }
        }

        if (is_right_over == 1)
        {
            printf("NO\n");
            continue;
        }
        else if (stack_top == -1)
        {
            printf("YES\n");
            continue;
        }
        else
        {
            printf("NO\n");
        }
    }

    return 0;
}